#include <gui/containers/Telemetry_PopUp.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif

Telemetry_PopUp::Telemetry_PopUp() {

}

void Telemetry_PopUp::initialize() {
	Telemetry_PopUpBase::initialize();
}

void Telemetry_PopUp::updateTick(void) {
#ifndef SIMULATOR
	Unicode::snprintf(DEBUG_0Buffer, DEBUG_0_SIZE, "%u",
			(uint16_t) PAGE_BOARD_Telemetria_DEBUG_0);
	DEBUG_0.invalidate();

	Unicode::snprintf(DEBUG_1Buffer, DEBUG_1_SIZE, "%u",
			(uint16_t) PAGE_BOARD_Telemetria_DEBUG_1);
	DEBUG_1.invalidate();

	Unicode::snprintf(DEBUG_2Buffer, DEBUG_2_SIZE, "%u",
			(uint16_t) PAGE_BOARD_Telemetria_DEBUG_2);
	DEBUG_2.invalidate();
#endif
}
