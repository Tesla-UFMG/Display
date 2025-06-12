#ifndef LORA_POPUP_HPP
#define LORA_POPUP_HPP

#include <gui_generated/containers/LoRA_PopUpBase.hpp>

#ifndef _LORA_STATUS_T
#define _LORA_STATUS_T
typedef enum
{
	LoRa_ON,
	LoRa_OFF
} LoRa_Status_t;

#endif

class LoRA_PopUp : public LoRA_PopUpBase
{
public:
    LoRA_PopUp();
    virtual ~LoRA_PopUp() {}
    virtual void updateTick(void);
    virtual void LoRa_Config_Begin();
    virtual void LoRa_Config_End();
    virtual void LoRa_Config_Set_Position();
    void setIcon_LoRa(LoRa_Status_t LoRa_Status);
    void BT_BAND_UP_Callback();
    void BT_BAND_DOWN_Callback();
    void BT_SF_UP_Callback();
    void BT_SF_DOWN_Callback();
    void BT_CR_UP_Callback();
    void BT_CR_DOWN_Callback();
    void FREQUENCIA_Callback(int value);

    virtual void initialize();
protected:
};

#endif // LORA_POPUP_HPP
