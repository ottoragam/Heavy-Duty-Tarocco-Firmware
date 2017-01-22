/*******************************************************************************
* File Name: vhigh.c  
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
#include "vhigh.h"

static vhigh_BACKUP_STRUCT  vhigh_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: vhigh_Sleep
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
*  \snippet vhigh_SUT.c usage_vhigh_Sleep_Wakeup
*******************************************************************************/
void vhigh_Sleep(void)
{
    #if defined(vhigh__PC)
        vhigh_backup.pcState = vhigh_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            vhigh_backup.usbState = vhigh_CR1_REG;
            vhigh_USB_POWER_REG |= vhigh_USBIO_ENTER_SLEEP;
            vhigh_CR1_REG &= vhigh_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(vhigh__SIO)
        vhigh_backup.sioState = vhigh_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        vhigh_SIO_REG &= (uint32)(~vhigh_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: vhigh_Wakeup
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
*  Refer to vhigh_Sleep() for an example usage.
*******************************************************************************/
void vhigh_Wakeup(void)
{
    #if defined(vhigh__PC)
        vhigh_PC = vhigh_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            vhigh_USB_POWER_REG &= vhigh_USBIO_EXIT_SLEEP_PH1;
            vhigh_CR1_REG = vhigh_backup.usbState;
            vhigh_USB_POWER_REG &= vhigh_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(vhigh__SIO)
        vhigh_SIO_REG = vhigh_backup.sioState;
    #endif
}


/* [] END OF FILE */
