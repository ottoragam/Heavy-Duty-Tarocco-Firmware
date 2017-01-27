/*******************************************************************************
* File Name: vlow.c  
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
#include "vlow.h"

static vlow_BACKUP_STRUCT  vlow_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: vlow_Sleep
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
*  \snippet vlow_SUT.c usage_vlow_Sleep_Wakeup
*******************************************************************************/
void vlow_Sleep(void)
{
    #if defined(vlow__PC)
        vlow_backup.pcState = vlow_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            vlow_backup.usbState = vlow_CR1_REG;
            vlow_USB_POWER_REG |= vlow_USBIO_ENTER_SLEEP;
            vlow_CR1_REG &= vlow_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(vlow__SIO)
        vlow_backup.sioState = vlow_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        vlow_SIO_REG &= (uint32)(~vlow_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: vlow_Wakeup
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
*  Refer to vlow_Sleep() for an example usage.
*******************************************************************************/
void vlow_Wakeup(void)
{
    #if defined(vlow__PC)
        vlow_PC = vlow_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            vlow_USB_POWER_REG &= vlow_USBIO_EXIT_SLEEP_PH1;
            vlow_CR1_REG = vlow_backup.usbState;
            vlow_USB_POWER_REG &= vlow_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(vlow__SIO)
        vlow_SIO_REG = vlow_backup.sioState;
    #endif
}


/* [] END OF FILE */
