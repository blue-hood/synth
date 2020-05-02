#pragma once

#include "InPort.hpp"
#include "OutPort.hpp"

#define COMPONENT_IN_PORTS_LENGTH 16

enum ComponentType { Mixer };

struct Component {
  // TODO: allocate +1 for end of inputs
  InPort inPorts[COMPONENT_IN_PORTS_LENGTH];
  OutPort outPort;
  ComponentType type;
};

Component *initComponent(Component *, ComponentType);
double mixerSynchronizer(InPort[COMPONENT_IN_PORTS_LENGTH]);
Component *syncComponent(Component *);
