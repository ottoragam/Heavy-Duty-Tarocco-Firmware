/*******************************************************************************
* File Name: uhigh.h  
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

#if !defined(CY_PINS_uhigh_ALIASES_H) /* Pins uhigh_ALIASES_H */
#define CY_PINS_uhigh_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define uhigh_0			(uhigh__0__PC)
#define uhigh_0_PS		(uhigh__0__PS)
#define uhigh_0_PC		(uhigh__0__PC)
#define uhigh_0_DR		(uhigh__0__DR)
#define uhigh_0_SHIFT	(uhigh__0__SHIFT)
#define uhigh_0_INTR	((uint16)((uint16)0x0003u << (uhigh__0__SHIFT*2u)))

#define uhigh_INTR_ALL	 ((uint16)(uhigh_0_INTR))


#endif /* End Pins uhigh_ALIASES_H */


/* [] END OF FILE */
