/*******************************************************************************
* File Name: wlow.c  
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
#include "wlow.h"

static wlow_BACKUP_STRUCT  wlow_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: wlow_Sleep
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
*  \snippet wlow_SUT.c usage_wlow_Sleep_Wakeup
*******************************************************************************/
void wlow_Sleep(void)
{
    #if defined(wlow__PC)
        wlow_backup.pcState = wlow_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            wlow_backup.usbState = wlow_CR1_REG;
            wlow_USB_POWER_REG |= wlow_USBIO_ENTER_SLEEP;
            wlow_CR1_REG &= wlow_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(wlow__SIO)
        wlow_backup.sioState = wlow_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        wlow_SIO_REG &= (uint32)(~wlow_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: wlow_Wakeup
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
*  Refer to wlow_Sleep() for an example usage.
*******************************************************************************/
void wlow_Wakeup(void)
{
    #if defined(wlow__PC)
        wlow_PC = wlow_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            wlow_USB_POWER_REG &= wlow_USBIO_EXIT_SLEEP_PH1;
            wlow_CR1_REG = wlow_backup.usbState;
            wlow_USB_POWER_REG &= wlow_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(wlow__SIO)
        wlow_SIO_REG = wlow_backup.sioState;
    #endif
}


/* [] END OF FILE */
