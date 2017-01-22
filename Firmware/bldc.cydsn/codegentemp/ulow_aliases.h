/*******************************************************************************
* File Name: ulow.h  
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

#if !defined(CY_PINS_ulow_ALIASES_H) /* Pins ulow_ALIASES_H */
#define CY_PINS_ulow_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ulow_0			(ulow__0__PC)
#define ulow_0_PS		(ulow__0__PS)
#define ulow_0_PC		(ulow__0__PC)
#define ulow_0_DR		(ulow__0__DR)
#define ulow_0_SHIFT	(ulow__0__SHIFT)
#define ulow_0_INTR	((uint16)((uint16)0x0003u << (ulow__0__SHIFT*2u)))

#define ulow_INTR_ALL	 ((uint16)(ulow_0_INTR))


#endif /* End Pins ulow_ALIASES_H */


/* [] END OF FILE */
