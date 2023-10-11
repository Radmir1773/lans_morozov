
{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*Функциональный блок для моделирования двигателя*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		w : {REDUND_UNREPLICABLE} REAL;
		phi : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		integrator : {REDUND_UNREPLICABLE} FB_Integrator;
		Tm : {REDUND_UNREPLICABLE} REAL;
		ke : {REDUND_UNREPLICABLE} REAL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Integrator (*Функциональный блок интегратора*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		out : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		prev_value : REAL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Controller (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR
		dt : REAL; (*шаг расчёта 0.01*)
	END_VAR
	VAR_INPUT
		e_in : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_OUTPUT
		u_out : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		sum : REAL;
		a : REAL;
		k_p : REAL;
		k_i : REAL;
		max_abs_value : REAL;
		iyOld : REAL;
		integrator : FB_Integrator;
	END_VAR
END_FUNCTION_BLOCK
