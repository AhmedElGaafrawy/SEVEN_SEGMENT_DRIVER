/*
 * Seven_Segement_prog.c
 *
 *  Created on : Mar 28, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafrawy
 */
/*****************************************************************************/
/**                                                                         **/
/**                         Libraries Inclusion                             **/
/**             standard types  -  bit math  -  error states                **/
/*****************************************************************************/
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
/*****************************************************************************/
/**                                                                         **/
/**                       AVR atmega 32 Library                             **/
/**                                                                         **/
/*****************************************************************************/
#include "../LIBRARY/AVR_REG.h"
/*****************************************************************************/
/**                                                                         **/
/**                      HAL Libraries Inclusion                            **/
/**           Seven Segment private  -  Seven Segment configuration         **/
/*****************************************************************************/
#include "../MCAL/DIO_priv.h"
#include "../MCAL/DIO_config.h"
#include "../MCAL/DIO_int.h"
/*****************************************************************************/
/**                                                                         **/
/**                      HAL Libraries Inclusion                            **/
/**           Seven Segment private  -  Seven Segment configuration         **/
/*****************************************************************************/
#include "Seven_Segment_priv.h"
#include "Seven_Segment_config.h"
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuInit.                                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Setting All Seven segments Pins output and turned off.**/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuInit(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK ;
	DIO_enuSetPinDirection(A_PORT,A_PIN,PIN_OUTPUT);
	DIO_enuSetPinDirection(B_PORT,B_PIN,PIN_OUTPUT);
	DIO_enuSetPinDirection(C_PORT,C_PIN,PIN_OUTPUT);
	DIO_enuSetPinDirection(D_PORT,D_PIN,PIN_OUTPUT);
	DIO_enuSetPinDirection(E_PORT,E_PIN,PIN_OUTPUT);
	DIO_enuSetPinDirection(F_PORT,F_PIN,PIN_OUTPUT);
	DIO_enuSetPinDirection(G_PORT,G_PIN,PIN_OUTPUT);

#if DOT_STATE == CONNECTED
	DIO_enuSetPinDirection(DOT_PORT,DOT_PIN,PIN_OUTPUT);
#endif

#if CMN_STATE == CONNECTED
	DIO_enuSetPinDirection(CMN_PORT,CMN_PIN,PIN_OUTPUT);
#endif
	error_enuState = ES_OK ;
	return error_enuState ;
}
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
ERROR_STATES SEV_enuDisplayNumber(u8 Copy_u8Number)
{
	ERROR_STATES error_enuState = ES_NOT_OK ;
#if SEV_TYPE == CMN_CATHODE
	DIO_enuSetPinValue(A_PORT,A_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT0)) );
	DIO_enuSetPinValue(B_PORT,B_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT1)) );
	DIO_enuSetPinValue(C_PORT,C_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT2)) );
	DIO_enuSetPinValue(D_PORT,D_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT3)) );
	DIO_enuSetPinValue(E_PORT,E_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT4)) );
	DIO_enuSetPinValue(F_PORT,F_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT5)) );
	DIO_enuSetPinValue(G_PORT,G_PIN,!!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT6)) );
	error_enuState = ES_OK ;

#elif SEV_TYPE == CMN_ANODE

	DIO_enuSetPinValue(A_PORT,A_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT0)) );
	DIO_enuSetPinValue(B_PORT,B_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT1)) );
	DIO_enuSetPinValue(C_PORT,C_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT2)) );
	DIO_enuSetPinValue(D_PORT,D_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT3)) );
	DIO_enuSetPinValue(E_PORT,E_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT4)) );
	DIO_enuSetPinValue(F_PORT,F_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT5)) );
	DIO_enuSetPinValue(G_PORT,G_PIN,!((seg[Copy_u8Number]) & (ACTIVE_BIT<<BIT6)) );
	error_enuState = ES_OK ;
#else
#error"Selection of Seven Segment Type must be Common Cathode or Anode"
#endif

#if (SEV_TYPE == CMN_CATHODE && DOT_STATE == CONNECTED)
	DIO_enuSetPinValue(DOT_PORT,DOT_PIN,CONNECTED);
#elif (SEV_TYPE == CMN_ANODE && DOT_STATE == CONNECTED)
	DIO_enuSetPinValue(DOT_PORT,DOT_PIN,! CONNECTED);
#else
#warning "DOT Pin at Seven Segment is not Connected"
#endif
	return error_enuState ;
}
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
ERROR_STATES SEV_enuSetCommonPin(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK ;
#if (SEV_TYPE == CMN_CATHODE )
	DIO_enuSetPinValue(CMN_PORT,CMN_PIN,PIN_LOW);
	error_enuState = ES_OK ;
#elif (SEV_TYPE == CMN_ANODE )
	DIO_enuSetPinValue(CMN_PORT,CMN_PIN,PIN_HIGH);
	error_enuState = ES_OK ;
#else
#error"Selection of Seven Segment Type must be Common Cathode or Anode"
#endif
	return error_enuState ;
}
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
ERROR_STATES SEV_enuStopCommonPin(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK ;
#if (SEV_TYPE == CMN_CATHODE )
	DIO_enuSetPinValue(CMN_PORT,CMN_PIN,PIN_HIGH);
	error_enuState = ES_OK ;
#elif (SEV_TYPE == CMN_ANODE )
	DIO_enuSetPinValue(CMN_PORT,CMN_PIN,PIN_LOW);
	error_enuState = ES_OK ;
#else
#error"Selection of Seven Segment Type must be Common Cathode or Anode"
#endif
	return error_enuState ;
}
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
ERROR_STATES SEV_enuStopSevSeg(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK ;
#if SEV_TYPE == CMN_CATHODE
	DIO_enuSetPinValue(A_PORT,A_PIN,PIN_LOW);
	DIO_enuSetPinValue(B_PORT,B_PIN,PIN_LOW);
	DIO_enuSetPinValue(C_PORT,C_PIN,PIN_LOW);
	DIO_enuSetPinValue(D_PORT,D_PIN,PIN_LOW);
	DIO_enuSetPinValue(E_PORT,E_PIN,PIN_LOW);
	DIO_enuSetPinValue(F_PORT,F_PIN,PIN_LOW);
	DIO_enuSetPinValue(G_PORT,G_PIN,PIN_LOW);
	error_enuState = ES_OK ;

#elif SEV_TYPE == CMN_ANODE

	DIO_enuSetPinValue(A_PORT,A_PIN,PIN_HIGH);
	DIO_enuSetPinValue(B_PORT,B_PIN,PIN_HIGH);
	DIO_enuSetPinValue(C_PORT,C_PIN,PIN_HIGH);
	DIO_enuSetPinValue(D_PORT,D_PIN,PIN_HIGH);
	DIO_enuSetPinValue(E_PORT,E_PIN,PIN_HIGH);
	DIO_enuSetPinValue(F_PORT,F_PIN,PIN_HIGH);
	DIO_enuSetPinValue(G_PORT,G_PIN,PIN_HIGH);
	error_enuState = ES_OK ;

#else
#error"Selection of Seven Segment Type must be Common Cathode or Anode"
#endif

#if (SEV_TYPE == CMN_CATHODE && DOT_STATE == CONNECTED)
	DIO_enuSetPinValue(DOT_PORT,DOT_PIN,PIN_LOW);
#elif (SEV_TYPE == CMN_ANODE && DOT_STATE == CONNECTED)
	DIO_enuSetPinValue(DOT_PORT,DOT_PIN,PIN_HIGH);
#else
#warning "DOT Pin at Seven Segment is not Connected"
#endif
	return error_enuState ;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
