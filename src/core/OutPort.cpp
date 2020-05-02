#include "OutPort.hpp"

OutPort *initOutPort(OutPort *outPort) {
  outPort->inPort = nullptr;

  return outPort;
}
