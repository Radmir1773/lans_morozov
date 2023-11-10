
FUNCTION_BLOCK DriveStateMachine
	VAR_INPUT
		state : UINT;
		enable : BOOL;
	END_VAR
	VAR_OUTPUT
		command : UINT;
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LedStateMachine
	VAR_INPUT
		state : DoorStates;
	END_VAR
	VAR_OUTPUT
		led2 : BOOL;
		led4 : BOOL;
		led3 : BOOL;
		led1 : BOOL;
		timer : INT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DoorStateMachine
	VAR_INPUT
		sw2 : BOOL;
		sw3 : BOOL;
		sw4 : BOOL;
		sw1 : BOOL;
		direction : BOOL;
		state : DoorStates;
	END_VAR
	VAR_OUTPUT
		speed : INT;
	END_VAR
	VAR
		swo1 : USINT;
		swo2 : USINT;
		swo3 : USINT;
		swo4 : USINT;
	END_VAR
END_FUNCTION_BLOCK
