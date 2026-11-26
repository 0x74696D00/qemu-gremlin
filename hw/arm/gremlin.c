#include "qemu/osdep.h"
#include "hw/arm/gremlin.h"
#include "hw/arm/virt.h"
#include "hw/arm/machines-qom.h" 

static void gremlin_init(MachineState *machine) {
    GremlinMachineState* gms = GREMLIN_MACHINE(machine);
    GremlinMachineClass* gmc = GREMLIN_MACHINE_GET_CLASS(machine);

    gmc->machvirt_init(machine);

    if (gmc->i2c_init) {
        gmc->i2c_init(gms);
    }
}

static void gremlin_class_init(ObjectClass* oc, const void *data) {
    MachineClass* mc = MACHINE_CLASS(oc);
    GremlinMachineClass* gmc = GREMLIN_MACHINE_CLASS(oc);

    gmc->machvirt_init = mc->init;
    mc->init = gremlin_init;
}


static const TypeInfo gremlin_types[] = {
    {
        .name = TYPE_GREMLIN_MACHINE,       
        .abstract = true,
        .parent = TYPE_VIRT_MACHINE,
        .instance_size = sizeof(GremlinMachineState),
        .class_size = sizeof(GremlinMachineClass),
        .interfaces = arm_aarch64_machine_interfaces,
        .class_init=gremlin_class_init
    }
};

DEFINE_TYPES(gremlin_types)

