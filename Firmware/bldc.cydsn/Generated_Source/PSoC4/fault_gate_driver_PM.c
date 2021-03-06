/*******************************************************************************
* File Name: fault_gate_driver.c  
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
#include "fault_gate_driver.h"

static fault_gate_driver_BACKUP_STRUCT  fault_gate_driver_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: fault_gate_driver_Sleep
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
*  \snippet fault_gate_driver_SUT.c usage_fault_gate_driver_Sleep_Wakeup
*******************************************************************************/
void fault_gate_driver_Sleep(void)
{
    #if defined(fault_gate_driver__PC)
        fault_gate_driver_backup.pcState = fault_gate_driver_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            fault_gate_driver_backup.usbState = fault_gate_driver_CR1_REG;
            fault_gate_driver_USB_POWER_REG |= fault_gate_driver_USBIO_ENTER_SLEEP;
            fault_gate_driver_CR1_REG &= fault_gate_driver_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(fault_gate_driver__SIO)
        fault_gate_driver_backup.sioState = fault_gate_driver_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        fault_gate_driver_SIO_REG &= (uint32)(~fault_gate_driver_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: fault_gate_driver_Wakeup
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
*  Refer to fault_gate_driver_Sleep() for an example usage.
*******************************************************************************/
void fault_gate_driver_Wakeup(void)
{
    #if defined(fault_gate_driver__PC)
        fault_gate_driver_PC = fault_gate_driver_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            fault_gate_driver_USB_POWER_REG &= fault_gate_driver_USBIO_EXIT_SLEEP_PH1;
            fault_gate_driver_CR1_REG = fault_gate_driver_backup.usbState;
            fault_gate_driver_USB_POWER_REG &= fault_gate_driver_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(fault_gate_driver__SIO)
        fault_gate_driver_SIO_REG = fault_gate_driver_backup.sioState;
    #endif
}


/* [] END OF FILE */
