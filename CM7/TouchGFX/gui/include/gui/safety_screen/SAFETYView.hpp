#ifndef SAFETYVIEW_HPP
#define SAFETYVIEW_HPP

#include <gui_generated/safety_screen/SAFETYViewBase.hpp>
#include <gui/safety_screen/SAFETYPresenter.hpp>

#ifndef _LORA_STATUS_T
#define _LORA_STATUS_T
typedef enum
{
	LoRa_ON,
	LoRa_OFF
} LoRa_Status_t;

#endif

#ifndef _LORA_MODO_T
#define _LORA_MODO_T
typedef enum {
	MODO_Error, MODO_Enduro, MODO_Aceleracao, MODO_SkidPad, MODO_Autocross
} Modo_t;
#endif

class SAFETYView: public SAFETYViewBase {
public:
	SAFETYView();
	virtual ~SAFETYView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();
	virtual void TransitionBegin_Safety();
	virtual void TransitionEnd_Safety();
	virtual void STACK_1_Begin();
	virtual void STACK_1_End();
	virtual void STACK_2_Begin();
	virtual void STACK_2_End();
	virtual void STACK_3_Begin();
	virtual void STACK_3_End();
	virtual void STACK_4_Begin();
	virtual void STACK_4_End();
	virtual void STACK_5_Begin();
	virtual void STACK_5_End();
	virtual void STACK_6_Begin();
	virtual void STACK_6_End();
	virtual void LORA_Begin();
	virtual void LORA_End();
	virtual void updateTick(void);
	void setIcon_LoRa(LoRa_Status_t LoRa_Status);
	void setIcon_Modo(Modo_t Flag_Modo);
	void setIcon_PopUp(uint8_t Flag_Value);

protected:
};

#endif // SAFETYVIEW_HPP
