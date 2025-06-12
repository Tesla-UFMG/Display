#include <gui/containers/BMS_PopUp.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif

BMS_PopUp::BMS_PopUp() {

}

void BMS_PopUp::initialize() {
	BMS_PopUpBase::initialize();
}

void BMS_PopUp::updateTick(void) {
#ifndef SIMULATOR
	Unicode::snprintf(DEBUG_0Buffer, DEBUG_0_SIZE, "%u",
			(uint16_t) PAGE_BOARD_BMS_DEBUG_0);
	DEBUG_0.invalidate();

	Unicode::snprintf(DEBUG_1Buffer, DEBUG_1_SIZE, "%u",
			(uint16_t) PAGE_BOARD_BMS_DEBUG_1);
	DEBUG_1.invalidate();

	Unicode::snprintf(DEBUG_2Buffer, DEBUG_2_SIZE, "%u",
			(uint16_t) PAGE_BOARD_BMS_DEBUG_2);
	DEBUG_2.invalidate();
#endif
}
