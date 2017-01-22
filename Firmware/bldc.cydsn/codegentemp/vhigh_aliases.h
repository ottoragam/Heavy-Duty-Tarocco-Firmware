/*******************************************************************************
* File Name: vhigh.h  
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

#if !defined(CY_PINS_vhigh_ALIASES_H) /* Pins vhigh_ALIASES_H */
#define CY_PINS_vhigh_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define vhigh_0			(vhigh__0__PC)
#define vhigh_0_PS		(vhigh__0__PS)
#define vhigh_0_PC		(vhigh__0__PC)
#define vhigh_0_DR		(vhigh__0__DR)
#define vhigh_0_SHIFT	(vhigh__0__SHIFT)
#define vhigh_0_INTR	((uint16)((uint16)0x0003u << (vhigh__0__SHIFT*2u)))

#define vhigh_INTR_ALL	 ((uint16)(vhigh_0_INTR))


#endif /* End Pins vhigh_ALIASES_H */


/* [] END OF FILE */
