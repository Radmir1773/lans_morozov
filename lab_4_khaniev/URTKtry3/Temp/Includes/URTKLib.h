/* Automation Studio generated header file */
/* Do not edit ! */
/* URTKLib  */

#ifndef _URTKLIB_
#define _URTKLIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "sys_lib.h"
#endif
#ifdef _SG4
		#include "sys_lib.h"
#endif
#ifdef _SGC
		#include "sys_lib.h"
#endif


/* Datatypes and datatypes of function blocks */
typedef struct URTKLibFmi2CbType
{	unsigned long Logger;
	unsigned long AllocateMemory;
	unsigned long FreeMemory;
	unsigned long StepFinished;
	unsigned long ComponentEnvironment;
} URTKLibFmi2CbType;

typedef struct URTKLibFmi2IfType
{	plcbit Enabled;
	double StartTime;
	double EndTime;
	double CurrentTime;
	double StepSize;
	signed long Error;
	unsigned long Instance;
	struct URTKLibFmi2CbType Callbacks;
} URTKLibFmi2IfType;

typedef struct URTKInternalType
{	struct URTKLibFmi2IfType Fmi2;
} URTKInternalType;

typedef struct URTKView
{
	/* VAR_INPUT (analog) */
	struct URTKInternalType* InstRef;
	/* VAR_OUTPUT (analog) */
	float ObjPos[9];
	/* VAR (analog) */
	double vInternal[9];
	/* VAR_INPUT (digital) */
	plcbit Enable;
} URTKView_typ;

typedef struct URTK
{
	/* VAR_INPUT (analog) */
	double Xinputvelocity;
	double Yimputvelocity;
	double Zimputevelocity;
	/* VAR_OUTPUT (analog) */
	unsigned long InstRef;
	double internal_axisY1;
	double internal_axisY2;
	double internal_axisY3;
	double internal_axisZ1;
	double internal_axisZ2;
	double internal_axisZ3;
	double internal_movementX1;
	double internal_movementX2;
	double internal_movementX3;
	double internal_movementY1;
	double internal_movementY2;
	double internal_movementY3;
	double internal_movementZ1;
	double internal_movementZ2;
	double internal_movementZ3;
	double internal_Ground1;
	double internal_Ground2;
	double internal_Ground3;
	/* VAR (analog) */
	struct URTKInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
} URTK_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void URTKView(struct URTKView* inst);
_BUR_PUBLIC void URTK(struct URTK* inst);


#ifdef __cplusplus
};
#endif
#endif /* _URTKLIB_ */

