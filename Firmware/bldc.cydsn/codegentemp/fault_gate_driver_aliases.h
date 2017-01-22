/*******************************************************************************
* File Name: fault_gate_driver.h  
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

#if !defined(CY_PINS_fault_gate_driver_ALIASES_H) /* Pins fault_gate_driver_ALIASES_H */
#define CY_PINS_fault_gate_driver_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define fault_gate_driver_0			(fault_gate_driver__0__PC)
#define fault_gate_driver_0_PS		(fault_gate_driver__0__PS)
#define fault_gate_driver_0_PC		(fault_gate_driver__0__PC)
#define fault_gate_driver_0_DR		(fault_gate_driver__0__DR)
#define fault_gate_driver_0_SHIFT	(fault_gate_driver__0__SHIFT)
#define fault_gate_driver_0_INTR	((uint16)((uint16)0x0003u << (fault_gate_driver__0__SHIFT*2u)))

#define fault_gate_driver_INTR_ALL	 ((uint16)(fault_gate_driver_0_INTR))


#endif /* End Pins fault_gate_driver_ALIASES_H */


/* [] END OF FILE */
