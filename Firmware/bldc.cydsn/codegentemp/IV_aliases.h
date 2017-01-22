/*******************************************************************************
* File Name: IV.h  
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

#if !defined(CY_PINS_IV_ALIASES_H) /* Pins IV_ALIASES_H */
#define CY_PINS_IV_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IV_0			(IV__0__PC)
#define IV_0_PS		(IV__0__PS)
#define IV_0_PC		(IV__0__PC)
#define IV_0_DR		(IV__0__DR)
#define IV_0_SHIFT	(IV__0__SHIFT)
#define IV_0_INTR	((uint16)((uint16)0x0003u << (IV__0__SHIFT*2u)))

#define IV_INTR_ALL	 ((uint16)(IV_0_INTR))


#endif /* End Pins IV_ALIASES_H */


/* [] END OF FILE */
