#pragma once

#include "Component.hpp"

struct InPort {
  Component *component;
  double *value;
};

InPort *initInPort(InPort *, Component *);
