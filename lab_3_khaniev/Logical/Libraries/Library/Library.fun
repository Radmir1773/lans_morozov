
FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : REAL;
	END_VAR
	VAR_OUTPUT
		out_w : REAL;
		out_phi : REAL;
	END_VAR
	VAR
		k_e : REAL;
		T_m : REAL;
		dt : REAL;
		integrator : FB_Integrator;
		integrator_phi : FB_Integrator;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : REAL;
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		out : REAL;
	END_VAR
	VAR
		state : REAL := 0.0;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Controller (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : REAL;
	END_VAR
	VAR_OUTPUT
		out : REAL;
	END_VAR
	VAR
		k_i : REAL;
		sum : REAL;
		k_p : REAL;
		dt : REAL;
		max_abs_value : REAL;
		integrator : FB_Integrator;
		last_sum : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Endswitch (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : REAL;
		neg_value : REAL;
		pos_value : REAL;
	END_VAR
	VAR_OUTPUT
		neg_reached : BOOL;
		pos_reached : BOOL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Axis (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		reset_error : BOOL;
		endswitch_a_reached : BOOL;
		endswitch_b_reached : BOOL;
		pwm_percentage : SINT;
	END_VAR
	VAR_OUTPUT
		reset_counter : BOOL;
		pwm_value : INT;
	END_VAR
	VAR_OUTPUT RETAIN
		counter : INT;
	END_VAR
	VAR_OUTPUT
		speed : REAL;
	END_VAR
	VAR
		last_counter : INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_power (*Функциональный блок запуска и референсирование осей*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		State : T_State_power;
		Power : MC_Power;
		Home : MC_Home;
		Axis : UDINT;
		enable : BOOL;
	END_VAR
	VAR_OUTPUT
		done : BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_move (*Функциональный блок движения оси*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Axis : UDINT;
		enable : BOOL;
		Move : MC_MoveAdditive;
		length : REAL;
	END_VAR
	VAR_OUTPUT
		done : BOOL;
	END_VAR
	VAR
		State : T_State_move;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Trajectory (*Функциональный блок управления УРТК*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		enable : BOOL;
		AxisY : UDINT;
		AxisZ : UDINT;
		length : REAL;
	END_VAR
	VAR_OUTPUT
		done : BOOL;
	END_VAR
	VAR
		State : T_State_Trajectory;
		Power_AxisY : FB_power;
		Power_AxisZ : FB_power;
		Move_Axis : FB_move;
	END_VAR
END_FUNCTION_BLOCK
