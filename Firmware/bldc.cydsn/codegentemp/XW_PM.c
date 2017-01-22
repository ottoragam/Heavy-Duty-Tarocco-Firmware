/*******************************************************************************
* File Name: XW.c  
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
#include "XW.h"

static XW_BACKUP_STRUCT  XW_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: XW_Sleep
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
*  \snippet XW_SUT.c usage_XW_Sleep_Wakeup
*******************************************************************************/
void XW_Sleep(void)
{
    #if defined(XW__PC)
        XW_backup.pcState = XW_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            XW_backup.usbState = XW_CR1_REG;
            XW_USB_POWER_REG |= XW_USBIO_ENTER_SLEEP;
            XW_CR1_REG &= XW_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(XW__SIO)
        XW_backup.sioState = XW_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        XW_SIO_REG &= (uint32)(~XW_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: XW_Wakeup
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
*  Refer to XW_Sleep() for an example usage.
*******************************************************************************/
void XW_Wakeup(void)
{
    #if defined(XW__PC)
        XW_PC = XW_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            XW_USB_POWER_REG &= XW_USBIO_EXIT_SLEEP_PH1;
            XW_CR1_REG = XW_backup.usbState;
            XW_USB_POWER_REG &= XW_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(XW__SIO)
        XW_SIO_REG = XW_backup.sioState;
    #endif
}


/* [] END OF FILE */
