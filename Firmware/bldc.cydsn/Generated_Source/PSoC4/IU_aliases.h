/*******************************************************************************
* File Name: IU.h  
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

#if !defined(CY_PINS_IU_ALIASES_H) /* Pins IU_ALIASES_H */
#define CY_PINS_IU_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IU_0			(IU__0__PC)
#define IU_0_PS		(IU__0__PS)
#define IU_0_PC		(IU__0__PC)
#define IU_0_DR		(IU__0__DR)
#define IU_0_SHIFT	(IU__0__SHIFT)
#define IU_0_INTR	((uint16)((uint16)0x0003u << (IU__0__SHIFT*2u)))

#define IU_INTR_ALL	 ((uint16)(IU_0_INTR))


#endif /* End Pins IU_ALIASES_H */


/* [] END OF FILE */
