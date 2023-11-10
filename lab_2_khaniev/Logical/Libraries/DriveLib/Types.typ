
TYPE
	DoorStates : 
		(
		ST_INIT,
		ST_UNKNOWN,
		ST_OPEN,
		ST_CLOSE,
		ST_ACC_POS,
		ST_ACC_NEG,
		ST_DEC_NEG,
		ST_DEC_POS,
		ST_NEG,
		ST_POS
		);
	DriveStates : 
		(
		CMD_ENABLED := 15,
		STATE_DISABLED := 64,
		CMD_SHUTDOWN := 6,
		CMD_SWITCHED_ON := 7,
		STATE_SWITCHED_ON := 35,
		STATE_READY := 33
		);
END_TYPE
