#include "qemu/osdep.h"
#include "hw/arm/gremlin.h"
#include "hw/arm/machines-qom.h"
#include "hw/arm/virt.h"
#include "hw/core/boards.h"
#include "qom/object.h"

#define TYPE_GREMLIN_X1_MACHINE MACHINE_TYPE_NAME("gremlin-x1")

struct GremlinX1MachineState {
    GremlinMachineState parent_obj;
};

static void gremlin_x1_machine_state_init(MachineState*);

static void gremlin_x1_class_init(ObjectClass *oc, const void *data) {
    MachineClass *mc = MACHINE_CLASS(oc);
    GremlinMachineClass *gmc = GREMLIN_MACHINE_CLASS(oc);

    mc->desc = "Gremlin X1 Board";
    gmc->machvirt_init = mc->init;

    mc->init = gremlin_x1_machine_state_init;
}

OBJECT_DECLARE_SIMPLE_TYPE(GremlinX1MachineState, GREMLIN_X1_MACHINE)

static void gremlin_x1_i2c_init(GremlinMachineState* state) {

}

static void gremlin_x1_machine_state_init(MachineState* machine) {
    GremlinMachineClass *g_class = GREMLIN_MACHINE_GET_CLASS(machine);
    GremlinMachineState *g_state = GREMLIN_MACHINE(machine);

    g_class->machvirt_init(machine);
    gremlin_x1_i2c_init(g_state);
}

static const TypeInfo gremlin_x1_types[] = {{
    .name = TYPE_GREMLIN_X1_MACHINE,
    .parent = TYPE_GREMLIN_MACHINE,
    .instance_size = sizeof(GremlinX1MachineState),
    .class_init = gremlin_x1_class_init,
}};

DEFINE_TYPES(gremlin_x1_types);
