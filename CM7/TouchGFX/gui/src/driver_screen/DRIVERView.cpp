#include <gui/driver_screen/DRIVERView.hpp>
#include <images/BitmapDatabase.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif
extern bool bottom_state;

#define TIME_TRANSITION 15U

bool DRIVE_page_Interlock = false;

DRIVERView::DRIVERView() {
}

void DRIVERView::setupScreen() {
	DRIVERViewBase::setupScreen();
}

void DRIVERView::tearDownScreen() {
	DRIVERViewBase::tearDownScreen();
}

void DRIVERView::TransitionEnd_Driver() {
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(255, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DRIVERView::TransitionBegin_Driver() {
	CHARGE_Progress.updateValue(100, 45);

	POTENCIMETRO_gauge.updateValue(0, 45);

	FRONTGROUND.setAlpha(255);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);

	DRIVE_page_Interlock = true;
}

void DRIVERView::LORA_Begin() {
	LORA_PopUp.setVisible(true);
	LORA_PopUp.invalidate();

	BOTTON_lora.setVisible(true);
	BOTTON_lora.invalidate();

	LORA_PopUp.clearMoveAnimationEndedAction();
	LORA_PopUp.startMoveAnimation(85, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DRIVERView::LORA_End() {
	BOTTON_lora.setVisible(false);
	BOTTON_lora.invalidate();

	LORA_PopUp.clearMoveAnimationEndedAction();
	LORA_PopUp.startMoveAnimation(480, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DRIVERView::updateTick(void) {
#ifndef SIMULATOR
	BACKGROUND.invalidate();
	if (bottom_state && !DRIVE_page_Interlock)
		application().gotoCONTROLScreenNoTransition();
	else if (!bottom_state)
		DRIVE_page_Interlock = false;

	POTENCIMETRO_gauge.setValue(PAGE_DRIVER_Potencia);

	CHARGE_Progress.setValue(100 - PAGE_DRIVER_Charge);

	Unicode::snprintf(VELOCIMETRO_digitalBuffer, VELOCIMETRO_DIGITAL_SIZE,
			"%02u", (uint8_t) PAGE_DRIVER_Velocidade % 100);
	VELOCIMETRO_digital.invalidate();

	Unicode::snprintf(charge_percentBuffer, CHARGE_PERCENT_SIZE, "%u",
			(uint8_t) PAGE_DRIVER_Charge);
	charge_percent.invalidate();

	Unicode::snprintf(hodometroBuffer, HODOMETRO_SIZE, "%u.%02u",
			(uint8_t) PAGE_DRIVER_Hodometro / 100,
			(uint8_t) PAGE_DRIVER_Hodometro % 100);
	hodometro.invalidate();

	Unicode::snprintf(torqueBuffer, TORQUE_SIZE, "%u",
			(uint8_t) PAGE_DRIVER_Torque);
	torque.invalidate();

	Unicode::snprintf(brake_biasBuffer, BRAKE_BIAS_SIZE, "%u",
			(uint8_t) PAGE_DRIVER_Brake_Bias);
	brake_bias.invalidate();

	Unicode::snprintf(tensao_minBuffer, TENSAO_MIN_SIZE, "%u.%02u",
			(uint8_t) PAGE_DRIVER_Tensao_Min / 100,
			(uint8_t) PAGE_DRIVER_Tensao_Min % 100);
	tensao_min.invalidate();

	Unicode::snprintf(temp_maxBuffer, TEMP_MAX_SIZE, "%u.%01u",
			(uint8_t) PAGE_DRIVER_Temp_Max / 10,
			(uint8_t) PAGE_DRIVER_Temp_Max % 10);
	temp_max.invalidate();

	setIcon_LoRa((LoRa_Status_t) PAGE_DRIVER_LoRa_State);

	setIcon_Modo((Modo_t) PAGE_DRIVER_Modo);

	setIcon_PopUp(PAGE_DRIVER_PopUp);

	LORA_PopUp.updateTick();
#endif
}

void DRIVERView::setIcon_LoRa(LoRa_Status_t LoRa_Status) {
	switch (LoRa_Status) {
	case LoRa_ON:
		ICON_LoRa.setXY(441, 15);
		ICON_LoRa.setBitmap(touchgfx::Bitmap(BITMAP_LORA_OFF_ID));
		ICON_LoRa.invalidate();
		break;
	case LoRa_OFF:
		ICON_LoRa.setXY(441, 15);
		ICON_LoRa.setBitmap(touchgfx::Bitmap(BITMAP_LORA_ON_ID));
		ICON_LoRa.invalidate();
		break;
	default:
		break;
	}
}

void DRIVERView::setIcon_Modo(Modo_t Flag_Modo) {
	switch (Flag_Modo) {
	case MODO_Error:
		ICON_Modo.setXY(443, 55);
		ICON_Modo.setBitmap(touchgfx::Bitmap(BITMAP_MODO_ERRO_ID));
		ICON_Modo.invalidate();
		break;
	case MODO_Enduro:
		ICON_Modo.setXY(436, 55);
		ICON_Modo.setBitmap(touchgfx::Bitmap(BITMAP_MODO_ENDURO_ID));
		ICON_Modo.invalidate();
		break;
	case MODO_Aceleracao:
		ICON_Modo.setXY(438, 56);
		ICON_Modo.setBitmap(touchgfx::Bitmap(BITMAP_MODO_ACELERACAO_ID));
		ICON_Modo.invalidate();
		break;
	case MODO_SkidPad:
		ICON_Modo.setXY(436, 55);
		ICON_Modo.setBitmap(touchgfx::Bitmap(BITMAP_MODO_SKIDPAD_ID));
		ICON_Modo.invalidate();
		break;
	case MODO_Autocross:
		ICON_Modo.setXY(436, 55);
		ICON_Modo.setBitmap(touchgfx::Bitmap(BITMAP_MODO_AUTOCROSS_ID));
		ICON_Modo.invalidate();
		break;
	default:
		break;
	}
}

void DRIVERView::setIcon_PopUp(uint8_t Flag_Value) {
	switch (Flag_Value) {
	case 0:
		PopUp.setXY(279, 236);
		PopUp.setVisible(false);
		PopUp.invalidate();
		break;
	case 1:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_CAN_OFF_1_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 2:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_2_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 3:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_1_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 4:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_1_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 5:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_2_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 6:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_3_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 7:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_1_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 8:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_2_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 9:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_3_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 10:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_4_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 11:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_5_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 12:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_6_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 13:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_7_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 14:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_8_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 15:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_9_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 16:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_10_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 17:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_11_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 18:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_12_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 19:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_13_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 20:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_14_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 21:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ALERT_INV_15_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 22:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_1_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 23:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_2_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 24:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_3_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 25:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_4_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 26:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_5_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 27:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_6_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 28:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_7_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 29:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_8_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 30:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_9_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 31:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_10_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 32:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_11_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 33:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_12_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 34:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_13_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 35:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_14_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 36:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_15_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 37:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_16_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 38:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_17_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 39:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_18_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 40:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_19_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 41:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_20_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 42:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_21_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 43:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_22_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 44:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_23_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 45:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_24_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 46:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_25_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 47:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_26_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 48:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_27_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 49:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_INV_28_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 50:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_4_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 51:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_5_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	case 52:
		PopUp.setXY(279, 236);
		PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ERROR_6_ID));
		PopUp.setVisible(true);
		PopUp.invalidate();
		break;
	default:
		break;
	}
}
