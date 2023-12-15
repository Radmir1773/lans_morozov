
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
void FB_power(struct FB_power* inst) // Функциональный блок запуска и референсирования осей
{
	switch (inst->State) // Машина состояний для ФБ
	{
		case Idle: // Состояние покоя
			{
				if(inst->enable)
				{
					inst->done = 0;
					inst->State = Power; // Переход к состоянию запуска
				}
			
				break;
			}
		case Power: // Состояние запуска
			{
				inst->Power.Axis = inst->Axis;
				inst->Power.Enable = 1;
				
				inst->State = Home; // Переход к состоянию референсирования
			
				break;
			}
		case Home: // Состояние референсирования осей
			{
				inst->Home.Axis = inst->Axis;
				inst->Home.Execute = 1;
				inst->Home.HomingMode = 1;
				inst->Home.Position = 0;
				if (inst->Home.Done)
				{
					inst->State = Done; // Переход к состоянию завершения
				}
			
				break;
			}
		case Done: // Состояние завершения работы
			{
				inst->done = 1;
				if(inst->done)
				{
					inst->Home.Done = 0;
					inst->enable = 0;
					inst->State = Idle; // Переход в состояние покоя после завершения
				}
			
				break;
			}
	}
	
	//Инициализация использованных функциональных блоков
	MC_Power(&inst->Power);
	MC_Home(&inst->Home);
	
}
