/*******************************************************************************
* File Name: WPWM_PM.c
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

#include "WPWM.h"

static WPWM_BACKUP_STRUCT WPWM_backup;


/*******************************************************************************
* Function Name: WPWM_SaveConfig
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
void WPWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: WPWM_Sleep
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
void WPWM_Sleep(void)
{
    if(0u != (WPWM_BLOCK_CONTROL_REG & WPWM_MASK))
    {
        WPWM_backup.enableState = 1u;
    }
    else
    {
        WPWM_backup.enableState = 0u;
    }

    WPWM_Stop();
    WPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: WPWM_RestoreConfig
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
void WPWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: WPWM_Wakeup
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
void WPWM_Wakeup(void)
{
    WPWM_RestoreConfig();

    if(0u != WPWM_backup.enableState)
    {
        WPWM_Enable();
    }
}


/* [] END OF FILE */
