/*******************************************************************************
* File Name: ulow.h  
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

#if !defined(CY_PINS_ulow_H) /* Pins ulow_H */
#define CY_PINS_ulow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ulow_aliases.h"


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
} ulow_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ulow_Read(void);
void    ulow_Write(uint8 value);
uint8   ulow_ReadDataReg(void);
#if defined(ulow__PC) || (CY_PSOC4_4200L) 
    void    ulow_SetDriveMode(uint8 mode);
#endif
void    ulow_SetInterruptMode(uint16 position, uint16 mode);
uint8   ulow_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ulow_Sleep(void); 
void ulow_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ulow__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ulow_DRIVE_MODE_BITS        (3)
    #define ulow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ulow_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ulow_SetDriveMode() function.
         *  @{
         */
        #define ulow_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ulow_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ulow_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ulow_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ulow_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ulow_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ulow_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ulow_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ulow_MASK               ulow__MASK
#define ulow_SHIFT              ulow__SHIFT
#define ulow_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ulow_SetInterruptMode() function.
     *  @{
     */
        #define ulow_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ulow_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ulow_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ulow_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ulow__SIO)
    #define ulow_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ulow__PC) && (CY_PSOC4_4200L)
    #define ulow_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ulow_USBIO_DISABLE              ((uint32)(~ulow_USBIO_ENABLE))
    #define ulow_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ulow_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ulow_USBIO_ENTER_SLEEP          ((uint32)((1u << ulow_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ulow_USBIO_SUSPEND_DEL_SHIFT)))
    #define ulow_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ulow_USBIO_SUSPEND_SHIFT)))
    #define ulow_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ulow_USBIO_SUSPEND_DEL_SHIFT)))
    #define ulow_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ulow__PC)
    /* Port Configuration */
    #define ulow_PC                 (* (reg32 *) ulow__PC)
#endif
/* Pin State */
#define ulow_PS                     (* (reg32 *) ulow__PS)
/* Data Register */
#define ulow_DR                     (* (reg32 *) ulow__DR)
/* Input Buffer Disable Override */
#define ulow_INP_DIS                (* (reg32 *) ulow__PC2)

/* Interrupt configuration Registers */
#define ulow_INTCFG                 (* (reg32 *) ulow__INTCFG)
#define ulow_INTSTAT                (* (reg32 *) ulow__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ulow_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ulow__SIO)
    #define ulow_SIO_REG            (* (reg32 *) ulow__SIO)
#endif /* (ulow__SIO_CFG) */

/* USBIO registers */
#if !defined(ulow__PC) && (CY_PSOC4_4200L)
    #define ulow_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ulow_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ulow_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ulow_DRIVE_MODE_SHIFT       (0x00u)
#define ulow_DRIVE_MODE_MASK        (0x07u << ulow_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ulow_H */


/* [] END OF FILE */
