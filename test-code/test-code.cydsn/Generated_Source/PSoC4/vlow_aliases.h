/*******************************************************************************
* File Name: vlow.h  
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

#if !defined(CY_PINS_vlow_ALIASES_H) /* Pins vlow_ALIASES_H */
#define CY_PINS_vlow_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define vlow_0			(vlow__0__PC)
#define vlow_0_PS		(vlow__0__PS)
#define vlow_0_PC		(vlow__0__PC)
#define vlow_0_DR		(vlow__0__DR)
#define vlow_0_SHIFT	(vlow__0__SHIFT)
#define vlow_0_INTR	((uint16)((uint16)0x0003u << (vlow__0__SHIFT*2u)))

#define vlow_INTR_ALL	 ((uint16)(vlow_0_INTR))


#endif /* End Pins vlow_ALIASES_H */


/* [] END OF FILE */
