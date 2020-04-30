// Copyright [2020] <Hood>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include <cstddef>

struct Component;

struct Input {
  Component *component;
  double *value;
};

Input *initInput(Input *input, Component *component) {
  input->component = component;
  input->value = nullptr;

  return input;
}

struct Output {
  Input *input;
  double value;
};

Output *initOutput(Output *output) {
  output->input = nullptr;

  return output;
}

void connectPort(Input *input, Output *output) {
  // TODO: disconnect prev ports
  input->value = &output->value;
  output->input = input;
}

#define COMPONENT_INPUTS_LENGTH 16

enum ComponentType { Mixer };

struct Component {
  // TODO: allocate +1 for end of inputs
  Input inputs[COMPONENT_INPUTS_LENGTH];
  Output output;
  ComponentType type;
};

Component *initComponent(Component *component, ComponentType type) {
  int index;

  component->type = type;

  for (index = 0; index < COMPONENT_INPUTS_LENGTH; index++) {
    initInput(&component->inputs[index], component);
  }

  return component;
}

double mixerSynchronizer(Input inputs[COMPONENT_INPUTS_LENGTH]) {
  Input **input;
  double value = 0.0;

  for (input = &inputs; *input != nullptr; input++) {
    value += *(*input)->value;
  }

  return value;
}

double (*const synchronizer[])(Input[COMPONENT_INPUTS_LENGTH]) = {
    mixerSynchronizer};

// TODO: inline
Component *syncComponent(Component *component) {
  component->output.value = synchronizer[component->type](component->inputs);

  return component;
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
double test() {
  Component component1, component2;
  Output output;

  // Define components
  initComponent(&component1, Mixer);
  initComponent(&component2, Mixer);

  initOutput(&output);

  // Connect components
  connectPort(&component1.inputs[0], &output);

  connectPort(&component2.inputs[0], &component1.output);
  connectPort(&component2.inputs[1], &output);

  // Set input
  output.value = 1.5;

  // Simulate
  syncComponent(output.input->component);
  syncComponent(output.input->component->output.input->component);

  return component2.output.value;
}
}
