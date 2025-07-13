#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR

#include "main.h"
#include "cmsis_os2.h"
#include "FDCAN.h"

bool bottom_state = false;
uint32_t VALUE = 90;

#endif

Model::Model() :
		modelListener(0) {
}

void Model::tick() {
#ifndef SIMULATOR
	if (HAL_GPIO_ReadPin(botao_GPIO_Port, botao_Pin) || 
		HAL_GPIO_ReadPin(CHANGE_SCREEN_PIN_GPIO_Port, CHANGE_SCREEN_PIN_Pin))
		bottom_state = true;
	else
		bottom_state = false;
#endif
	modelListener->updateTick();
}
