/*******************************************************************************
* File Name: VPWM_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "VPWM.h"

static VPWM_BACKUP_STRUCT VPWM_backup;


/*******************************************************************************
* Function Name: VPWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void VPWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: VPWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void VPWM_Sleep(void)
{
    if(0u != (VPWM_BLOCK_CONTROL_REG & VPWM_MASK))
    {
        VPWM_backup.enableState = 1u;
    }
    else
    {
        VPWM_backup.enableState = 0u;
    }

    VPWM_Stop();
    VPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: VPWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void VPWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: VPWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void VPWM_Wakeup(void)
{
    VPWM_RestoreConfig();

    if(0u != VPWM_backup.enableState)
    {
        VPWM_Enable();
    }
}


/* [] END OF FILE */
