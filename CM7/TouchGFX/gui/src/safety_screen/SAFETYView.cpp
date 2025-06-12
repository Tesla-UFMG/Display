#include <gui/safety_screen/SAFETYView.hpp>
#include <images/BitmapDatabase.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif

extern bool bottom_state;
#define TIME_TRANSITION 15U
bool SAFETY_page_Interlock = false;

SAFETYView::SAFETYView() {
}

void SAFETYView::setupScreen() {
	SAFETYViewBase::setupScreen();
}

void SAFETYView::tearDownScreen() {
	SAFETYViewBase::tearDownScreen();
}

void SAFETYView::TransitionBegin_Safety() {
	FRONTGROUND.setAlpha(255);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);

	CHARGE_Progress.updateValue(100, 45);

	SAFETY_page_Interlock = true;
}

void SAFETYView::TransitionEnd_Safety() {
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(255, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_1_Begin() {

	STACK_1.setVisible(true);
	STACK_1.invalidate();

	BOTTON_stack_1.setVisible(true);
	BOTTON_stack_1.invalidate();

	STACK_1.clearMoveAnimationEndedAction();
	STACK_1.startMoveAnimation(0, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_1_End() {
	BOTTON_stack_1.setVisible(false);
	BOTTON_stack_1.invalidate();

	STACK_1.clearMoveAnimationEndedAction();
	STACK_1.startMoveAnimation(400, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_2_Begin() {
	STACK_2.setVisible(true);
	STACK_2.invalidate();

	BOTTON_stack_2.setVisible(true);
	BOTTON_stack_2.invalidate();

	STACK_2.clearMoveAnimationEndedAction();
	STACK_2.startMoveAnimation(0, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_2_End() {
	BOTTON_stack_2.setVisible(false);
	BOTTON_stack_2.invalidate();

	STACK_2.clearMoveAnimationEndedAction();
	STACK_2.startMoveAnimation(400, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_3_Begin() {
	STACK_3.setVisible(true);
	STACK_3.invalidate();

	BOTTON_stack_3.setVisible(true);
	BOTTON_stack_3.invalidate();

	STACK_3.clearMoveAnimationEndedAction();
	STACK_3.startMoveAnimation(0, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_3_End() {
	BOTTON_stack_3.setVisible(false);
	BOTTON_stack_3.invalidate();

	STACK_3.clearMoveAnimationEndedAction();
	STACK_3.startMoveAnimation(400, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_4_Begin() {
	STACK_4.setVisible(true);
	STACK_4.invalidate();

	BOTTON_stack_4.setVisible(true);
	BOTTON_stack_4.invalidate();

	STACK_4.clearMoveAnimationEndedAction();
	STACK_4.startMoveAnimation(0, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_4_End() {
	BOTTON_stack_4.setVisible(false);
	BOTTON_stack_4.invalidate();

	STACK_4.clearMoveAnimationEndedAction();
	STACK_4.startMoveAnimation(400, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_5_Begin() {
	STACK_5.setVisible(true);
	STACK_5.invalidate();

	BOTTON_stack_5.setVisible(true);
	BOTTON_stack_5.invalidate();

	STACK_5.clearMoveAnimationEndedAction();
	STACK_5.startMoveAnimation(0, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_5_End() {
	BOTTON_stack_5.setVisible(false);
	BOTTON_stack_5.invalidate();

	STACK_5.clearMoveAnimationEndedAction();
	STACK_5.startMoveAnimation(400, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_6_Begin() {
	STACK_6.setVisible(true);
	STACK_6.invalidate();

	BOTTON_stack_6.setVisible(true);
	BOTTON_stack_6.invalidate();

	STACK_6.clearMoveAnimationEndedAction();
	STACK_6.startMoveAnimation(0, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(200, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::STACK_6_End() {
	BOTTON_stack_6.setVisible(false);
	BOTTON_stack_6.invalidate();

	STACK_6.clearMoveAnimationEndedAction();
	STACK_6.startMoveAnimation(400, 0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);
	FRONTGROUND.clearFadeAnimationEndedAction();
	FRONTGROUND.startFadeAnimation(0, TIME_TRANSITION,
			touchgfx::EasingEquations::linearEaseIn);
}

void SAFETYView::LORA_Begin() {
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

void SAFETYView::LORA_End() {
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

void SAFETYView::updateTick(void) {
#ifndef SIMULATOR
	BACKGROUND.invalidate();
	if (bottom_state && !SAFETY_page_Interlock)
		application().gotoDEBUGScreenNoTransition();
	else if (!bottom_state)
		SAFETY_page_Interlock = false;

	CHARGE_Progress.setValue(100 - PAGE_SAFETY_Charge);

	Unicode::snprintf(temp_maxBuffer, TEMP_MAX_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Temp_Max / 10,
			(uint8_t) PAGE_SAFETY_Temp_Max % 10);
	temp_max.invalidate();

	Unicode::snprintf(tensao_maxBuffer, TENSAO_MAX_SIZE, "%u.%02u",
			(uint8_t) PAGE_SAFETY_Tensao_Max / 100,
			(uint8_t) PAGE_SAFETY_Tensao_Max % 100);
	tensao_max.invalidate();

	Unicode::snprintf(tensao_minBuffer, TENSAO_MIN_SIZE, "%u.%02u",
			(uint8_t) PAGE_SAFETY_Tensao_Min / 100,
			(uint8_t) PAGE_SAFETY_Tensao_Min % 100);
	tensao_min.invalidate();

	Unicode::snprintf(charge_percentBuffer, CHARGE_PERCENT_SIZE, "%u",
			(uint8_t) PAGE_SAFETY_Charge);
	charge_percent.invalidate();

	Unicode::snprintf(STACK_6_textBuffer, STACK_6_TEXT_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Stack_6 / 10,
			(uint8_t) PAGE_SAFETY_Stack_6 % 10);
	STACK_6_text.invalidate();

	Unicode::snprintf(STACK_5_textBuffer, STACK_5_TEXT_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Stack_5 / 10,
			(uint8_t) PAGE_SAFETY_Stack_5 % 10);
	STACK_5_text.invalidate();

	Unicode::snprintf(STACK_4_textBuffer, STACK_4_TEXT_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Stack_4 / 10,
			(uint8_t) PAGE_SAFETY_Stack_4 % 10);
	STACK_4_text.invalidate();

	Unicode::snprintf(STACK_3_textBuffer, STACK_3_TEXT_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Stack_3 / 10,
			(uint8_t) PAGE_SAFETY_Stack_3 % 10);
	STACK_3_text.invalidate();

	Unicode::snprintf(STACK_2_textBuffer, STACK_2_TEXT_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Stack_2 / 10,
			(uint8_t) PAGE_SAFETY_Stack_2 % 10);
	STACK_2_text.invalidate();

	Unicode::snprintf(STACK_1_textBuffer, STACK_1_TEXT_SIZE, "%u.%01u",
			(uint8_t) PAGE_SAFETY_Stack_1 / 10,
			(uint8_t) PAGE_SAFETY_Stack_1 % 10);
	STACK_1_text.invalidate();

	Unicode::snprintf(SENSOR_4_textBuffer, SENSOR_4_TEXT_SIZE, "%i",
			(int16_t) PAGE_SAFETY_Corrente_4 - 130);
	SENSOR_4_text.invalidate();

	Unicode::snprintf(SENSOR_3_textBuffer, SENSOR_3_TEXT_SIZE, "%i",
			(int16_t) PAGE_SAFETY_Corrente_3 - 130);
	SENSOR_3_text.invalidate();

	Unicode::snprintf(SENSOR_2_textBuffer, SENSOR_2_TEXT_SIZE, "%i",
			(int16_t) PAGE_SAFETY_Corrente_2 - 130);
	SENSOR_2_text.invalidate();

	Unicode::snprintf(SENSOR_1_textBuffer, SENSOR_1_TEXT_SIZE, "%i",
			(int16_t) PAGE_SAFETY_Corrente_1 - 130);
	SENSOR_1_text.invalidate();

	if (((int16_t) PAGE_SAFETY_Corrente_4 - 130) == 0)
		SENSOR_4_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_4_ID));
	else if (((int16_t) PAGE_SAFETY_Corrente_4 - 130) > 0)
		SENSOR_4_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_4_ID));
	else
		SENSOR_4_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_BACK_4_ID));

	if (((int16_t) PAGE_SAFETY_Corrente_3 - 130) == 0)
		SENSOR_3_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_3_ID));
	else if (((int16_t) PAGE_SAFETY_Corrente_3 - 130) > 0)
		SENSOR_3_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_3_ID));
	else
		SENSOR_3_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_BACK_3_ID));

	if (((int16_t) PAGE_SAFETY_Corrente_2 - 130) == 0)
		SENSOR_2_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_2_ID));
	else if (((int16_t) PAGE_SAFETY_Corrente_2 - 130) > 0)
		SENSOR_2_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_2_ID));
	else
		SENSOR_2_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_BACK_2_ID));

	if (((int16_t) PAGE_SAFETY_Corrente_1 - 130) == 0)
		SENSOR_1_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_1_ID));
	else if (((int16_t) PAGE_SAFETY_Corrente_1 - 130) > 0)
		SENSOR_1_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_1_ID));
	else
		SENSOR_1_icon.setBitmap(
				touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_BACK_1_ID));

	setIcon_LoRa((LoRa_Status_t) PAGE_SAFETY_LoRa_State);

	setIcon_Modo((Modo_t)PAGE_SAFETY_Modo);

	setIcon_PopUp(PAGE_SAFETY_PopUp);

	LORA_PopUp.updateTick();

	if (PAGE_SAFETY_Air) {
		ICON_Air.setXY(433, 97);
		ICON_Air.setBitmap(touchgfx::Bitmap(BITMAP_AIR_ABERTO_ID));
	} else {
		ICON_Air.setXY(438, 97);
		ICON_Air.setBitmap(touchgfx::Bitmap(BITMAP_AIR_FECHADO_ID));
	}
	ICON_Air.invalidate();

	STACK_1.updateTick();

	STACK_2.updateTick();

	STACK_3.updateTick();

	STACK_4.updateTick();

	STACK_5.updateTick();

	STACK_6.updateTick();
#endif
}

void SAFETYView::setIcon_LoRa(LoRa_Status_t LoRa_Status) {
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

void SAFETYView::setIcon_Modo(Modo_t Flag_Modo) {
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

void SAFETYView::setIcon_PopUp(uint8_t Flag_Value) {
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

