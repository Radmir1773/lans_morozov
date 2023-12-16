
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#include <stdio.h>
#endif


void G_code() 
{
	for (i = 0; i < strlen(temp); ++i) 
	{
		if (temp[i] == 'G') 
		{
			for (j = i + 1; j < strlen(temp); ++j) 
			{
				if (temp[j] == ' ' || j == strlen(temp)-1) 
				{
					strncpy(buffer, &temp[i+1], j-i-1);
					out.command = atoi(buffer);
					strcpy(buffer, "");
					break;
				}
			}
		}
		
		if (out.command == 0)
		{
			if (temp[i] == 'X') 
			{
				for (j = i + 1; j < strlen(temp); ++j) 
				{
					if (temp[j] == ' ' || j == strlen(temp)-1) 
					{
						strncpy(buffer, &temp[i+1], j-i-1);
						out.x = atoi(buffer);
						strcpy(buffer, "");
						break;
					}
				}
			}
			if (temp[i] == 'Y') 
			{
				for (j = i + 1; j < strlen(temp); ++j) 
				{
					if (temp[j] == ' ' || j == strlen(temp)-1) 
					{
						strncpy(buffer, &temp[i+1], j-i-1);
						out.y = atoi(buffer);
						strcpy(buffer, "");
						break;
					}
				}
			}
			if (temp[i] == 'Z') 
			{
				for (j = i + 1; j < strlen(temp); ++j) 
				{
					if (temp[j] == ' ' || j == strlen(temp)-1) 
					{
						strncpy(buffer, &temp[i+1], j-i);
						out.z = atoi(buffer);
						strcpy(buffer, "");
						break;
					}
				}
			}
			if (temp[i] == 'F') 
			{
				for (j = i + 1; j < strlen(temp); ++j) 
				{
					if (temp[j] == ' ' || j == strlen(temp)-1) 
					{
						strncpy(buffer, &temp[i+1], j-i);
						out.f = atoi(buffer);
						strcpy(buffer, "");
						break;
					}
				}
			}
			
			if (out.x != (INT)x_real)
				URTK1.Xinputvelocity = out.f;
			if (out.y != (INT)y_real)
				URTK1.Yimputvelocity = out.f;
			if (out.z != (INT)z_real)
				URTK1.Zimputevelocity = out.f;	
		}
		
		if (out.command == 28)
		{
			if (sensorX1 != 0)
				URTK1.Xinputvelocity = -10;
			if (sensorY1 != 0)
				URTK1.Yimputvelocity = -10;
			if (sensorZ1 != 0)
				URTK1.Zimputevelocity = -10;
		}		
	}
}

void _CYCLIC ProgramCyclic(void)
{
	
	URTK(&URTK1);
	
	URTKView_0 .InstRef = URTK1.InstRef;
	
	URTKView(&URTKView_0 );
	
	urtk_out.internal_axisZ1 = URTK1.internal_axisZ1 + 252.315;
	urtk_out.internal_axisZ2 = URTK1.internal_axisZ2 + 336.641;
	urtk_out.internal_axisZ3 = URTK1.internal_axisZ3-50.1246;
	urtk_out.internal_axisY1 = URTK1.internal_axisY1 + 280.678;
	urtk_out.internal_axisY2 = URTK1.internal_axisY2 + 114.875;
	urtk_out.internal_axisY3 = URTK1.internal_axisY3 - 267.531;
	urtk_out.internal_Ground1 = URTK1.internal_Ground1 + 241.35;
	urtk_out.internal_Ground2 = URTK1.internal_Ground2 + 20.735;
	urtk_out.internal_Ground3 = URTK1.internal_Ground3 - 50.4717;
	urtk_out.internal_movementX1 = URTK1.internal_movementX1 + 253.027;
	urtk_out.internal_movementX2 = URTK1.internal_movementX2 + 38.0305;
	urtk_out.internal_movementX3 = URTK1.internal_movementX3 - 49.6654;
	urtk_out.internal_movementY1 = URTK1.internal_movementY1 + 281.057;
	urtk_out.internal_movementY2 = URTK1.internal_movementY2 + 116.335;
	urtk_out.internal_movementY3 = URTK1.internal_movementY3 - 48;
	urtk_out.internal_movementZ1 = URTK1.internal_movementZ1 + 252.937;
	urtk_out.internal_movementZ2 = URTK1.internal_movementZ2 + 117;
	urtk_out.internal_movementZ3 = URTK1.internal_movementZ3 - 48.6654;
	
	if (urtk_out.internal_movementX1 <= 80)
	{
		sensorX1 = 1;
		if (URTK1.Xinputvelocity > 0)
			URTK1.Xinputvelocity = 0;
	}
	
	if (urtk_out.internal_movementX1 >= 340)
	{
		sensorX2 = 1;
		if (URTK1.Xinputvelocity < 0)
			URTK1.Xinputvelocity = 0;
	}
	
	if (urtk_out.internal_movementX1 >= 80 && urtk_out.internal_movementX1 <= 340)
	{
		sensorX1 = 0;
		sensorX2 = 0;
	}
	
	if (urtk_out.internal_movementZ2 <= 130)
	{
		sensorY1 = 1;
		if (URTK1.Zimputevelocity < 0)
			URTK1.Zimputevelocity = 0;
	}
	
	if (urtk_out.internal_movementZ2 >= 390)
	{
		sensorY2 = 1;
		if (URTK1.Zimputevelocity > 0)
			URTK1.Zimputevelocity = 0;
	}
	
	if (urtk_out.internal_movementZ2 >= 130 && urtk_out.internal_movementZ2 <= 390)
	{
		sensorY1 = 0;
		sensorY2 = 0;
	}
	
	if (urtk_out.internal_axisY3 <= -255)
	{
		sensorZ1 = 1;
		if (URTK1.Yimputvelocity < 0)
			URTK1.Yimputvelocity = 0;
	}
	
	if (urtk_out.internal_axisY3 >= 10)
	{
		sensorZ2 = 1;
		if (URTK1.Yimputvelocity > 0)
			URTK1.Yimputvelocity = 0;
	}
	
	if (urtk_out.internal_axisY3 >= -255 && urtk_out.internal_axisY3 <= 10)
	{
		sensorZ1 = 0;
		sensorZ2 = 0;
	}
	
	int max_speed = 1000;
	
	if (URTK1.Xinputvelocity>max_speed)
		URTK1.Xinputvelocity = max_speed;
	if (URTK1.Xinputvelocity<-max_speed)
		URTK1.Xinputvelocity = -max_speed;
		
	if (URTK1.Zimputevelocity>max_speed)
		URTK1.Zimputevelocity = max_speed;
	if (URTK1.Zimputevelocity<-max_speed)
		URTK1.Zimputevelocity = -max_speed;
		
	if (URTK1.Yimputvelocity>max_speed)
		URTK1.Yimputvelocity = max_speed;
	if (URTK1.Yimputvelocity<-max_speed)
		URTK1.Yimputvelocity = -max_speed;
	
	URTK1.Enable = 1;
	URTK1.Internal.Fmi2.StepSize = 0.1;
	
	if (!working)
		G_code();
	
	if ((INT)x_real == out.x || sensorX1 == 1 || sensorX2 == 1)
	{
		URTK1.Xinputvelocity = 0;
	}
	
	if ((INT)y_real == out.y || sensorY1 == 1 || sensorY2 == 1)
	{
		URTK1.Yimputvelocity = 0;
	}
	
	if ((INT)z_real == out.z || sensorZ1 == 1 || sensorZ2 == 1)
	{
		URTK1.Zimputevelocity = 0;
	}
	
	if ((INT)x_real == out.x && (INT)y_real == out.y && (INT)z_real == out.z)
		working = 0;
	
	x_real += URTK1.Xinputvelocity*0.1;
	y_real += URTK1.Yimputvelocity*0.1;
	z_real += URTK1.Zimputevelocity*0.1;
}



