
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library1.h"
#ifdef __cplusplus
	};
#endif
/* Функциональный блок интегратора */
void FB_Integrator(struct FB_Integrator* inst)
{
	inst->dt = d_t;
	inst->out = inst->dt * inst->in + inst->prev_value;
	inst->prev_value = inst->out;
}
