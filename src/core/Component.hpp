#define COMPONENT_INPUTS_LENGTH 16

enum ComponentType { Mixer };

struct Component {
  // TODO: allocate +1 for end of inputs
  Input inputs[COMPONENT_INPUTS_LENGTH];
  Output output;
  ComponentType type;
};

Component *initComponent(Component *, ComponentType);
double mixerSynchronizer(Input[COMPONENT_INPUTS_LENGTH]);
Component *syncComponent(Component *);
