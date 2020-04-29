// Copyright [2020] <Hood>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

struct Component;

struct Input {
  double *value;
  Component *component;
};

#define COMPONENT_INPUTS_LENGTH 16

struct Component {
  Input inputs[COMPONENT_INPUTS_LENGTH];
  double output;
};

#include <cstddef>

Component *initComponent(Component *component) {
  int index;

  for (index = 0; index < COMPONENT_INPUTS_LENGTH; index++) {
    component->inputs[index].component = component;
    component->inputs[index].value = nullptr;
  }

  return component;
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
double test() {
  Component component1, component2;

  initComponent(&component1);
  initComponent(&component2);

  component2.inputs[0].value = &component1.output;

  component1.output = 1.5;
  component2.output = *component2.inputs[0].value;

  return component2.output;
}
}
