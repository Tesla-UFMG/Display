#ifndef DEBUGVIEW_HPP
#define DEBUGVIEW_HPP

#include <gui_generated/debug_screen/DEBUGViewBase.hpp>
#include <gui/debug_screen/DEBUGPresenter.hpp>

#ifndef _LORA_STATUS_T
#define _LORA_STATUS_T
typedef enum
{
	LoRa_ON,
	LoRa_OFF
} LoRa_Status_t;

#endif

class DEBUGView: public DEBUGViewBase {
public:
	DEBUGView();
	virtual ~DEBUGView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();
	virtual void TransitionBegin_Debug();
	virtual void TransitionEnd_Debug();
	virtual void LORA_Begin();
	virtual void LORA_End();
	virtual void Telemetry_PopUp_Begin();
	virtual void Telemetry_PopUp_End();
	virtual void Datalogger_PopUp_Begin();
	virtual void Datalogger_PopUp_End();
	virtual void BMS_PopUp_Begin();
	virtual void BMS_PopUp_End();
	virtual void ECU_PopUp_Begin();
	virtual void ECU_PopUp_End();
	virtual void updateTick(void);
	void setIcon_LoRa(LoRa_Status_t LoRa_Status);
	void setIcon_PopUp(uint8_t Flag_Value);

protected:
};

#endif // DEBUGVIEW_HPP
