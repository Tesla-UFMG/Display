#include <gui/debug_screen/DEBUGView.hpp>
#include <images/BitmapDatabase.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif

extern bool bottom_state;
#define TIME_TRANSITION 15U
bool DEBUG_page_Interlock = false;

DEBUGView::DEBUGView() {
}

void DEBUGView::setupScreen() {
	DEBUGViewBase::setupScreen();
}

void DEBUGView::tearDownScreen() {
	DEBUGViewBase::tearDownScreen();
}

void DEBUGView::TransitionBegin_Debug() {
	FRONTGROUND.setAlpha(255);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);

	DEBUG_page_Interlock = true;
}

void DEBUGView::TransitionEnd_Debug() {
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(255, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::Telemetry_PopUp_Begin() {
	PopUp_Telemetry.setVisible(true);
	PopUp_Telemetry.invalidate();

	BOTTON_PopUp_Telemetry.setVisible(true);
	BOTTON_PopUp_Telemetry.invalidate();

	PopUp_Telemetry.clearMoveAnimationEndedAction();
	PopUp_Telemetry.startMoveAnimation(71, 84, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::Telemetry_PopUp_End() {
	BOTTON_PopUp_Telemetry.setVisible(false);
	BOTTON_PopUp_Telemetry.invalidate();

	PopUp_Telemetry.clearMoveAnimationEndedAction();
	PopUp_Telemetry.startMoveAnimation(71, -103, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::Datalogger_PopUp_Begin() {
	PopUp_Datalogger.setVisible(true);
	PopUp_Datalogger.invalidate();

	BOTTON_PopUp_Datalogger.setVisible(true);
	BOTTON_PopUp_Datalogger.invalidate();

	PopUp_Datalogger.clearMoveAnimationEndedAction();
	PopUp_Datalogger.startMoveAnimation(71, 84, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::Datalogger_PopUp_End() {
	BOTTON_PopUp_Datalogger.setVisible(false);
	BOTTON_PopUp_Datalogger.invalidate();

	PopUp_Datalogger.clearMoveAnimationEndedAction();
	PopUp_Datalogger.startMoveAnimation(71, -103, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::BMS_PopUp_Begin() {
	PopUp_BMS.setVisible(true);
	PopUp_BMS.invalidate();

	BOTTON_PopUp_BMS.setVisible(true);
	BOTTON_PopUp_BMS.invalidate();

	PopUp_BMS.clearMoveAnimationEndedAction();
	PopUp_BMS.startMoveAnimation(71, 84, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::BMS_PopUp_End() {
	BOTTON_PopUp_BMS.setVisible(false);
	BOTTON_PopUp_BMS.invalidate();

	PopUp_BMS.clearMoveAnimationEndedAction();
	PopUp_BMS.startMoveAnimation(71, 272, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::ECU_PopUp_Begin() {
	PopUp_ECU.setVisible(true);
	PopUp_ECU.invalidate();

	BOTTON_PopUp_ECU.setVisible(true);
	BOTTON_PopUp_ECU.invalidate();

	PopUp_ECU.clearMoveAnimationEndedAction();
	PopUp_ECU.startMoveAnimation(71, 84, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::ECU_PopUp_End() {
	BOTTON_PopUp_ECU.setVisible(false);
	BOTTON_PopUp_ECU.invalidate();

	PopUp_ECU.clearMoveAnimationEndedAction();
	PopUp_ECU.startMoveAnimation(71, 272, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void DEBUGView::LORA_Begin() {
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

void DEBUGView::LORA_End() {
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

void DEBUGView::updateTick(void) {
#ifndef SIMULATOR
	BACKGROUND.invalidate();
	if (bottom_state && !DEBUG_page_Interlock)
		application().gotoDRIVERScreenNoTransition();
	else if (!bottom_state)
		DEBUG_page_Interlock = false;

	Unicode::snprintf(DataRate_TelemetriaBuffer, DATARATE_TELEMETRIA_SIZE, "%u",
			(uint8_t) PAGE_DEBUG_Telemetria);

	Unicode::snprintf(DataRate_DataloggerBuffer, DATARATE_DATALOGGER_SIZE, "%u",
			(uint8_t) PAGE_DEBUG_Datalogger);

	Unicode::snprintf(DataRate_BMSBuffer, DATARATE_BMS_SIZE, "%u",
			(uint8_t) PAGE_DEBUG_BMS);

	Unicode::snprintf(DataRate_ECUBuffer, DATARATE_ECU_SIZE, "%u",
			(uint8_t) PAGE_DEBUG_ECU);

	Unicode::snprintf(Beacon_LeapBuffer, BEACON_LEAP_SIZE, "%u",
			(uint8_t) PAGE_DEBUG_Beacon);

	if (PAGE_DEBUG_State_ECU)
		ICON_ECU.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_ON_ID));
	else
		ICON_ECU.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_OFF_ID));
	ICON_ECU.invalidate();

	if (PAGE_DEBUG_State_BMS)
		ICON_BMS.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_ON_ID));
	else
		ICON_BMS.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_OFF_ID));
	ICON_BMS.invalidate();

	if (PAGE_DEBUG_State_Telemetry)
		ICON_Telemetria.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_ON_ID));
	else
		ICON_Telemetria.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_OFF_ID));
	ICON_Telemetria.invalidate();

	if (PAGE_DEBUG_State_Datalogger)
		ICON_Datalogger.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_ON_ID));
	else
		ICON_Datalogger.setBitmap(touchgfx::Bitmap(BITMAP_CONEXAO_OFF_ID));
	ICON_Datalogger.invalidate();

	setIcon_LoRa((LoRa_Status_t) PAGE_CONTROL_LoRa_State);

	setIcon_PopUp(PAGE_CONTROL_PopUp);

	LORA_PopUp.updateTick();

	PopUp_Telemetry.updateTick();

	PopUp_Datalogger.updateTick();

	PopUp_BMS.updateTick();

	PopUp_ECU.updateTick();
#endif
}

void DEBUGView::setIcon_LoRa(LoRa_Status_t LoRa_Status) {
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

void DEBUGView::setIcon_PopUp(uint8_t Flag_Value) {
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
