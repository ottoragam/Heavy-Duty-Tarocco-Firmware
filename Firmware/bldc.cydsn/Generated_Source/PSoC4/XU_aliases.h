/*******************************************************************************
* File Name: XU.h  
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

#if !defined(CY_PINS_XU_ALIASES_H) /* Pins XU_ALIASES_H */
#define CY_PINS_XU_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define XU_0			(XU__0__PC)
#define XU_0_PS		(XU__0__PS)
#define XU_0_PC		(XU__0__PC)
#define XU_0_DR		(XU__0__DR)
#define XU_0_SHIFT	(XU__0__SHIFT)
#define XU_0_INTR	((uint16)((uint16)0x0003u << (XU__0__SHIFT*2u)))

#define XU_INTR_ALL	 ((uint16)(XU_0_INTR))


#endif /* End Pins XU_ALIASES_H */


/* [] END OF FILE */
