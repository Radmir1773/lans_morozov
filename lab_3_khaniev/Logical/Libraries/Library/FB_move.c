
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
void FB_move(struct FB_move* inst) // Функциональный блок движения оси
{
	switch (inst->State) // Машина состояний
	{
		case Idle_move: // Состояние покоя
			{
				if(inst->enable)
				{
					inst->Move.Done = 0;
					inst->done = 0;
					inst->State = Move; // Переход к состоянию движения
				}
			
				break;
			}
		case Move: // Состояние движение
			{
				// Передача необходимых параметров в функциональный блок
				inst->Move.Axis = inst->Axis;
				inst->Move.Execute = 1;
				inst->Move.Distance = inst->length;
				inst->Move.Velocity = 3000;
				inst->Move.Acceleration = 6000;
				inst->Move.Deceleration = 6000;
				
				if(inst->Move.Done)
				{
					inst->State = Done_move; // Переход к состоянию завершения
				}
			
				break;
			}
		case Done_move: // Состояние завершения
			{
				inst->done = 1;
				if(inst->done)
				{
					inst->Move.Execute = 0;
					inst->length = 0;
					inst->enable = 0;
					inst->State = Idle_move;
				}
			
				break;
			}
	}
	MC_MoveAdditive(&inst->Move); // Инициализация Функционального блока движения 
}
//ВсеГО хорошеГО