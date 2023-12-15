/* Automation Studio generated header file */
/* Do not edit ! */
/* Library  */

#ifndef _LIBRARY_
#define _LIBRARY_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "Runtime.h"
		#include "Operator.h"
		#include "asstring.h"
		#include "AsIOTime.h"
		#include "AsMath.h"
		#include "Acp10par.h"
		#include "NcGlobal.h"
		#include "astime.h"
		#include "brsystem.h"
		#include "sys_lib.h"
		#include "DataObj.h"
		#include "AsArLog.h"
		#include "FileIO.h"
		#include "AsArProf.h"
		#include "AsMem.h"
		#include "Acp10man.h"
		#include "AsIecCon.h"
		#include "Acp10sim.h"
		#include "Acp10_MC.h"
		#include "Acp10sdc.h"
		#include "Arnc0man.h"
#endif
#ifdef _SG3
		#include "Runtime.h"
		#include "Operator.h"
		#include "asstring.h"
		#include "AsIOTime.h"
		#include "AsMath.h"
		#include "Acp10par.h"
		#include "NcGlobal.h"
		#include "astime.h"
		#include "brsystem.h"
		#include "sys_lib.h"
		#include "DataObj.h"
		#include "AsArLog.h"
		#include "FileIO.h"
		#include "AsArProf.h"
		#include "AsMem.h"
		#include "Acp10man.h"
		#include "AsIecCon.h"
		#include "Acp10sim.h"
		#include "Acp10_MC.h"
		#include "Acp10sdc.h"
		#include "Arnc0man.h"
#endif
#ifdef _SGC
		#include "Runtime.h"
		#include "Operator.h"
		#include "asstring.h"
		#include "AsIOTime.h"
		#include "AsMath.h"
		#include "Acp10par.h"
		#include "NcGlobal.h"
		#include "astime.h"
		#include "brsystem.h"
		#include "sys_lib.h"
		#include "DataObj.h"
		#include "AsArLog.h"
		#include "FileIO.h"
		#include "AsArProf.h"
		#include "AsMem.h"
		#include "Acp10man.h"
		#include "AsIecCon.h"
		#include "Acp10sim.h"
		#include "Acp10_MC.h"
		#include "Acp10sdc.h"
		#include "Arnc0man.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef enum T_State_Trajectory
{	Idle_Trajectory,
	Done_Trajectory,
	side1,
	side2,
	side3,
	side4,
	PowerY,
	PowerZ,
	Stop_Trajectory
} T_State_Trajectory;

typedef enum T_State_move
{	Idle_move,
	Move,
	Done_move
} T_State_move;

typedef enum T_State_power
{	Idle,
	Power,
	Home,
	Done
} T_State_power;

typedef struct FB_Integrator
{
	/* VAR_INPUT (analog) */
	float in;
	float dt;
	/* VAR_OUTPUT (analog) */
	float out;
	/* VAR (analog) */
	float state;
} FB_Integrator_typ;

typedef struct FB_Motor
{
	/* VAR_INPUT (analog) */
	float in;
	/* VAR_OUTPUT (analog) */
	float out_w;
	float out_phi;
	/* VAR (analog) */
	float k_e;
	float T_m;
	float dt;
	struct FB_Integrator integrator;
	struct FB_Integrator integrator_phi;
} FB_Motor_typ;

typedef struct FB_Controller
{
	/* VAR_INPUT (analog) */
	float in;
	/* VAR_OUTPUT (analog) */
	float out;
	/* VAR (analog) */
	float k_i;
	float sum;
	float k_p;
	float dt;
	float max_abs_value;
	struct FB_Integrator integrator;
	float last_sum;
} FB_Controller_typ;

typedef struct FB_Endswitch
{
	/* VAR_INPUT (analog) */
	float in;
	float neg_value;
	float pos_value;
	/* VAR_OUTPUT (digital) */
	plcbit neg_reached;
	plcbit pos_reached;
} FB_Endswitch_typ;

typedef struct FB_Axis
{
	/* VAR_INPUT (analog) */
	signed char pwm_percentage;
	/* VAR_OUTPUT (analog) */
	signed short pwm_value;
	signed short counter;
	float speed;
	/* VAR (analog) */
	signed short last_counter;
	/* VAR_INPUT (digital) */
	plcbit reset_error;
	plcbit endswitch_a_reached;
	plcbit endswitch_b_reached;
	/* VAR_OUTPUT (digital) */
	plcbit reset_counter;
} FB_Axis_typ;

typedef struct FB_power
{
	/* VAR_INPUT (analog) */
	enum T_State_power State;
	struct MC_Power Power;
	struct MC_Home Home;
	unsigned long Axis;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit done;
} FB_power_typ;

typedef struct FB_move
{
	/* VAR_INPUT (analog) */
	unsigned long Axis;
	struct MC_MoveAdditive Move;
	float length;
	/* VAR (analog) */
	enum T_State_move State;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit done;
} FB_move_typ;

typedef struct FB_Trajectory
{
	/* VAR_INPUT (analog) */
	unsigned long AxisY;
	unsigned long AxisZ;
	float length;
	/* VAR (analog) */
	enum T_State_Trajectory State;
	struct FB_power Power_AxisY;
	struct FB_power Power_AxisZ;
	struct FB_move Move_Axis;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit done;
} FB_Trajectory_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FB_Motor(struct FB_Motor* inst);
_BUR_PUBLIC void FB_Integrator(struct FB_Integrator* inst);
_BUR_PUBLIC void FB_Controller(struct FB_Controller* inst);
_BUR_PUBLIC void FB_Endswitch(struct FB_Endswitch* inst);
_BUR_PUBLIC void FB_Axis(struct FB_Axis* inst);
_BUR_PUBLIC void FB_power(struct FB_power* inst);
_BUR_PUBLIC void FB_move(struct FB_move* inst);
_BUR_PUBLIC void FB_Trajectory(struct FB_Trajectory* inst);


#ifdef __cplusplus
};
#endif
#endif /* _LIBRARY_ */

