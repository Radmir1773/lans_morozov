#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DoorStateMachine(struct DoorStateMachine* inst)
{
	switch(inst->state)
	{
		case ST_INIT:
			{
				if(inst->sw1==0 && inst->sw2==0 && inst->sw3==0 && inst->sw4==0)
					inst->state=ST_UNKNOWN;
				break;
			}
		case ST_UNKNOWN:
			{
				if(inst->direction==0 && inst->sw1!=inst->swo1)
					inst->state=ST_CLOSE;
				if(inst->direction==1 && inst->sw1!=inst->swo1)
					inst->state=ST_NEG;
				if(inst->direction==1 && inst->sw2!=inst->swo2)
					inst->state=ST_ACC_NEG;
				if(inst->direction==1 && inst->sw3!=inst->swo3)
					inst->state=ST_DEC_NEG;
				
				if(inst->direction==1 && inst->sw4!=inst->swo4)
					inst->state=ST_OPEN;
				if(inst->direction==0 && inst->sw4!=inst->swo4)
					inst->state=ST_POS;
				if(inst->direction==0 && inst->sw3!=inst->swo3)
					inst->state=ST_ACC_POS;
				if(inst->direction==0 && inst->sw2!=inst->swo2)
					inst->state=ST_DEC_POS;
				break;
			}
		case ST_CLOSE:
			{
				inst->speed = 0;
				if(inst->direction==1)
					inst->state=ST_NEG;
				break;
			}
		case ST_NEG:
			{
				inst->speed = -250;
				if(inst->direction==1 && inst->sw2!=inst->swo2)
					inst->state=ST_ACC_NEG;
				if(inst->direction==0)
					inst->state=ST_DEC_POS;
				break;
				
			}
		case ST_ACC_NEG:
			{
				inst->speed = -800;
				if(inst->direction==1 && inst->sw3!=inst->swo3)
					inst->state=ST_DEC_NEG;
				if(inst->direction==0)
					inst->state=ST_ACC_POS;
				break;
			}
		case ST_DEC_NEG:
			{
				inst->speed = -250;
				if(inst->direction==1 && inst->sw4!=inst->swo4)
					inst->state=ST_OPEN;
				if(inst->direction==0)
					inst->state=ST_POS;
				break;
			}
		
		
		
		
		
		
		
		case ST_OPEN:
			{
				inst->speed = 0;
				if(inst->direction==0)
					inst->state=ST_POS;
				break;
			}
		case ST_POS:
			{
				inst->speed = 250;
				if(inst->direction==0 && inst->sw3!=inst->swo3)
					inst->state=ST_ACC_POS;
				if(inst->direction==1)
					inst->state=ST_DEC_NEG;
				break;
			}
		case ST_ACC_POS:
			{
				inst->speed = 800;
				if(inst->direction==0 && inst->sw2!=inst->swo2)
					inst->state=ST_DEC_POS;
				if(inst->direction==1)
					inst->state=ST_ACC_NEG;
				break;
			}
		case ST_DEC_POS:
			{
				inst->speed = 250;
				if(inst->direction==0 && inst->sw1!=inst->swo1)
					inst->state=ST_CLOSE;
				if(inst->direction==1)
					inst->state=ST_NEG;

				break;
			}
	}
	
	inst->swo1=inst->sw1;
	inst->swo2=inst->sw2;
	inst->swo3=inst->sw3;
	inst->swo4=inst->sw4;
}
