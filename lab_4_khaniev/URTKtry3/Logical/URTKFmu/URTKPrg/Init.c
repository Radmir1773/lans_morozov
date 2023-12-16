
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
	#include <stdio.h>
#endif

void reader()
{
	STRING *filename = "Gcodes.txt";
	FILE *fp = fopen(filename, "r");

	const unsigned MAX_LENGTH = 256;
	char buffer[MAX_LENGTH];

	while (fgets(buffer, MAX_LENGTH, fp))
		printf("%s", buffer);
	
	fclose(fp);
}
	
void _INIT ProgramInit(void)
{	
	urtk_out.internal_axisZ1 = 252.315;
	urtk_out.internal_axisZ2 = 336.641;
	urtk_out.internal_axisZ3 = -50.1246;
	urtk_out.internal_axisY1 = 280.678;
	urtk_out.internal_axisY2 = 114.875;
	urtk_out.internal_axisY3 = -267.531;
	urtk_out.internal_Ground1 = 241.35;
	urtk_out.internal_Ground2 = 20.735;
	urtk_out.internal_Ground3 = -50.4717;
	urtk_out.internal_movementX1 = 253.027;
	urtk_out.internal_movementX2 = 38.0305;
	urtk_out.internal_movementX3 = -49.6654;
	urtk_out.internal_movementY1 = 281.057;
	urtk_out.internal_movementY2 = 116.335;
	urtk_out.internal_movementY3 = -48;
	urtk_out.internal_movementZ1 = 252.937;
	urtk_out.internal_movementZ2 = 117;
	urtk_out.internal_movementZ3 = -48.6654;

}
