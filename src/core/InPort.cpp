#include "InPort.hpp"

InPort *initInPort(InPort *inPort, Component *component) {
  inPort->component = component;
  inPort->value = nullptr;

  return inPort;
}
