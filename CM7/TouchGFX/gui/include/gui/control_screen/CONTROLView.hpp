#ifndef CONTROLVIEW_HPP
#define CONTROLVIEW_HPP

#include <gui_generated/control_screen/CONTROLViewBase.hpp>
#include <gui/control_screen/CONTROLPresenter.hpp>

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

class CONTROLView: public CONTROLViewBase {
public:
	CONTROLView();
	virtual ~CONTROLView() {
	}
	virtual void setupScreen();
	virtual void tearDownScreen();
	virtual void TransitionBegin_Control();
	virtual void TransitionEnd_Control();
	virtual void LORA_Begin();
	virtual void LORA_End();
	virtual void updateTick(void);
	void setIcon_LoRa(LoRa_Status_t LoRa_Status);
	void setIcon_Modo(Modo_t Flag_Modo);
	void setIcon_PopUp(uint8_t Flag_Value);

protected:
};

#endif // CONTROLVIEW_HPP
