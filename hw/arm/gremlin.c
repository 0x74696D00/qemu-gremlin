#include "qemu/osdep.h"
#include "hw/arm/gremlin.h"
#include "hw/arm/virt.h"
#include "hw/arm/machines-qom.h" 

static const TypeInfo gremlin_types[] = {
    {
        .name = TYPE_GREMLIN_MACHINE,       
        .abstract = true,
        .parent = TYPE_VIRT_MACHINE,
        .instance_size = sizeof(GremlinMachineState),
        .class_size = sizeof(GremlinMachineClass),
        .interfaces = arm_aarch64_machine_interfaces
    }
};

DEFINE_TYPES(gremlin_types)

