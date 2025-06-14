/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/safety_screen/SAFETYViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SAFETYViewBase::SAFETYViewBase() :
    buttonCallback(this, &SAFETYViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &SAFETYViewBase::flexButtonCallbackHandler),
    interaction_Delay_DRIVER_pageCounter(0),
    interaction_Delay_CONTROL_pageCounter(0),
    interaction_Delay_DEBUG_pageCounter(0)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    BACKGROUND.setXY(0, 0);
    BACKGROUND.setBitmap(touchgfx::Bitmap(BITMAP_PAGE_SAFETY_ID));
    add(BACKGROUND);

    CHARGE_Progress.setXY(367, -1);
    CHARGE_Progress.setProgressIndicatorPosition(0, 0, 47, 236);
    CHARGE_Progress.setRange(0, 100);
    CHARGE_Progress.setBackground(touchgfx::Bitmap(BITMAP_CHARGE_PROGRESS_ID));
    CHARGE_ProgressPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    CHARGE_Progress.setPainter(CHARGE_ProgressPainter);
    CHARGE_Progress.setStart(25.4f, 0.0f);
    CHARGE_Progress.setEnd(25.5f, 237.0f);
    CHARGE_Progress.setLineWidth(50.9);
    CHARGE_Progress.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);
    CHARGE_Progress.setValue(0);
    add(CHARGE_Progress);

    PopUp.setXY(279, 236);
    PopUp.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_CAN_OFF_1_ID));
    PopUp.setVisible(false);
    add(PopUp);

    PAGE_Debug.setXY(0, 204);
    PAGE_Debug.setBitmaps(touchgfx::Bitmap(BITMAP_BOTTOM_DOWN_OFF_ID), touchgfx::Bitmap(BITMAP_BOTTOM_DOWN_ON_ID));
    PAGE_Debug.setAction(buttonCallback);
    add(PAGE_Debug);

    PAGE_Safety.setXY(0, 137);
    PAGE_Safety.setBitmaps(touchgfx::Bitmap(BITMAP_BOTTOM_MID_DOWN_ON_SELECT_ID), touchgfx::Bitmap(BITMAP_BOTTOM_MID_DOWN_OFF_SELECT_ID));
    add(PAGE_Safety);

    PAGE_Control.setXY(0, 69);
    PAGE_Control.setBitmaps(touchgfx::Bitmap(BITMAP_BOTTOM_MID_UP_OFF_ID), touchgfx::Bitmap(BITMAP_BOTTOM_MID_UP_ON_ID));
    PAGE_Control.setAction(buttonCallback);
    add(PAGE_Control);

    PAGE_Drive.setXY(0, 0);
    PAGE_Drive.setBitmaps(touchgfx::Bitmap(BITMAP_BOTTOM_UP_OFF_ID), touchgfx::Bitmap(BITMAP_BOTTOM_UP_ON_ID));
    PAGE_Drive.setAction(buttonCallback);
    add(PAGE_Drive);

    BOTTON_Stack_6.setXY(162, 183);
    BOTTON_Stack_6.setBitmaps(touchgfx::Bitmap(BITMAP_STACK_6_ID), touchgfx::Bitmap(BITMAP_STACK_6_SELECT_ID));
    BOTTON_Stack_6.setAction(buttonCallback);
    add(BOTTON_Stack_6);

    BOTTON_Stack_5.setXY(171, 111);
    BOTTON_Stack_5.setBitmaps(touchgfx::Bitmap(BITMAP_STACK_5_ID), touchgfx::Bitmap(BITMAP_STACK_5_SELECT_ID));
    BOTTON_Stack_5.setAction(buttonCallback);
    add(BOTTON_Stack_5);

    BOTTON_Stack_4.setXY(159, 37);
    BOTTON_Stack_4.setBitmaps(touchgfx::Bitmap(BITMAP_STACK_4_ID), touchgfx::Bitmap(BITMAP_STACK_4_SELECT_ID));
    BOTTON_Stack_4.setAction(buttonCallback);
    add(BOTTON_Stack_4);

    BOTTON_Stack_3.setXY(80, 183);
    BOTTON_Stack_3.setBitmaps(touchgfx::Bitmap(BITMAP_STACK_3_ID), touchgfx::Bitmap(BITMAP_STACK_3_SELECT_ID));
    BOTTON_Stack_3.setAction(buttonCallback);
    add(BOTTON_Stack_3);

    BOTTON_Stack_2.setXY(90, 111);
    BOTTON_Stack_2.setBitmaps(touchgfx::Bitmap(BITMAP_STACK_2_ID), touchgfx::Bitmap(BITMAP_STACK_2_SELECT_ID));
    BOTTON_Stack_2.setAction(buttonCallback);
    add(BOTTON_Stack_2);

    BOTTON_Stack_1.setXY(80, 38);
    BOTTON_Stack_1.setBitmaps(touchgfx::Bitmap(BITMAP_STACK_1_ID), touchgfx::Bitmap(BITMAP_STACK_1_SELECT_ID));
    BOTTON_Stack_1.setAction(buttonCallback);
    add(BOTTON_Stack_1);

    SENSOR_4_icon.setXY(254, 188);
    SENSOR_4_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_4_ID));
    add(SENSOR_4_icon);

    SENSOR_3_icon.setXY(254, 142);
    SENSOR_3_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_3_ID));
    add(SENSOR_3_icon);

    SENSOR_2_icon.setXY(254, 93);
    SENSOR_2_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_2_ID));
    add(SENSOR_2_icon);

    SENSOR_1_icon.setXY(254, 46);
    SENSOR_1_icon.setBitmap(touchgfx::Bitmap(BITMAP_SENSOR_CURRENT_FOWARD_1_ID));
    add(SENSOR_1_icon);

    temp_max.setXY(429, 214);
    temp_max.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    temp_max.setLinespacing(0);
    Unicode::snprintf(temp_maxBuffer, TEMP_MAX_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_OJ2V).getText());
    temp_max.setWildcard(temp_maxBuffer);
    temp_max.resizeToCurrentText();
    temp_max.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EYDG));
    add(temp_max);

    tensao_max.setPosition(419, 133, 61, 15);
    tensao_max.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tensao_max.setLinespacing(0);
    Unicode::snprintf(tensao_maxBuffer, TENSAO_MAX_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ZEKC).getText());
    tensao_max.setWildcard(tensao_maxBuffer);
    tensao_max.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BLM9));
    add(tensao_max);

    tensao_min.setPosition(424, 173, 55, 15);
    tensao_min.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tensao_min.setLinespacing(0);
    Unicode::snprintf(tensao_minBuffer, TENSAO_MIN_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_BQ00).getText());
    tensao_min.setWildcard(tensao_minBuffer);
    tensao_min.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MZQS));
    add(tensao_min);

    charge_percent.setPosition(303, 6, 56, 18);
    charge_percent.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    charge_percent.setLinespacing(0);
    Unicode::snprintf(charge_percentBuffer, CHARGE_PERCENT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_W5DZ).getText());
    charge_percent.setWildcard(charge_percentBuffer);
    charge_percent.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PCOB));
    add(charge_percent);

    STACK_6_text.setPosition(172, 204, 48, 15);
    STACK_6_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    STACK_6_text.setLinespacing(0);
    Unicode::snprintf(STACK_6_textBuffer, STACK_6_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_O9H5).getText());
    STACK_6_text.setWildcard(STACK_6_textBuffer);
    STACK_6_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T21J));
    add(STACK_6_text);

    STACK_5_text.setPosition(183, 133, 48, 15);
    STACK_5_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    STACK_5_text.setLinespacing(0);
    Unicode::snprintf(STACK_5_textBuffer, STACK_5_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5CES).getText());
    STACK_5_text.setWildcard(STACK_5_textBuffer);
    STACK_5_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZCMW));
    add(STACK_5_text);

    STACK_4_text.setPosition(171, 58, 48, 15);
    STACK_4_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    STACK_4_text.setLinespacing(0);
    Unicode::snprintf(STACK_4_textBuffer, STACK_4_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_RUTU).getText());
    STACK_4_text.setWildcard(STACK_4_textBuffer);
    STACK_4_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BVMV));
    add(STACK_4_text);

    STACK_3_text.setPosition(90, 204, 48, 15);
    STACK_3_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    STACK_3_text.setLinespacing(0);
    Unicode::snprintf(STACK_3_textBuffer, STACK_3_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_EYPO).getText());
    STACK_3_text.setWildcard(STACK_3_textBuffer);
    STACK_3_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CQUD));
    add(STACK_3_text);

    STACK_2_text.setPosition(100, 132, 48, 15);
    STACK_2_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    STACK_2_text.setLinespacing(0);
    Unicode::snprintf(STACK_2_textBuffer, STACK_2_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_RIPS).getText());
    STACK_2_text.setWildcard(STACK_2_textBuffer);
    STACK_2_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6AAQ));
    add(STACK_2_text);

    STACK_1_text.setPosition(90, 58, 48, 15);
    STACK_1_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    STACK_1_text.setLinespacing(0);
    Unicode::snprintf(STACK_1_textBuffer, STACK_1_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Q65U).getText());
    STACK_1_text.setWildcard(STACK_1_textBuffer);
    STACK_1_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A1MF));
    add(STACK_1_text);

    SENSOR_4_text.setPosition(282, 202, 42, 15);
    SENSOR_4_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SENSOR_4_text.setLinespacing(0);
    Unicode::snprintf(SENSOR_4_textBuffer, SENSOR_4_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_GW1J).getText());
    SENSOR_4_text.setWildcard(SENSOR_4_textBuffer);
    SENSOR_4_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EP5M));
    add(SENSOR_4_text);

    SENSOR_3_text.setPosition(282, 157, 42, 15);
    SENSOR_3_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SENSOR_3_text.setLinespacing(0);
    Unicode::snprintf(SENSOR_3_textBuffer, SENSOR_3_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_AMIJ).getText());
    SENSOR_3_text.setWildcard(SENSOR_3_textBuffer);
    SENSOR_3_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M8NZ));
    add(SENSOR_3_text);

    SENSOR_2_text.setPosition(282, 109, 42, 15);
    SENSOR_2_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SENSOR_2_text.setLinespacing(0);
    Unicode::snprintf(SENSOR_2_textBuffer, SENSOR_2_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_B351).getText());
    SENSOR_2_text.setWildcard(SENSOR_2_textBuffer);
    SENSOR_2_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XKB0));
    add(SENSOR_2_text);

    SENSOR_1_text.setPosition(282, 61, 42, 15);
    SENSOR_1_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SENSOR_1_text.setLinespacing(0);
    Unicode::snprintf(SENSOR_1_textBuffer, SENSOR_1_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IRWO).getText());
    SENSOR_1_text.setWildcard(SENSOR_1_textBuffer);
    SENSOR_1_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IWRT));
    add(SENSOR_1_text);

    ICON_Air.setXY(433, 97);
    ICON_Air.setBitmap(touchgfx::Bitmap(BITMAP_AIR_ABERTO_ID));
    add(ICON_Air);

    ICON_Modo.setXY(436, 55);
    ICON_Modo.setBitmap(touchgfx::Bitmap(BITMAP_MODO_ENDURO_ID));
    add(ICON_Modo);

    BOTTOM_Info_LoRa.setXY(420, 0);
    BOTTOM_Info_LoRa.setBitmaps(touchgfx::Bitmap(BITMAP_INFO_LORA_ID), touchgfx::Bitmap(BITMAP_INFO_LORA_SELECT_ID));
    BOTTOM_Info_LoRa.setAction(buttonCallback);
    add(BOTTOM_Info_LoRa);

    ICON_LoRa.setXY(441, 15);
    ICON_LoRa.setBitmap(touchgfx::Bitmap(BITMAP_LORA_OFF_ID));
    add(ICON_LoRa);

    FRONTGROUND.setPosition(80, 0, 400, 272);
    FRONTGROUND.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    FRONTGROUND.setAlpha(0);
    add(FRONTGROUND);

    BOTTON_stack_6.setBoxWithBorderPosition(0, 0, 408, 272);
    BOTTON_stack_6.setBorderSize(5);
    BOTTON_stack_6.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_stack_6.setAlpha(0);
    BOTTON_stack_6.setVisible(false);
    BOTTON_stack_6.setAction(flexButtonCallback);
    BOTTON_stack_6.setPosition(72, 0, 408, 272);
    add(BOTTON_stack_6);

    STACK_6.setXY(400, 0);
    STACK_6.setVisible(false);
    add(STACK_6);

    BOTTON_stack_5.setBoxWithBorderPosition(0, 0, 408, 272);
    BOTTON_stack_5.setBorderSize(5);
    BOTTON_stack_5.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_stack_5.setAlpha(0);
    BOTTON_stack_5.setVisible(false);
    BOTTON_stack_5.setAction(flexButtonCallback);
    BOTTON_stack_5.setPosition(72, 0, 408, 272);
    add(BOTTON_stack_5);

    STACK_5.setXY(400, 0);
    STACK_5.setVisible(false);
    add(STACK_5);

    BOTTON_stack_4.setBoxWithBorderPosition(0, 0, 408, 272);
    BOTTON_stack_4.setBorderSize(5);
    BOTTON_stack_4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_stack_4.setAlpha(0);
    BOTTON_stack_4.setVisible(false);
    BOTTON_stack_4.setAction(flexButtonCallback);
    BOTTON_stack_4.setPosition(72, 0, 408, 272);
    add(BOTTON_stack_4);

    STACK_4.setXY(400, 0);
    STACK_4.setVisible(false);
    add(STACK_4);

    BOTTON_stack_3.setBoxWithBorderPosition(0, 0, 408, 272);
    BOTTON_stack_3.setBorderSize(5);
    BOTTON_stack_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_stack_3.setAlpha(0);
    BOTTON_stack_3.setVisible(false);
    BOTTON_stack_3.setAction(flexButtonCallback);
    BOTTON_stack_3.setPosition(72, 0, 408, 272);
    add(BOTTON_stack_3);

    STACK_3.setXY(400, 0);
    STACK_3.setVisible(false);
    add(STACK_3);

    BOTTON_stack_2.setBoxWithBorderPosition(0, 0, 408, 272);
    BOTTON_stack_2.setBorderSize(5);
    BOTTON_stack_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_stack_2.setAlpha(0);
    BOTTON_stack_2.setVisible(false);
    BOTTON_stack_2.setAction(flexButtonCallback);
    BOTTON_stack_2.setPosition(72, 0, 408, 272);
    add(BOTTON_stack_2);

    STACK_2.setXY(400, 0);
    STACK_2.setVisible(false);
    add(STACK_2);

    BOTTON_stack_1.setBoxWithBorderPosition(0, 0, 408, 272);
    BOTTON_stack_1.setBorderSize(5);
    BOTTON_stack_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_stack_1.setAlpha(0);
    BOTTON_stack_1.setVisible(false);
    BOTTON_stack_1.setAction(flexButtonCallback);
    BOTTON_stack_1.setPosition(72, 0, 408, 272);
    add(BOTTON_stack_1);

    STACK_1.setXY(400, 0);
    STACK_1.setVisible(false);
    add(STACK_1);

    BOTTON_lora.setBoxWithBorderPosition(0, 0, 67, 272);
    BOTTON_lora.setBorderSize(5);
    BOTTON_lora.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    BOTTON_lora.setAlpha(0);
    BOTTON_lora.setVisible(false);
    BOTTON_lora.setAction(flexButtonCallback);
    BOTTON_lora.setPosition(414, 1, 67, 272);
    add(BOTTON_lora);

    LORA_PopUp.setXY(480, 0);
    LORA_PopUp.setVisible(false);
    add(LORA_PopUp);
}

SAFETYViewBase::~SAFETYViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void SAFETYViewBase::setupScreen()
{
    STACK_6.initialize();
    STACK_5.initialize();
    STACK_4.initialize();
    STACK_3.initialize();
    STACK_2.initialize();
    STACK_1.initialize();
    LORA_PopUp.initialize();
    transitionBegins();
}

void SAFETYViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &PAGE_Drive)
    {
        //Interaction_DRIVER_page_press
        //When PAGE_Drive clicked call virtual function
        //Call TransitionEnd_Safety
        TransitionEnd_Safety();
    
        //Interaction_Delay_DRIVER_page
        //When Interaction_DRIVER_page_press completed delay
        //Delay for 251 ms (15 Ticks)
        interaction_Delay_DRIVER_pageCounter = INTERACTION_DELAY_DRIVER_PAGE_DURATION;
    }
    if (&src == &PAGE_Control)
    {
        //Interaction_CONTROL_page_press
        //When PAGE_Control clicked call virtual function
        //Call TransitionEnd_Safety
        TransitionEnd_Safety();
    
        //Interaction_Delay_CONTROL_page
        //When Interaction_CONTROL_page_press completed delay
        //Delay for 251 ms (15 Ticks)
        interaction_Delay_CONTROL_pageCounter = INTERACTION_DELAY_CONTROL_PAGE_DURATION;
    }
    if (&src == &PAGE_Debug)
    {
        //Interaction_DEBUG_page_press
        //When PAGE_Debug clicked call virtual function
        //Call TransitionEnd_Safety
        TransitionEnd_Safety();
    
        //Interaction_Delay_DEBUG_page
        //When Interaction_DEBUG_page_press completed delay
        //Delay for 251 ms (15 Ticks)
        interaction_Delay_DEBUG_pageCounter = INTERACTION_DELAY_DEBUG_PAGE_DURATION;
    }
    if (&src == &BOTTON_Stack_1)
    {
        //Interaction_STACK_1_Begin
        //When BOTTON_Stack_1 clicked call virtual function
        //Call STACK_1_Begin
        STACK_1_Begin();
    }
    if (&src == &BOTTON_Stack_2)
    {
        //Interaction_STACK_2_Begin
        //When BOTTON_Stack_2 clicked call virtual function
        //Call STACK_2_Begin
        STACK_2_Begin();
    }
    if (&src == &BOTTON_Stack_3)
    {
        //Interaction_STACK_3_Begin
        //When BOTTON_Stack_3 clicked call virtual function
        //Call STACK_3_Begin
        STACK_3_Begin();
    }
    if (&src == &BOTTON_Stack_4)
    {
        //Interaction_STACK_4_begin
        //When BOTTON_Stack_4 clicked call virtual function
        //Call STACK_4_Begin
        STACK_4_Begin();
    }
    if (&src == &BOTTON_Stack_5)
    {
        //Interaction_STACK_5_Begin
        //When BOTTON_Stack_5 clicked call virtual function
        //Call STACK_5_Begin
        STACK_5_Begin();
    }
    if (&src == &BOTTOM_Info_LoRa)
    {
        //Interaction_LORA_Begin
        //When BOTTOM_Info_LoRa clicked call virtual function
        //Call LORA_Begin
        LORA_Begin();
    }
    if (&src == &BOTTON_Stack_6)
    {
        //Interaction_STACK_6_Begin
        //When BOTTON_Stack_6 clicked call virtual function
        //Call STACK_6_Begin
        STACK_6_Begin();
    }
}

void SAFETYViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &BOTTON_stack_1)
    {
        //Interaction_STACK_1_End
        //When BOTTON_stack_1 clicked call virtual function
        //Call STACK_1_End
        STACK_1_End();
    }
    if (&src == &BOTTON_stack_2)
    {
        //Interaction_STACK_2_End
        //When BOTTON_stack_2 clicked call virtual function
        //Call STACK_2_End
        STACK_2_End();
    }
    if (&src == &BOTTON_stack_3)
    {
        //Interaction_STACK_3_End
        //When BOTTON_stack_3 clicked call virtual function
        //Call STACK_3_End
        STACK_3_End();
    }
    if (&src == &BOTTON_stack_4)
    {
        //Interaction_STACK_4_End
        //When BOTTON_stack_4 clicked call virtual function
        //Call STACK_4_End
        STACK_4_End();
    }
    if (&src == &BOTTON_stack_5)
    {
        //Interaction_STACK_5_End
        //When BOTTON_stack_5 clicked call virtual function
        //Call STACK_5_End
        STACK_5_End();
    }
    if (&src == &BOTTON_lora)
    {
        //Interaction_LORA_End
        //When BOTTON_lora clicked call virtual function
        //Call LORA_End
        LORA_End();
    }
    if (&src == &BOTTON_stack_6)
    {
        //Interaction_STACK_6_End
        //When BOTTON_stack_6 clicked call virtual function
        //Call STACK_6_End
        STACK_6_End();
    }
}

void SAFETYViewBase::handleTickEvent()
{
    if (interaction_Delay_DRIVER_pageCounter > 0)
    {
        interaction_Delay_DRIVER_pageCounter--;
        if (interaction_Delay_DRIVER_pageCounter == 0)
        {
                //Interaction_Screen_DRIVER_page
                //When Interaction_Delay_DRIVER_page completed change screen to DRIVER
                //Go to DRIVER with no screen transition
                application().gotoDRIVERScreenNoTransition();
        }
    }

    if (interaction_Delay_CONTROL_pageCounter > 0)
    {
        interaction_Delay_CONTROL_pageCounter--;
        if (interaction_Delay_CONTROL_pageCounter == 0)
        {
                //Interaction_Screen_CONTROL_page
                //When Interaction_Delay_CONTROL_page completed change screen to CONTROL
                //Go to CONTROL with no screen transition
                application().gotoCONTROLScreenNoTransition();
        }
    }

    if (interaction_Delay_DEBUG_pageCounter > 0)
    {
        interaction_Delay_DEBUG_pageCounter--;
        if (interaction_Delay_DEBUG_pageCounter == 0)
        {
                //Interaction_Screen_DEBUG_page
                //When Interaction_Delay_DEBUG_page completed change screen to DEBUG
                //Go to DEBUG with no screen transition
                application().gotoDEBUGScreenNoTransition();
        }
    }
}

void SAFETYViewBase::transitionBegins()
{
    //Interaction_TransitionBegin
    //When screen transition begins call virtual function
    //Call TransitionBegin_Safety
    TransitionBegin_Safety();
}
