/*
 * main.c
 *
 *  Created on : Mar 28, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafrawy
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"

#include "../LIBRARY/AVR_REG.h"
#include "../MCAL/DIO_int.h"

#include "../HAL/Seven_Segment_int.h"

#include <util\delay.h>

int main(void)
{
	SEV_enuInit();

	while (1)
	{
		SEV_enuDisplayNumber(9);
		//SEV_enuSetCommonPin();
		_delay_ms (1000);

		SEV_enuDisplayNumber(5);
		//SEV_enuSetCommonPin();
		_delay_ms (1000);

		SEV_enuStopSevSeg();
		_delay_ms (1000);
	}
	return 0;
}
