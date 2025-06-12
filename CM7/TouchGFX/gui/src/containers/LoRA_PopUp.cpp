#include <gui/containers/LoRA_PopUp.hpp>
#include <images/BitmapDatabase.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#include <math.h>
#endif

LoRA_PopUp::LoRA_PopUp() {
}

#define TIME_TRANSITION_LoRa 15U

uint8_t LoRa_FlagConfig = 0;

typedef enum {
	BANDWICH_125 = 0, BANDWICH_250, BANDWICH_500
} LoRa_Bandwich_t;

typedef enum {
	SF_6 = 6, SF_7, SF_8, SF_9, SF_10, SF_11, SF_12
} LoRa_SpreadFactor_t;

typedef enum {
	CR1_5 = 1, CR1_6, CR1_7, CR1_8
} LoRa_CodingRate_t;

LoRa_Bandwich_t Bandwich_Value = BANDWICH_125;
LoRa_SpreadFactor_t SpreadFactor_Value = SF_6;
LoRa_CodingRate_t CodingRate_Value = CR1_5;
uint16_t Frequencia_Value = 0;

void LoRA_PopUp::BT_BAND_UP_Callback() {
	switch (Bandwich_Value) {
	case BANDWICH_125:
		Bandwich_Value = BANDWICH_250;
		break;
	case BANDWICH_250:
		Bandwich_Value = BANDWICH_500;
		break;
	case BANDWICH_500:
		Bandwich_Value = BANDWICH_125;
		break;
	default:
		Bandwich_Value = BANDWICH_500;
		break;
	}
}
void LoRA_PopUp::BT_BAND_DOWN_Callback() {
	switch (Bandwich_Value) {
	case BANDWICH_125:
		Bandwich_Value = BANDWICH_500;
		break;
	case BANDWICH_250:
		Bandwich_Value = BANDWICH_125;
		break;
	case BANDWICH_500:
		Bandwich_Value = BANDWICH_250;
		break;
	default:
		Bandwich_Value = BANDWICH_125;
		break;
	}
}
void LoRA_PopUp::BT_SF_UP_Callback() {
	switch (SpreadFactor_Value) {
	case SF_6:
		SpreadFactor_Value = SF_7;
		break;
	case SF_7:
		SpreadFactor_Value = SF_8;
		break;
	case SF_8:
		SpreadFactor_Value = SF_9;
		break;
	case SF_9:
		SpreadFactor_Value = SF_10;
		break;
	case SF_10:
		SpreadFactor_Value = SF_11;
		break;
	case SF_11:
		SpreadFactor_Value = SF_12;
		break;
	case SF_12:
		SpreadFactor_Value = SF_6;
		break;
	default:
		SpreadFactor_Value = SF_12;
		break;
	}
}
void LoRA_PopUp::BT_SF_DOWN_Callback() {
	switch (SpreadFactor_Value) {
	case SF_6:
		SpreadFactor_Value = SF_12;
		break;
	case SF_7:
		SpreadFactor_Value = SF_6;
		break;
	case SF_8:
		SpreadFactor_Value = SF_7;
		break;
	case SF_9:
		SpreadFactor_Value = SF_8;
		break;
	case SF_10:
		SpreadFactor_Value = SF_9;
		break;
	case SF_11:
		SpreadFactor_Value = SF_10;
		break;
	case SF_12:
		SpreadFactor_Value = SF_11;
		break;
	default:
		SpreadFactor_Value = SF_6;
		break;
	}
}
void LoRA_PopUp::BT_CR_UP_Callback() {
	switch (CodingRate_Value) {
	case CR1_5:
		CodingRate_Value = CR1_6;
		break;
	case CR1_6:
		CodingRate_Value = CR1_7;
		break;
	case CR1_7:
		CodingRate_Value = CR1_8;
		break;
	case CR1_8:
		CodingRate_Value = CR1_5;
		break;
	default:
		CodingRate_Value = CR1_5;
		break;
	}
}
void LoRA_PopUp::BT_CR_DOWN_Callback() {
	switch (CodingRate_Value) {
	case CR1_5:
		CodingRate_Value = CR1_8;
		break;
	case CR1_6:
		CodingRate_Value = CR1_5;
		break;
	case CR1_7:
		CodingRate_Value = CR1_6;
		break;
	case CR1_8:
		CodingRate_Value = CR1_7;
		break;
	default:
		CodingRate_Value = CR1_8;
		break;
	}
}

void LoRA_PopUp::updateTick(void) {
#ifndef SIMULATOR
	if (LoRa_Config.isVisible() == false) {
		LoRa_FlagConfig = 0;
		Bandwich_Value = (LoRa_Bandwich_t) PAGE_LORA_Bandwich;
		SpreadFactor_Value = (LoRa_SpreadFactor_t) PAGE_LORA_Spread_Factor;
		CodingRate_Value = (LoRa_CodingRate_t) PAGE_LORA_Coding_Rate;
		Frequencia_Value = PAGE_LORA_Frequencia;
	} else
		LoRa_FlagConfig = 1;

	Unicode::snprintf(RSSIBuffer, RSSI_SIZE, "%u", (uint8_t) PAGE_LORA_RSSI);
	RSSI.invalidate();

	setIcon_LoRa((LoRa_Status_t) PAGE_DRIVER_LoRa_State);

	Unicode::snprintf(VERSIONBuffer, VERSION_SIZE, "%u.%u.%u",
			(uint8_t) (PAGE_LORA_Version / 10000),
			(uint8_t) ((PAGE_LORA_Version / 100) % 100),
			(uint8_t) (PAGE_LORA_Version % 100));
	VERSION.invalidate();

	Unicode::snprintf(DATA_RateBuffer, DATA_RATE_SIZE, "%u",
			(uint8_t) PAGE_LORA_Data_Rate);
	DATA_Rate.invalidate();

	Unicode::snprintf(USER_IDBuffer, USER_ID_SIZE, "%08u",
			(uint16_t) PAGE_LORA_User_ID);
	USER_ID.invalidate();

	Unicode::snprintf(BANDWIDTHBuffer, BANDWIDTH_SIZE, "%u",
			125 * ((uint8_t) pow(2.0, (double) Bandwich_Value)));
	BANDWIDTH.invalidate();

	Unicode::snprintf(SPREAD_FACTORBuffer, SPREAD_FACTOR_SIZE, "%u",
			SpreadFactor_Value);
	SPREAD_FACTOR.invalidate();

	Unicode::snprintf(CODING_RATEBuffer, CODING_RATE_SIZE, "%u",
			4 + CodingRate_Value);
	CODING_RATE.invalidate();

	Unicode::snprintf(FREQUENCIABuffer, FREQUENCIA_SIZE, "%u",
			Frequencia_Value);
	FREQUENCIA.invalidate();
#endif
}

void LoRA_PopUp::setIcon_LoRa(LoRa_Status_t LoRa_Status) {
	switch (LoRa_Status) {
	case LoRa_ON:
		STATE.setBitmap(touchgfx::Bitmap(BITMAP_LORA_OFF_ID));
		STATE.invalidate();
		break;
	case LoRa_OFF:
		STATE.setBitmap(touchgfx::Bitmap(BITMAP_LORA_ON_ID));
		STATE.invalidate();
		break;
	default:
		break;
	}
}

void LoRA_PopUp::FREQUENCIA_Callback(int value) {
	Frequencia_Value = value;
}

void LoRA_PopUp::initialize() {
	LoRA_PopUpBase::initialize();
}

void LoRA_PopUp::LoRa_Config_Begin() {
	BT_CR_DOWN.setXY(289, 143);
	BT_CR_DOWN.setVisible(true);
	BT_CR_DOWN.clearFadeAnimationEndedAction();
	BT_CR_DOWN.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	BT_CR_UP.setXY(288, 121);
	BT_CR_UP.setVisible(true);
	BT_CR_UP.clearFadeAnimationEndedAction();
	BT_CR_UP.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	BT_SF_DOWN.setXY(203, 112);
	BT_SF_DOWN.setVisible(true);
	BT_SF_DOWN.clearFadeAnimationEndedAction();
	BT_SF_DOWN.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	BT_SF_UP.setXY(202, 90);
	BT_SF_UP.setVisible(true);
	BT_SF_UP.clearFadeAnimationEndedAction();
	BT_SF_UP.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	BT_BAND_DOWN.setXY(286, 81);
	BT_BAND_DOWN.setVisible(true);
	BT_BAND_DOWN.clearFadeAnimationEndedAction();
	BT_BAND_DOWN.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	BT_BAND_UP.setXY(285, 59);
	BT_BAND_UP.setVisible(true);
	BT_BAND_UP.clearFadeAnimationEndedAction();
	BT_BAND_UP.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	LoRa_Config.setVisible(true);
	LoRa_Config.clearFadeAnimationEndedAction();
	LoRa_Config.startFadeAnimation(255, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	SLIDER_FREQ.setXY(480, 175);
	SLIDER_FREQ.setValue(Frequencia_Value);
	SLIDER_FREQ.clearMoveAnimationEndedAction();
	SLIDER_FREQ.startMoveAnimation(211, 175, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
}

void LoRA_PopUp::LoRa_Config_End() {
	BT_CR_DOWN.setXY(289, 143);
	BT_CR_DOWN.clearFadeAnimationEndedAction();
	BT_CR_DOWN.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);
	BT_CR_DOWN.clearMoveAnimationEndedAction();
	BT_CR_DOWN.startMoveAnimation(289, 272, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	BT_CR_UP.setXY(288, 121);
	BT_CR_UP.clearFadeAnimationEndedAction();
	BT_CR_UP.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);
	BT_CR_UP.clearMoveAnimationEndedAction();
	BT_CR_UP.startMoveAnimation(288, -17, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	BT_SF_DOWN.setXY(203, 112);
	BT_SF_DOWN.clearFadeAnimationEndedAction();
	BT_SF_DOWN.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);
	BT_SF_DOWN.clearMoveAnimationEndedAction();
	BT_SF_DOWN.startMoveAnimation(203, 272, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	BT_SF_UP.setXY(202, 90);
	BT_SF_UP.clearFadeAnimationEndedAction();
	BT_SF_UP.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);
	BT_SF_UP.clearMoveAnimationEndedAction();
	BT_SF_UP.startMoveAnimation(202, -17, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	BT_BAND_DOWN.setXY(286, 81);
	BT_BAND_DOWN.clearFadeAnimationEndedAction();
	BT_BAND_DOWN.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);
	BT_BAND_DOWN.clearMoveAnimationEndedAction();
	BT_BAND_DOWN.startMoveAnimation(286, 272, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	BT_BAND_UP.setXY(285, 59);
	BT_BAND_UP.clearFadeAnimationEndedAction();
	BT_BAND_UP.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);
	BT_BAND_UP.clearMoveAnimationEndedAction();
	BT_BAND_UP.startMoveAnimation(285, -17, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	LoRa_Config.clearFadeAnimationEndedAction();
	LoRa_Config.startFadeAnimation(0, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn);

	SLIDER_FREQ.setXY(211, 175);
	SLIDER_FREQ.clearMoveAnimationEndedAction();
	SLIDER_FREQ.startMoveAnimation(480, 175, TIME_TRANSITION_LoRa,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
}
void LoRA_PopUp::LoRa_Config_Set_Position() {
	BT_CR_DOWN.setXY(289, 143);
	BT_CR_DOWN.setVisible(false);

	BT_CR_UP.setXY(288, 121);
	BT_CR_UP.setVisible(false);

	BT_SF_DOWN.setXY(203, 112);
	BT_SF_DOWN.setVisible(false);

	BT_SF_UP.setXY(202, 90);
	BT_SF_UP.setVisible(false);

	BT_BAND_DOWN.setXY(286, 81);
	BT_BAND_DOWN.setVisible(false);

	BT_BAND_UP.setXY(285, 59);
	BT_BAND_UP.setVisible(false);

	LoRa_Config.setVisible(false);
}
