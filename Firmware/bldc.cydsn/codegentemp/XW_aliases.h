/*******************************************************************************
* File Name: XW.h  
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

#if !defined(CY_PINS_XW_ALIASES_H) /* Pins XW_ALIASES_H */
#define CY_PINS_XW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define XW_0			(XW__0__PC)
#define XW_0_PS		(XW__0__PS)
#define XW_0_PC		(XW__0__PC)
#define XW_0_DR		(XW__0__DR)
#define XW_0_SHIFT	(XW__0__SHIFT)
#define XW_0_INTR	((uint16)((uint16)0x0003u << (XW__0__SHIFT*2u)))

#define XW_INTR_ALL	 ((uint16)(XW_0_INTR))


#endif /* End Pins XW_ALIASES_H */


/* [] END OF FILE */
