/*******************************************************************************
* File Name: wlow.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_wlow_ALIASES_H) /* Pins wlow_ALIASES_H */
#define CY_PINS_wlow_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define wlow_0			(wlow__0__PC)
#define wlow_0_PS		(wlow__0__PS)
#define wlow_0_PC		(wlow__0__PC)
#define wlow_0_DR		(wlow__0__DR)
#define wlow_0_SHIFT	(wlow__0__SHIFT)
#define wlow_0_INTR	((uint16)((uint16)0x0003u << (wlow__0__SHIFT*2u)))

#define wlow_INTR_ALL	 ((uint16)(wlow_0_INTR))


#endif /* End Pins wlow_ALIASES_H */


/* [] END OF FILE */
