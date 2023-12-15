
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	// ќбъ€вление осей Y и Z по адресу
	Trajectory.AxisY = &AxisY;
	Trajectory.AxisZ = &AxisZ;
	
	// ћнгновенное присваивание значени€ 0 при инициализации переменной
	Trajectory.length = 0;
	Move_axis.length = 0;
}

void _CYCLIC ProgramCyclic(void)
{	
	FB_Trajectory(&Trajectory); // »нициализаци€ функционального блока     
}

void _EXIT ProgramExit(void)
{

}

