#ifndef ARM_GREMLIN_H
#define ARM_GREMLIN_H

#include "hw/arm/virt.h"
#include "hw/core/boards.h"
#include "qemu/typedefs.h"

#define TYPE_GREMLIN_MACHINE MACHINE_TYPE_NAME("gremlin")

OBJECT_DECLARE_TYPE(GremlinMachineState, GremlinMachineClass, GREMLIN_MACHINE)

struct GremlinMachineState {
  VirtMachineState parent_obj;
};

struct GremlinMachineClass {
  VirtMachineClass parent_obj;
  // save VirtMachineClass init
  void (*machvirt_init)(MachineState *);
  void (*i2c_init)(GremlinMachineState *);
};

#endif // !ARM_GREMLIN_H
