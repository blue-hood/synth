#include "Component.hpp"

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
