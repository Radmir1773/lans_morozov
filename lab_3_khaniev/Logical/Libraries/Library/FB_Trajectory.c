
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Trajectory(struct FB_Trajectory* inst) // Функциональный блок управления УРТК
{
	switch (inst->State) // Машина состояний
	{
		case Idle_Trajectory: // Состояние покоя 
			{
				if (inst->enable)
				{
					inst->done = 0;
					inst->State = PowerY; // Переход к запуску оси Y
				}
				break;
			}
		case PowerY : // Запуск оси Y
			{
				inst->Power_AxisY.Axis = inst->AxisY; // Объявление оси Y
				inst->Power_AxisY.enable = 1;
				if(inst->Power_AxisY.done)
				{
					inst->State = PowerZ; // Переход к запуску оси Z
				}
				break;
			}
		case PowerZ :  // Запуск оси Z 
			{
				inst->Power_AxisZ.Axis = inst->AxisZ; // Объявление оси Z
				inst->Power_AxisZ.enable = 1;
				if(inst->Power_AxisZ.done)
				{
					inst->State = side1; // Переход к состоянию движения по траектории 1-й стороны
				}
				break;
			}
		case side1 : // Состояние движения по траектории 1-й стороны
			{
				inst->Move_Axis.Axis = inst->AxisY;
				inst->Move_Axis.length = inst->length*100;
				inst->Move_Axis.enable = 1;
				if(inst->Move_Axis.done)
				{
					inst->State = side2; // Переход к состоянию движения по траектории 2-й стороны
				}
				break;
			}
		case side2 : // Состояние движения по траектории 2-й стороны
			{
				inst->Move_Axis.Axis = inst->AxisZ;
				inst->Move_Axis.length = inst->length*100;
				inst->Move_Axis.enable = 1;
				if(inst->Move_Axis.done)
				{
					inst->State = side3; // Переход к состоянию движения по траектории 3-й стороны
				}
				break;
			}
		case side3 : // Состояние движения по траектории 3-й стороны
			{
				inst->Move_Axis.Axis = inst->AxisY;
				inst->Move_Axis.length = -inst->length*100;
				inst->Move_Axis.enable = 1;
				if(inst->Move_Axis.done)
				{
					inst->State = side4; // Переход к состоянию движения по траектории 4-й стороны
				}
				break;
			}
		case side4 : // Состояние движения по траектории 4-й стороны
			{
				inst->Move_Axis.Axis = inst->AxisZ;
				inst->Move_Axis.length = -inst->length*100;
				inst->Move_Axis.enable = 1;
				if(inst->Move_Axis.done)
				{
					inst->State = Stop_Trajectory; // Переход к состоянию остановки и выключения УРТК
				}
				break;
			}
		case Stop_Trajectory : // Состояние остановке и выключения УРТК
			{
				inst->Power_AxisY.Power.Enable = 0;
				inst->Power_AxisZ.Power.Enable = 0;
				if (!inst->Power_AxisY.Power.Status && !inst->Power_AxisZ.Power.Status)
				{
					inst->State = Done_Trajectory; // Переход к состоянию завершения работы ФБ
				}
			}
		case Done_Trajectory : // Состояние завершения работы ФБ
			{
				inst->done = 1;
				if(inst->done)
				{
					inst->Move_Axis.done = 0;
					inst->Move_Axis.done = 0;
					inst->enable = 0;
					inst->State = Idle_Trajectory;
				}
				break;
			}
	}
	
	// Инициализация использованных функциональных блоков
	FB_move(&inst->Move_Axis);
	FB_power(&inst->Power_AxisY);
	FB_power(&inst->Power_AxisZ);
}
