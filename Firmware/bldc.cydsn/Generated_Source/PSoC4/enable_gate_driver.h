/*******************************************************************************
* File Name: enable_gate_driver.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_enable_gate_driver_H) /* Pins enable_gate_driver_H */
#define CY_PINS_enable_gate_driver_H

#include "cytypes.h"
#include "cyfitter.h"
#include "enable_gate_driver_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} enable_gate_driver_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   enable_gate_driver_Read(void);
void    enable_gate_driver_Write(uint8 value);
uint8   enable_gate_driver_ReadDataReg(void);
#if defined(enable_gate_driver__PC) || (CY_PSOC4_4200L) 
    void    enable_gate_driver_SetDriveMode(uint8 mode);
#endif
void    enable_gate_driver_SetInterruptMode(uint16 position, uint16 mode);
uint8   enable_gate_driver_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void enable_gate_driver_Sleep(void); 
void enable_gate_driver_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(enable_gate_driver__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define enable_gate_driver_DRIVE_MODE_BITS        (3)
    #define enable_gate_driver_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - enable_gate_driver_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the enable_gate_driver_SetDriveMode() function.
         *  @{
         */
        #define enable_gate_driver_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define enable_gate_driver_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define enable_gate_driver_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define enable_gate_driver_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define enable_gate_driver_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define enable_gate_driver_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define enable_gate_driver_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define enable_gate_driver_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define enable_gate_driver_MASK               enable_gate_driver__MASK
#define enable_gate_driver_SHIFT              enable_gate_driver__SHIFT
#define enable_gate_driver_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in enable_gate_driver_SetInterruptMode() function.
     *  @{
     */
        #define enable_gate_driver_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define enable_gate_driver_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define enable_gate_driver_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define enable_gate_driver_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(enable_gate_driver__SIO)
    #define enable_gate_driver_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(enable_gate_driver__PC) && (CY_PSOC4_4200L)
    #define enable_gate_driver_USBIO_ENABLE               ((uint32)0x80000000u)
    #define enable_gate_driver_USBIO_DISABLE              ((uint32)(~enable_gate_driver_USBIO_ENABLE))
    #define enable_gate_driver_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define enable_gate_driver_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define enable_gate_driver_USBIO_ENTER_SLEEP          ((uint32)((1u << enable_gate_driver_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << enable_gate_driver_USBIO_SUSPEND_DEL_SHIFT)))
    #define enable_gate_driver_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << enable_gate_driver_USBIO_SUSPEND_SHIFT)))
    #define enable_gate_driver_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << enable_gate_driver_USBIO_SUSPEND_DEL_SHIFT)))
    #define enable_gate_driver_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(enable_gate_driver__PC)
    /* Port Configuration */
    #define enable_gate_driver_PC                 (* (reg32 *) enable_gate_driver__PC)
#endif
/* Pin State */
#define enable_gate_driver_PS                     (* (reg32 *) enable_gate_driver__PS)
/* Data Register */
#define enable_gate_driver_DR                     (* (reg32 *) enable_gate_driver__DR)
/* Input Buffer Disable Override */
#define enable_gate_driver_INP_DIS                (* (reg32 *) enable_gate_driver__PC2)

/* Interrupt configuration Registers */
#define enable_gate_driver_INTCFG                 (* (reg32 *) enable_gate_driver__INTCFG)
#define enable_gate_driver_INTSTAT                (* (reg32 *) enable_gate_driver__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define enable_gate_driver_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(enable_gate_driver__SIO)
    #define enable_gate_driver_SIO_REG            (* (reg32 *) enable_gate_driver__SIO)
#endif /* (enable_gate_driver__SIO_CFG) */

/* USBIO registers */
#if !defined(enable_gate_driver__PC) && (CY_PSOC4_4200L)
    #define enable_gate_driver_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define enable_gate_driver_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define enable_gate_driver_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define enable_gate_driver_DRIVE_MODE_SHIFT       (0x00u)
#define enable_gate_driver_DRIVE_MODE_MASK        (0x07u << enable_gate_driver_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins enable_gate_driver_H */


/* [] END OF FILE */
