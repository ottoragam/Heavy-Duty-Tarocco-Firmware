/*******************************************************************************
* File Name: XU.c  
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
#include "XU.h"

static XU_BACKUP_STRUCT  XU_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: XU_Sleep
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
*  \snippet XU_SUT.c usage_XU_Sleep_Wakeup
*******************************************************************************/
void XU_Sleep(void)
{
    #if defined(XU__PC)
        XU_backup.pcState = XU_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            XU_backup.usbState = XU_CR1_REG;
            XU_USB_POWER_REG |= XU_USBIO_ENTER_SLEEP;
            XU_CR1_REG &= XU_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(XU__SIO)
        XU_backup.sioState = XU_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        XU_SIO_REG &= (uint32)(~XU_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: XU_Wakeup
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
*  Refer to XU_Sleep() for an example usage.
*******************************************************************************/
void XU_Wakeup(void)
{
    #if defined(XU__PC)
        XU_PC = XU_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            XU_USB_POWER_REG &= XU_USBIO_EXIT_SLEEP_PH1;
            XU_CR1_REG = XU_backup.usbState;
            XU_USB_POWER_REG &= XU_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(XU__SIO)
        XU_SIO_REG = XU_backup.sioState;
    #endif
}


/* [] END OF FILE */
