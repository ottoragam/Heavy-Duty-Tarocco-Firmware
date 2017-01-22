/*******************************************************************************
* File Name: UPWM_PM.c
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

#include "UPWM.h"

static UPWM_BACKUP_STRUCT UPWM_backup;


/*******************************************************************************
* Function Name: UPWM_SaveConfig
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
void UPWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: UPWM_Sleep
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
void UPWM_Sleep(void)
{
    if(0u != (UPWM_BLOCK_CONTROL_REG & UPWM_MASK))
    {
        UPWM_backup.enableState = 1u;
    }
    else
    {
        UPWM_backup.enableState = 0u;
    }

    UPWM_Stop();
    UPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: UPWM_RestoreConfig
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
void UPWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: UPWM_Wakeup
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
void UPWM_Wakeup(void)
{
    UPWM_RestoreConfig();

    if(0u != UPWM_backup.enableState)
    {
        UPWM_Enable();
    }
}


/* [] END OF FILE */
