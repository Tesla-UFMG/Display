/*
 * Determinação do erro do PopUp - PopUp_Error.h
 *
 *      Data: 25 de julho, 2024
 *      Autor: Gabriel Luiz

 */

#ifndef INC_DATA_PROCESS_H_
#define INC_DATA_PROCESS_H_
#include "ID.h"
#include "FDCAN.h"

#define _ERRO_CONTROLE ECU_Flag();
#define _ERRO_INVERSOR INVERSOR_Flag()
#define _ERRO_SEGURANCA BMS_Flag();

typedef enum{
    CONTROLE_Board,
    INVERSOR_Board,
    SAFETY_Board,
	BusOFF_CAN
} TypeError_t;

uint8_t ECU_Flag();

uint8_t BMS_Flag();

uint16_t INVERSOR_Flag();

uint8_t PopUpError_Flag();
#endif /* INC_DATA_PROCESS_ */
