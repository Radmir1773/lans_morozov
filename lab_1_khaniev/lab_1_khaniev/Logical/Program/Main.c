
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	// T_target = 1/30
	
	fb_motor1.ke = 0.24;
	fb_motor1.Tm = 0.1;
	fb_motor1.u = 0;
	
	fb_motor2.ke = 0.24;
	fb_motor2.Tm = 0.1;
	fb_motor2.u = 0;
	
	// regulated real drive
	fb_motor3.ke = 0.00735;
	fb_motor3.Tm = 0.0147;
	fb_motor3.u = 0;
	
	// unregulated real drive
	fb_motor4.ke = 0.00735;
	fb_motor4.Tm = 0.0147;
	fb_motor4.u = 0;
	
	fb_controller.k_p = 0.72;
	fb_controller.k_i = 7.2;
	fb_controller.max_abs_value = 24.0;
	fb_controller.dt = 0.01;
	fb_controller.integrator.dt=0.001;
	
	// for fb_motor3 -- real drive
	fb_controller2.k_p = 0.00324;   
	fb_controller2.k_i = 0.2205;    
	fb_controller2.max_abs_value = 24.0;
	fb_controller2.dt = 0.01;
	fb_controller2.integrator.dt=0.001;
	
	speed = 0;
	counter = 0;
	enable = 1;
	
}

void _CYCLIC ProgramCyclic(void)
{
	if(enable)
	{
		
		if(counter == 200)
		{
			speed = 50;
		}
		else if (counter == 400)
		{
			speed = 0;
			counter= 0;
		}
		
		counter++;
		
		fb_controller.e_in = speed - fb_motor1.w;
		FB_Controller(&fb_controller);
		
		// for real drive
		fb_controller2.e_in = speed - fb_motor3.w;
		FB_Controller(&fb_controller2);
		
		fb_motor1.u = fb_controller.u_out;
		// for real drive
		fb_motor3.u = fb_controller2.u_out;
		
		fb_motor2.u = speed * fb_motor2.ke;
		// for real drive
		fb_motor4.u = speed * fb_motor4.ke;
		
		FB_Motor(&fb_motor1);
		FB_Motor(&fb_motor2);
		
		// for real drives
		FB_Motor(&fb_motor3);
		FB_Motor(&fb_motor4);
		
		fb_integrator1.in = fb_motor1.w;
		FB_Integrator (&fb_integrator1);
		
		// for real drive
		fb_integrator2.in = fb_motor3.w;
		FB_Integrator (&fb_integrator2);
	}
}

void _EXIT ProgramExit(void)
{

}

