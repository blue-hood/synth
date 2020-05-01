// Copyright [2020] <Hood>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include "Component.hpp"
#include <cstddef>

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

extern "C" {
EMSCRIPTEN_KEEPALIVE
double simulate() {
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
