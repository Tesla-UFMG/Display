/*
 * Mapa de identificadores de variaveis do display - CAN_map.h
 *
 *      Data: 24 de julho, 2024
 *      Autor: Gabriel Luiz

 */

#ifndef INC_FDCAN_MAP_H_
#define INC_FDCAN_MAP_H_
#include "ID.h"
#include "FDCAN.h"
#include "PopUp_Error.h"

extern "C" {
extern CAN_Buffer_t CAN_stream;
extern uint16_t DataRATE_Telemetry;
extern uint16_t DataRATE_Datalogger;
extern uint16_t DataRATE_BMS;
extern uint16_t DataRATE_ECU;
extern uint8_t Flag_PopUP;
}

/********************* ANIMATION PAGE *********************/
#define PAGE_ANIMATION_RTD_FLAG *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_FLAGS_STATUS])

/************************ LORA PAGE ***********************/
#define PAGE_LORA_User_ID *((uint16_t *) CAN_stream.Data_buf[CanID_AQS_LORA_USER_ID])
#define PAGE_LORA_Data_Rate *((uint8_t *) CAN_stream.Data_buf[CanID_AQS_LORA_DATA_RATE])
#define PAGE_LORA_Version *((uint16_t *) CAN_stream.Data_buf[CanID_AQS_LORA_VERSION])
#define PAGE_LORA_RSSI *((uint8_t *) CAN_stream.Data_buf[CanID_AQS_LORA_RSSI])
#define PAGE_LORA_State *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
#define PAGE_LORA_Frequencia *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_FREQUENCIA])
#define PAGE_LORA_Spread_Factor *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_SPREAD_FACT])
#define PAGE_LORA_Bandwich *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_BANDWIDTH])
#define PAGE_LORA_Coding_Rate *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_CODING_RATE])

/*********************** DRIVER PAGE **********************/
#ifdef UPDATED_PROTOCOL
    #define PAGE_DRIVER_Velocidade *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_VELOCIDADE_MED])
    #define PAGE_DRIVER_Potencia (*((uint8_t *) CAN_stream.Data_buf[CanID_ECU_POTENCIA_MD]) + *((uint8_t *)CAN_stream.Data_buf[CanID_ECU_POTENCIA_ME]))/2
    #define PAGE_DRIVER_Hodometro *((uint16_t *) CAN_stream.Data_buf[CanID_ECU_HODOM_PARCIAL])
    #define PAGE_DRIVER_Charge *((uint8_t *) CAN_stream.Data_buf[CanID_SS_CARGA_ATUAL])
    #define PAGE_DRIVER_LoRa_State (LoRa_Status_t)*((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
    #define PAGE_DRIVER_Modo *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_MODO])
    #define PAGE_DRIVER_Torque (*((uint8_t *) CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_D]) + *((uint8_t *)CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_E]))/2
    #define PAGE_DRIVER_Brake_Bias 0
    #define PAGE_DRIVER_Tensao_Min *((uint16_t *) CAN_stream.Data_buf[CanID_SS_TENSAO_MIN])
    #define PAGE_DRIVER_Temp_Max *((uint16_t *) CAN_stream.Data_buf[CanID_SS_TEMP_MAX])
    #define PAGE_DRIVER_PopUp Flag_PopUP
#else
    #define PAGE_DRIVER_Velocidade (uint16_t) (CAN_stream.Data_buf[76][1] << 8 | CAN_stream.Data_buf[76][0])

    // uint16_t potencia_me = (uint16_t) (CAN_stream.Data_buf[85][2] << 8 | CAN_stream.Data_buf[85][3]);
    // uint16_t potencia_md = (uint16_t) (CAN_stream.Data_buf[95][2] << 8 | CAN_stream.Data_buf[95][3]);
    #define PAGE_DRIVER_Potencia (uint16_t) ((uint16_t) (CAN_stream.Data_buf[85][3] << 8 | CAN_stream.Data_buf[85][2]) + (uint16_t) (CAN_stream.Data_buf[95][3] << 8 | CAN_stream.Data_buf[95][2])) / 2

    #define PAGE_DRIVER_Hodometro (uint16_t) (CAN_stream.Data_buf[77][5] << 8 | CAN_stream.Data_buf[77][4])
    #define PAGE_DRIVER_Charge *((uint8_t *) CAN_stream.Data_buf[CanID_SS_CARGA_ATUAL])
    #define PAGE_DRIVER_LoRa_State (LoRa_Status_t)*((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
    #define PAGE_DRIVER_Modo *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_MODO])
    #define PAGE_DRIVER_Torque (*((uint8_t *) CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_D]) + *((uint8_t *)CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_E]))/2
    #define PAGE_DRIVER_Brake_Bias 0
    #define PAGE_DRIVER_Tensao_Min *((uint16_t *) CAN_stream.Data_buf[CanID_SS_TENSAO_MIN])
    #define PAGE_DRIVER_Temp_Max *((uint16_t *) CAN_stream.Data_buf[CanID_SS_TEMP_MAX])
    #define PAGE_DRIVER_PopUp Flag_PopUP
#endif

/********************** CONTROL PAGE **********************/
#ifdef UPDATED_PROTOCOL
    #define PAGE_CONTROL_Temperatura_ME (*((uint16_t *) CAN_stream.Data_buf[CanID_ECU_TEMP_1_MOS_ME]) + *((uint16_t *)CAN_stream.Data_buf[CanID_ECU_TEMP_2_MOS_ME]))/2
    #define PAGE_CONTROL_Torque_Inst_ME *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_TORQUE_ME])
    #define PAGE_CONTROL_Poten_Inst_ME *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_POTENCIA_ME])
    #define PAGE_CONTROL_Giros_ME *((uint16_t *) CAN_stream.Data_buf[CanID_ECU_VELOCIDADE_ME])
    #define PAGE_CONTROL_Temperatura_MD (*((uint16_t *) CAN_stream.Data_buf[CanID_ECU_TEMP_1_MOS_MD]) + *((uint16_t *)CAN_stream.Data_buf[CanID_ECU_TEMP_2_MOS_MD]))/2
    #define PAGE_CONTROL_Torque_Inst_MD *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_TORQUE_MD])
    #define PAGE_CONTROL_Poten_Inst_MD *((uint8_t *) CAN_stream.Data_buf[CanID_ECU_POTENCIA_MD])
    #define PAGE_CONTROL_Giros_MD *((uint16_t *) CAN_stream.Data_buf[CanID_ECU_VELOCIDADE_MD])
    #define PAGE_CONTROL_Angulo_Vol *((uint16_t *) CAN_stream.Data_buf[CanID_ECU_VOLANTE_ANG])
    #define PAGE_CONTROL_Angulo_Car *((uint16_t *) CAN_stream.Data_buf[CanID_ECU_VOLANTE_ANG]) // melhorar depois, pegar da IMU
    #define PAGE_CONTROL_LoRa_State *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
    #define PAGE_CONTROL_Modo *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_MODO])
    #define PAGE_CONTROL_Frenagem *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_FRENAGEM_STATUS])
    #define PAGE_CONTROL_Acelerometro ((int16_t *) CAN_stream.Data_buf[CanID_ECU_ACEL_IMU_Temp])[1] << 8 | ((int16_t *) CAN_stream.Data_buf[CanID_ECU_ACEL_IMU_Temp])[0]
    #define PAGE_CONTROL_Giroscopio ((int16_t *) CAN_stream.Data_buf[CanID_ECU_GIR_IMU_Erro])[1] << 8 | ((int16_t *) CAN_stream.Data_buf[CanID_ECU_GIR_IMU_Erro])[0]
    #define PAGE_CONTROL_Torque (*((uint64_t *) CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_D]) + *((uint64_t *)CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_E]))/2
    #define PAGE_CONTROL_PopUp Flag_PopUP
#else
    #define PAGE_CONTROL_Temperatura_MD (uint16_t) ((uint16_t) (CAN_stream.Data_buf[86][5] << 8 | CAN_stream.Data_buf[86][4]) + (uint16_t) (CAN_stream.Data_buf[86][7] << 8 | CAN_stream.Data_buf[86][6])) / 2
    #define PAGE_CONTROL_Torque_Inst_MD (uint16_t) (CAN_stream.Data_buf[85][3] << 8 | CAN_stream.Data_buf[85][2])
    #define PAGE_CONTROL_Poten_Inst_MD (uint16_t) (CAN_stream.Data_buf[85][5] << 8 | CAN_stream.Data_buf[85][4])
    #define PAGE_CONTROL_Giros_MD (uint16_t) (CAN_stream.Data_buf[85][1] << 8 | CAN_stream.Data_buf[85][0])
    #define PAGE_CONTROL_Temperatura_ME (uint16_t) ((uint16_t) (CAN_stream.Data_buf[96][5] << 8 | CAN_stream.Data_buf[96][4]) + (uint16_t) (CAN_stream.Data_buf[96][7] << 8 | CAN_stream.Data_buf[96][6])) / 2
    #define PAGE_CONTROL_Torque_Inst_ME (uint16_t) (CAN_stream.Data_buf[95][3] << 8 | CAN_stream.Data_buf[95][2])
    #define PAGE_CONTROL_Poten_Inst_ME (uint16_t) (CAN_stream.Data_buf[95][5] << 8 | CAN_stream.Data_buf[95][4])
    #define PAGE_CONTROL_Giros_ME (uint16_t) (CAN_stream.Data_buf[95][1] << 8 | CAN_stream.Data_buf[95][0])
    #define PAGE_CONTROL_Angulo_Vol (uint16_t) (CAN_stream.Data_buf[76][3] << 8 | CAN_stream.Data_buf[76][2])
    #define PAGE_CONTROL_Angulo_Car (uint16_t) (CAN_stream.Data_buf[76][3] << 8 | CAN_stream.Data_buf[76][2]) // melhorar depois, pegar da IMU
    #define PAGE_CONTROL_LoRa_State *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
    #define PAGE_CONTROL_Modo (uint16_t) (CAN_stream.Data_buf[77][1] << 8 | CAN_stream.Data_buf[77][0])
    #define PAGE_CONTROL_Frenagem *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_FRENAGEM_STATUS])
    #define PAGE_CONTROL_Acelerometro ((int16_t *) CAN_stream.Data_buf[CanID_ECU_ACEL_IMU_Temp])[1] << 8 | ((int16_t *) CAN_stream.Data_buf[CanID_ECU_ACEL_IMU_Temp])[0]
    #define PAGE_CONTROL_Giroscopio ((int16_t *) CAN_stream.Data_buf[CanID_ECU_GIR_IMU_Erro])[1] << 8 | ((int16_t *) CAN_stream.Data_buf[CanID_ECU_GIR_IMU_Erro])[0]
    #define PAGE_CONTROL_Torque (*((uint64_t *) CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_D]) + *((uint64_t *)CAN_stream.Data_buf[CanID_ECU_REF_TORQ_MOTOR_E]))/2
    #define PAGE_CONTROL_PopUp Flag_PopUP
#endif

/*********************** SAFETY PAGE **********************/
#define PAGE_SAFETY_Stack_1 *((uint8_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENSAO_TOTAL])
#define PAGE_SAFETY_Stack_2 *((uint8_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENSAO_TOTAL])
#define PAGE_SAFETY_Stack_3 *((uint8_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENSAO_TOTAL])
#define PAGE_SAFETY_Stack_4 *((uint8_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENSAO_TOTAL])
#define PAGE_SAFETY_Stack_5 *((uint8_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENSAO_TOTAL])
#define PAGE_SAFETY_Stack_6 *((uint8_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENSAO_TOTAL])
#define PAGE_SAFETY_Corrente_1 *((uint16_t *) CAN_stream.Data_buf[CanID_SS_CORRENTE_0])
#define PAGE_SAFETY_Corrente_2 *((uint16_t *) CAN_stream.Data_buf[CanID_SS_CORRENTE_1])
#define PAGE_SAFETY_Corrente_3 *((uint16_t *) CAN_stream.Data_buf[CanID_SS_CORRENTE_2])
#define PAGE_SAFETY_Corrente_4 *((uint16_t *) CAN_stream.Data_buf[CanID_SS_CORRENTE_3])
#define PAGE_SAFETY_Charge *((uint64_t *) CAN_stream.Data_buf[CanID_SS_CARGA_ATUAL])
#define PAGE_SAFETY_LoRa_State *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
#define PAGE_SAFETY_Modo *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_MODO])
#define PAGE_SAFETY_Air *((uint64_t *) CAN_stream.Data_buf[CanID_SS_STATUS_CONTATOR])
#define PAGE_SAFETY_Tensao_Max *((uint64_t *) CAN_stream.Data_buf[CanID_SS_TENSAO_MAX])
#define PAGE_SAFETY_Tensao_Min *((uint64_t *) CAN_stream.Data_buf[CanID_SS_TENSAO_MIN])
#define PAGE_SAFETY_Temp_Max *((uint64_t *) CAN_stream.Data_buf[CanID_SS_TEMP_MAX])
#define PAGE_SAFETY_PopUp Flag_PopUP

/************************ STACK PAGE ***********************/
#define PAGE_STACK_1_CELL_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_1])
#define PAGE_STACK_1_CELL_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_2])
#define PAGE_STACK_1_CELL_3 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_3])
#define PAGE_STACK_1_CELL_4 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_4])
#define PAGE_STACK_1_CELL_5 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_5])
#define PAGE_STACK_1_CELL_6 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_6])
#define PAGE_STACK_1_CELL_7 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_7])
#define PAGE_STACK_1_CELL_8 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_8])
#define PAGE_STACK_1_CELL_9 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_9])
#define PAGE_STACK_1_CELL_10 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_10])
#define PAGE_STACK_1_CELL_11 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_11])
#define PAGE_STACK_1_CELL_12 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK1_TENS_CELL_12])
#define PAGE_STACK_1_CELL_13 0
#define PAGE_STACK_1_CELL_14 0
#define PAGE_STACK_1_CELL_15 0
#define PAGE_STACK_1_CELL_16 0

#define PAGE_STACK_2_CELL_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_1])
#define PAGE_STACK_2_CELL_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_2])
#define PAGE_STACK_2_CELL_3 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_3])
#define PAGE_STACK_2_CELL_4 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_4])
#define PAGE_STACK_2_CELL_5 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_5])
#define PAGE_STACK_2_CELL_6 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_6])
#define PAGE_STACK_2_CELL_7 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_7])
#define PAGE_STACK_2_CELL_8 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_8])
#define PAGE_STACK_2_CELL_9 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_9])
#define PAGE_STACK_2_CELL_10 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_10])
#define PAGE_STACK_2_CELL_11 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_11])
#define PAGE_STACK_2_CELL_12 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK2_TENS_CELL_12])
#define PAGE_STACK_2_CELL_13 0
#define PAGE_STACK_2_CELL_14 0
#define PAGE_STACK_2_CELL_15 0
#define PAGE_STACK_2_CELL_16 0

#define PAGE_STACK_3_CELL_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_1])
#define PAGE_STACK_3_CELL_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_2])
#define PAGE_STACK_3_CELL_3 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_3])
#define PAGE_STACK_3_CELL_4 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_4])
#define PAGE_STACK_3_CELL_5 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_5])
#define PAGE_STACK_3_CELL_6 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_6])
#define PAGE_STACK_3_CELL_7 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_7])
#define PAGE_STACK_3_CELL_8 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_8])
#define PAGE_STACK_3_CELL_9 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_9])
#define PAGE_STACK_3_CELL_10 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_10])
#define PAGE_STACK_3_CELL_11 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_11])
#define PAGE_STACK_3_CELL_12 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK3_TENS_CELL_12])
#define PAGE_STACK_3_CELL_13 0
#define PAGE_STACK_3_CELL_14 0
#define PAGE_STACK_3_CELL_15 0
#define PAGE_STACK_3_CELL_16 0

#define PAGE_STACK_4_CELL_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_1])
#define PAGE_STACK_4_CELL_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_2])
#define PAGE_STACK_4_CELL_3 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_3])
#define PAGE_STACK_4_CELL_4 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_4])
#define PAGE_STACK_4_CELL_5 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_5])
#define PAGE_STACK_4_CELL_6 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_6])
#define PAGE_STACK_4_CELL_7 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_7])
#define PAGE_STACK_4_CELL_8 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_8])
#define PAGE_STACK_4_CELL_9 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_9])
#define PAGE_STACK_4_CELL_10 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_10])
#define PAGE_STACK_4_CELL_11 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_11])
#define PAGE_STACK_4_CELL_12 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK4_TENS_CELL_12])
#define PAGE_STACK_4_CELL_13 0
#define PAGE_STACK_4_CELL_14 0
#define PAGE_STACK_4_CELL_15 0
#define PAGE_STACK_4_CELL_16 0

#define PAGE_STACK_5_CELL_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_1])
#define PAGE_STACK_5_CELL_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_2])
#define PAGE_STACK_5_CELL_3 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_3])
#define PAGE_STACK_5_CELL_4 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_4])
#define PAGE_STACK_5_CELL_5 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_5])
#define PAGE_STACK_5_CELL_6 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_6])
#define PAGE_STACK_5_CELL_7 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_7])
#define PAGE_STACK_5_CELL_8 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_8])
#define PAGE_STACK_5_CELL_9 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_9])
#define PAGE_STACK_5_CELL_10 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_10])
#define PAGE_STACK_5_CELL_11 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_11])
#define PAGE_STACK_5_CELL_12 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK5_TENS_CELL_12])
#define PAGE_STACK_5_CELL_13 0
#define PAGE_STACK_5_CELL_14 0
#define PAGE_STACK_5_CELL_15 0
#define PAGE_STACK_5_CELL_16 0

#define PAGE_STACK_6_CELL_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_1])
#define PAGE_STACK_6_CELL_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_2])
#define PAGE_STACK_6_CELL_3 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_3])
#define PAGE_STACK_6_CELL_4 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_4])
#define PAGE_STACK_6_CELL_5 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_5])
#define PAGE_STACK_6_CELL_6 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_6])
#define PAGE_STACK_6_CELL_7 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_7])
#define PAGE_STACK_6_CELL_8 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_8])
#define PAGE_STACK_6_CELL_9 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_9])
#define PAGE_STACK_6_CELL_10 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_10])
#define PAGE_STACK_6_CELL_11 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_11])
#define PAGE_STACK_6_CELL_12 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_PCK6_TENS_CELL_12])
#define PAGE_STACK_6_CELL_13 0
#define PAGE_STACK_6_CELL_14 0
#define PAGE_STACK_6_CELL_15 0
#define PAGE_STACK_6_CELL_16 0

/*********************** DEBUG PAGE ***********************/
#define PAGE_DEBUG_ECU DataRATE_ECU
#define PAGE_DEBUG_BMS DataRATE_BMS
#define PAGE_DEBUG_Datalogger DataRATE_Datalogger
#define PAGE_DEBUG_Telemetria DataRATE_Telemetry
#define PAGE_DEBUG_Lora_State *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_LORA_STATUS])
#define PAGE_DEBUG_State_Datalogger DataRATE_Datalogger != 0
#define PAGE_DEBUG_State_Telemetry DataRATE_Telemetry != 0
#define PAGE_DEBUG_State_BMS DataRATE_BMS != 0
#define PAGE_DEBUG_State_ECU DataRATE_ECU != 0
#define PAGE_DEBUG_Beacon *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_BEACON_VIRTUAL])
#define PAGE_DEBUG_PopUp Flag_PopUP

/************************ BOARD PAGE ************************/
#define PAGE_BOARD_Telemetria_DEBUG_0 *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_TEL_DEBUG_0])
#define PAGE_BOARD_Telemetria_DEBUG_1 *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_TEL_DEBUG_1])
#define PAGE_BOARD_Telemetria_DEBUG_2 *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_TEL_DEBUG_2])

#define PAGE_BOARD_Datalogger_DEBUG_0 *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_DAT_DEBUG_0])
#define PAGE_BOARD_Datalogger_DEBUG_1 *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_DAT_DEBUG_1])
#define PAGE_BOARD_Datalogger_DEBUG_2 *((uint64_t *) CAN_stream.Data_buf[CanID_AQS_DAT_DEBUG_2])

#define PAGE_BOARD_BMS_DEBUG_0 *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_DEBUG_0])
#define PAGE_BOARD_BMS_DEBUG_1 *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_DEBUG_1])
#define PAGE_BOARD_BMS_DEBUG_2 *((uint64_t *) CAN_stream.Data_buf[CanID_ECU_DEBUG_2])

#define PAGE_BOARD_ECU_DEBUG_0 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_DEBUG_0])
#define PAGE_BOARD_ECU_DEBUG_1 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_DEBUG_1])
#define PAGE_BOARD_ECU_DEBUG_2 *((uint64_t *) CAN_stream.Data_buf[CanID_SS_DEBUG_2])

#endif /* INC_FD*((uint64_t *) CAN_MAP_H_ */
