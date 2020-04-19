/*
 * Seven_Segment_int.h
 *
 *  Created on : Mar 28, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafrawy
 */

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuInit.                                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Setting All Seven segments Pins output and turned off.**/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuInit(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuDisplayNumber.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Displayed Number.                                     **/
/**	Functionality   : Displaying a specific Number to Seven Segment.        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuDisplayNumber(u8 Copy_u8Number);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuSetCommonPin.                                  **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling the Common Pin to Seven Segment.             **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuSetCommonPin(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuStopCommonPin.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Disabling the Common Pin to Seven Segment.            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuStopCommonPin(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuStopSevSeg.                                    **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Turning off Seven Segment.                            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuStopSevSeg(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
#endif /* SEVEN_SEGMENT_INT_H_ */
