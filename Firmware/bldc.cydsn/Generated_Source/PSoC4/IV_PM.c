/*******************************************************************************
* File Name: IV.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "IV.h"

static IV_BACKUP_STRUCT  IV_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: IV_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet IV_SUT.c usage_IV_Sleep_Wakeup
*******************************************************************************/
void IV_Sleep(void)
{
    #if defined(IV__PC)
        IV_backup.pcState = IV_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            IV_backup.usbState = IV_CR1_REG;
            IV_USB_POWER_REG |= IV_USBIO_ENTER_SLEEP;
            IV_CR1_REG &= IV_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(IV__SIO)
        IV_backup.sioState = IV_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        IV_SIO_REG &= (uint32)(~IV_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: IV_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to IV_Sleep() for an example usage.
*******************************************************************************/
void IV_Wakeup(void)
{
    #if defined(IV__PC)
        IV_PC = IV_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            IV_USB_POWER_REG &= IV_USBIO_EXIT_SLEEP_PH1;
            IV_CR1_REG = IV_backup.usbState;
            IV_USB_POWER_REG &= IV_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(IV__SIO)
        IV_SIO_REG = IV_backup.sioState;
    #endif
}


/* [] END OF FILE */
