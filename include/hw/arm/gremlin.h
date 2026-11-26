#ifndef ARM_GREMLIN_H
#define ARM_GREMLIN_H

#include "hw/arm/virt.h"

#define TYPE_GREMLIN_MACHINE MACHINE_TYPE_NAME("gremlin")

OBJECT_DECLARE_TYPE(GremlinMachineState, GremlinMachineClass, GREMLIN_MACHINE)

struct GremlinMachineState {
    VirtMachineState parent_obj;
};

struct GremlinMachineClass {
    VirtMachineClass parent_obj;
    // save VirtMachineClass init
    void (*machvirt_init )(MachineState*);
};

#endif // !ARM_GREMLIN_H


