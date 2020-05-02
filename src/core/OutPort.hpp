#pragma once

#include "InPort.hpp"

struct OutPort {
  InPort *inPort;
  double value;
};

OutPort *initOutPort(OutPort *);
