#include <gui/containers/ECU_PopUp.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif

ECU_PopUp::ECU_PopUp() {

}

void ECU_PopUp::initialize() {
	ECU_PopUpBase::initialize();
}

void ECU_PopUp::updateTick(void) {
#ifndef SIMULATOR
	Unicode::snprintf(DEBUG_0Buffer, DEBUG_0_SIZE, "%u",
			(uint16_t) PAGE_BOARD_ECU_DEBUG_0);
	DEBUG_0.invalidate();

	Unicode::snprintf(DEBUG_1Buffer, DEBUG_1_SIZE, "%u",
			(uint16_t) PAGE_BOARD_ECU_DEBUG_1);
	DEBUG_1.invalidate();

	Unicode::snprintf(DEBUG_2Buffer, DEBUG_2_SIZE, "%u",
			(uint16_t) PAGE_BOARD_ECU_DEBUG_2);
	DEBUG_2.invalidate();
#endif
}
