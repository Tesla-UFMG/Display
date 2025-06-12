#include "PopUp_Error.h"
#include "cmsis_os2.h"

extern CAN_Buffer_t *CAN_stream;

TypeError_t Actual_ERROR = CONTROLE_Board;

uint32_t flagsTimeout = 0;

uint8_t Flag_PopUP = 0;

uint8_t Flag_ErroBMS = 0;

uint16_t Flag_ErroECU = 0;

uint8_t ECU_Flag() {
	Flag_ErroECU = CAN_Get_value(CanID_ECU_FLAGS_ERRO);
	for (int8_t i = 15; i >= 0; i--) {
		if (Flag_ErroECU >> i == 1) {
			return i + 1;
		}
	}
	return 0;
}
uint8_t BMS_Flag() {
	Flag_ErroBMS = CAN_Get_value(CanID_SS_FLAG_ERRO);
	for (int8_t i = 8; i >= 0; i--)
		if (Flag_ErroBMS >> i == 1)
			return i + 1;
	return 0;
}

uint16_t INVERSOR_Flag() {
	uint16_t FALHA = 0;
	uint16_t ALARME = 0;

	if (CAN_Get_value(CanID_ECU_FALHA_ATUAL_MD)
			> CAN_Get_value(CanID_ECU_FALHA_ATUAL_ME))
		FALHA = CAN_Get_value(CanID_ECU_FALHA_ATUAL_MD);
	else
		FALHA = CAN_Get_value(CanID_ECU_FALHA_ATUAL_ME);

	if (CAN_Get_value(CanID_ECU_ALARM_ATUAL_MD)
			> CAN_Get_value(CanID_ECU_ALARM_ATUAL_ME))
		ALARME = CAN_Get_value(CanID_ECU_ALARM_ATUAL_MD);
	else
		ALARME = CAN_Get_value(CanID_ECU_ALARM_ATUAL_ME);

	if (FALHA != 0)
		return FALHA;
	else if (ALARME != 0)
		return ALARME;
	return 0;
}

uint8_t timer_wait_ms(uint32_t timer_start, uint32_t delay) {
	const uint32_t current_time = HAL_GetTick();
	if ((current_time - timer_start) >= delay) {
		return 1;
	}
	return 0;
}
void timer_restart(uint32_t *timer_to_restart) {
	*timer_to_restart = HAL_GetTick();
}

uint8_t osTask_PopUpError() {
	/*Verify if have an control flag error during 1s*/
	while (1) {
		uint16_t ERRO = 0;
		switch (Actual_ERROR) {
		case CONTROLE_Board:

			if (timer_wait_ms(flagsTimeout, 2000))
				Actual_ERROR = INVERSOR_Board;
			else
				ERRO = _ERRO_CONTROLE
			;

			switch (ERRO) {
			case 1:
				Flag_PopUP = 2;
				break;
			case 2:
				Flag_PopUP = 3;
				break;
			case 9:
				Flag_PopUP = 4;
				break;
			case 10:
				Flag_PopUP = 5;
				break;
			case 11:
				Flag_PopUP = 6;
				break;
			default:
				if (Actual_ERROR != BusOFF_CAN)
					Actual_ERROR = INVERSOR_Board;
				timer_restart(&flagsTimeout);
				break;
			}
			if (Flag_PopUP != 0)
				break;
		case INVERSOR_Board:
			/*Verify if have an control flag status during 1s*/
			if (timer_wait_ms(flagsTimeout, 2000))
				Actual_ERROR = SAFETY_Board;
			else
				ERRO = _ERRO_INVERSOR;

			switch (ERRO) {
			case 46:
				Flag_PopUP = 7;
				break;
			case 47:
				Flag_PopUP = 8;
				break;
			case 50:
				Flag_PopUP = 9;
				break;
			case 90:
				Flag_PopUP = 10;
				break;
			case 98:
				Flag_PopUP = 11;
				break;
			case 110:
				Flag_PopUP = 12;
				break;
			case 128:
				Flag_PopUP = 13;
				break;
			case 133:
				Flag_PopUP = 14;
				break;
			case 134:
				Flag_PopUP = 15;
				break;
			case 135:
				Flag_PopUP = 16;
				break;
			case 136:
				Flag_PopUP = 17;
				break;
			case 152:
				Flag_PopUP = 18;
				break;
			case 702:
				Flag_PopUP = 19;
				break;
			case 704:
				Flag_PopUP = 20;
				break;
			case 706:
				Flag_PopUP = 21;
				break;
			case 21:
				Flag_PopUP = 22;
				break;
			case 22:
				Flag_PopUP = 23;
				break;
			case 30:
				Flag_PopUP = 24;
				break;
			case 34:
				Flag_PopUP = 25;
				break;
			case 38:
				Flag_PopUP = 26;
				break;
			case 48:
				Flag_PopUP = 27;
				break;
			case 51:
				Flag_PopUP = 28;
				break;
			case 67:
				Flag_PopUP = 29;
				break;
			case 71:
				Flag_PopUP = 30;
				break;
			case 72:
				Flag_PopUP = 31;
				break;
			case 78:
				Flag_PopUP = 32;
				break;
			case 79:
				Flag_PopUP = 33;
				break;
			case 80:
				Flag_PopUP = 34;
				break;
			case 84:
				Flag_PopUP = 35;
				break;
			case 91:
				Flag_PopUP = 36;
				break;
			case 99:
				Flag_PopUP = 37;
				break;
			case 150:
				Flag_PopUP = 38;
				break;
			case 153:
				Flag_PopUP = 39;
				break;
			case 156:
				Flag_PopUP = 40;
				break;
			case 157:
				Flag_PopUP = 41;
				break;
			case 158:
				Flag_PopUP = 42;
				break;
			case 182:
				Flag_PopUP = 43;
				break;
			case 183:
				Flag_PopUP = 44;
				break;
			case 185:
				Flag_PopUP = 45;
				break;
			case 228:
				Flag_PopUP = 46;
				break;
			case 234:
				Flag_PopUP = 47;
				break;
			case 235:
				Flag_PopUP = 48;
				break;
			case 711:
				Flag_PopUP = 49;
				break;
			default:
				if (Actual_ERROR != BusOFF_CAN)
					Actual_ERROR = SAFETY_Board;
				timer_restart(&flagsTimeout);
				break;
			}
			if (Flag_PopUP != 0)
				break;
		case SAFETY_Board:
			/*Verify if have an security flag error during 1s after control*/
			if (timer_wait_ms(flagsTimeout, 2000))
				Actual_ERROR = CONTROLE_Board;
			else
				ERRO = _ERRO_SEGURANCA
			;

			switch (ERRO) {
			case 1:
				Flag_PopUP = 50;
				break;
			case 2:
				Flag_PopUP = 51;
				break;
			case 3:
				Flag_PopUP = 52;
				break;
			default:
				if (Actual_ERROR != BusOFF_CAN)
					Actual_ERROR = CONTROLE_Board;
				timer_restart(&flagsTimeout);
				break;
			}
			break;
		case BusOFF_CAN:
			while (Actual_ERROR == BusOFF_CAN)
				Flag_PopUP = 1;
		default:
			timer_restart(&flagsTimeout);
			Flag_PopUP = 0;
			break;
		}
	}
}
