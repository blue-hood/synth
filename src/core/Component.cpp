#include "Component.hpp"

Component *initComponent(Component *component, ComponentType type) {
  int index;

  component->type = type;

  for (index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    initInput(&component->inPorts[index], component);
  }

  return component;
}

double mixerSynchronizer(InPort inPorts[COMPONENT_IN_PORTS_LENGTH]) {
  InPort **inPort;
  double value = 0.0;

  for (inPort = &inPorts; *inPort != nullptr; inPort++) {
    value += *(*inPort)->value;
  }

  return value;
}

double (*const synchronizer[])(InPort[COMPONENT_IN_PORTS_LENGTH]) = {
    mixerSynchronizer};

// TODO: inline
Component *syncComponent(Component *component) {
  component->outPort.value = synchronizer[component->type](component->inPorts);

  return component;
}
