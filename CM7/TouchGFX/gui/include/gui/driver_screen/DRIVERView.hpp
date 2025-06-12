#ifndef DRIVERVIEW_HPP
#define DRIVERVIEW_HPP

#include <gui_generated/driver_screen/DRIVERViewBase.hpp>
#include <gui/driver_screen/DRIVERPresenter.hpp>

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

class DRIVERView: public DRIVERViewBase {
public:
	DRIVERView();
	virtual ~DRIVERView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();
	virtual void TransitionBegin_Driver();
	virtual void TransitionEnd_Driver();
	virtual void LORA_Begin();
	virtual void LORA_End();
	virtual void updateTick(void);
	void setIcon_LoRa(LoRa_Status_t LoRa_Status);
	void setIcon_Modo(Modo_t Flag_Modo);
	void setIcon_PopUp(uint8_t Flag_Value);
protected:
};

#endif // DRIVERVIEW_HPP
