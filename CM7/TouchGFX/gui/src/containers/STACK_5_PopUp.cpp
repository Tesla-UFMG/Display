#include <gui/containers/STACK_5_PopUp.hpp>
#include <images/BitmapDatabase.hpp>
#ifndef SIMULATOR
#include "FDCAN_map.h"
#endif

STACK_5_PopUp::STACK_5_PopUp() {

}

void STACK_5_PopUp::initialize() {
	STACK_5_PopUpBase::initialize();
}

void STACK_5_PopUp::updateTick(void) {
#ifndef SIMULATOR

	Unicode::snprintf(Tensao_CELL_1Buffer, TENSAO_CELL_1_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_1 / 100,
			(uint8_t) PAGE_STACK_5_CELL_1 % 100);
	Tensao_CELL_1.invalidate();

	Unicode::snprintf(Tensao_CELL_2Buffer, TENSAO_CELL_2_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_2 / 100,
			(uint8_t) PAGE_STACK_5_CELL_2 % 100);
	Tensao_CELL_2.invalidate();

	Unicode::snprintf(Tensao_CELL_3Buffer, TENSAO_CELL_3_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_3 / 100,
			(uint8_t) PAGE_STACK_5_CELL_3 % 100);
	Tensao_CELL_3.invalidate();

	Unicode::snprintf(Tensao_CELL_4Buffer, TENSAO_CELL_4_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_4 / 100,
			(uint8_t) PAGE_STACK_5_CELL_4 % 100);
	Tensao_CELL_4.invalidate();

	Unicode::snprintf(Tensao_CELL_5Buffer, TENSAO_CELL_5_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_5 / 100,
			(uint8_t) PAGE_STACK_5_CELL_5 % 100);
	Tensao_CELL_5.invalidate();

	Unicode::snprintf(Tensao_CELL_6Buffer, TENSAO_CELL_6_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_6 / 100,
			(uint8_t) PAGE_STACK_5_CELL_6 % 100);
	Tensao_CELL_6.invalidate();

	Unicode::snprintf(Tensao_CELL_7Buffer, TENSAO_CELL_7_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_7 / 100,
			(uint8_t) PAGE_STACK_5_CELL_7 % 100);
	Tensao_CELL_7.invalidate();

	Unicode::snprintf(Tensao_CELL_8Buffer, TENSAO_CELL_8_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_8 / 100,
			(uint8_t) PAGE_STACK_5_CELL_8 % 100);
	Tensao_CELL_8.invalidate();

	Unicode::snprintf(Tensao_CELL_9Buffer, TENSAO_CELL_9_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_9 / 100,
			(uint8_t) PAGE_STACK_5_CELL_9 % 100);
	Tensao_CELL_9.invalidate();

	Unicode::snprintf(Tensao_CELL_10Buffer, TENSAO_CELL_10_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_10 / 100,
			(uint8_t) PAGE_STACK_5_CELL_10 % 100);
	Tensao_CELL_10.invalidate();

	Unicode::snprintf(Tensao_CELL_11Buffer, TENSAO_CELL_11_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_11 / 100,
			(uint8_t) PAGE_STACK_5_CELL_11 % 100);
	Tensao_CELL_11.invalidate();

	Unicode::snprintf(Tensao_CELL_12Buffer, TENSAO_CELL_12_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_12 / 100,
			(uint8_t) PAGE_STACK_5_CELL_12 % 100);
	Tensao_CELL_12.invalidate();

	Unicode::snprintf(Tensao_CELL_13Buffer, TENSAO_CELL_13_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_13 / 100,
			(uint8_t) PAGE_STACK_5_CELL_13 % 100);
	Tensao_CELL_13.invalidate();

	Unicode::snprintf(Tensao_CELL_14Buffer, TENSAO_CELL_14_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_14 / 100,
			(uint8_t) PAGE_STACK_5_CELL_14 % 100);
	Tensao_CELL_14.invalidate();

	Unicode::snprintf(Tensao_CELL_15Buffer, TENSAO_CELL_15_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_15 / 100,
			(uint8_t) PAGE_STACK_5_CELL_15 % 100);
	Tensao_CELL_15.invalidate();

	Unicode::snprintf(Tensao_CELL_16Buffer, TENSAO_CELL_16_SIZE, "%u.%02u",
			(uint8_t) PAGE_STACK_5_CELL_16 / 100,
			(uint8_t) PAGE_STACK_5_CELL_16 % 100);
	Tensao_CELL_16.invalidate();

#endif
}

