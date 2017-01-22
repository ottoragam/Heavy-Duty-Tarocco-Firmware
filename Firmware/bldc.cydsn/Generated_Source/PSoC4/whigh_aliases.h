/*******************************************************************************
* File Name: whigh.h  
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

#if !defined(CY_PINS_whigh_ALIASES_H) /* Pins whigh_ALIASES_H */
#define CY_PINS_whigh_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define whigh_0			(whigh__0__PC)
#define whigh_0_PS		(whigh__0__PS)
#define whigh_0_PC		(whigh__0__PC)
#define whigh_0_DR		(whigh__0__DR)
#define whigh_0_SHIFT	(whigh__0__SHIFT)
#define whigh_0_INTR	((uint16)((uint16)0x0003u << (whigh__0__SHIFT*2u)))

#define whigh_INTR_ALL	 ((uint16)(whigh_0_INTR))


#endif /* End Pins whigh_ALIASES_H */


/* [] END OF FILE */
