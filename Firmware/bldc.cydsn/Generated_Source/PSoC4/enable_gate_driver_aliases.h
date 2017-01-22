/*******************************************************************************
* File Name: enable_gate_driver.h  
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

#if !defined(CY_PINS_enable_gate_driver_ALIASES_H) /* Pins enable_gate_driver_ALIASES_H */
#define CY_PINS_enable_gate_driver_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define enable_gate_driver_0			(enable_gate_driver__0__PC)
#define enable_gate_driver_0_PS		(enable_gate_driver__0__PS)
#define enable_gate_driver_0_PC		(enable_gate_driver__0__PC)
#define enable_gate_driver_0_DR		(enable_gate_driver__0__DR)
#define enable_gate_driver_0_SHIFT	(enable_gate_driver__0__SHIFT)
#define enable_gate_driver_0_INTR	((uint16)((uint16)0x0003u << (enable_gate_driver__0__SHIFT*2u)))

#define enable_gate_driver_INTR_ALL	 ((uint16)(enable_gate_driver_0_INTR))


#endif /* End Pins enable_gate_driver_ALIASES_H */


/* [] END OF FILE */
