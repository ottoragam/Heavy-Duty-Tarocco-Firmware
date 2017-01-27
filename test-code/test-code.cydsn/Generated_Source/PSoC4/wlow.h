/*******************************************************************************
* File Name: wlow.h  
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

#if !defined(CY_PINS_wlow_H) /* Pins wlow_H */
#define CY_PINS_wlow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "wlow_aliases.h"


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
} wlow_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   wlow_Read(void);
void    wlow_Write(uint8 value);
uint8   wlow_ReadDataReg(void);
#if defined(wlow__PC) || (CY_PSOC4_4200L) 
    void    wlow_SetDriveMode(uint8 mode);
#endif
void    wlow_SetInterruptMode(uint16 position, uint16 mode);
uint8   wlow_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void wlow_Sleep(void); 
void wlow_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(wlow__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define wlow_DRIVE_MODE_BITS        (3)
    #define wlow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - wlow_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the wlow_SetDriveMode() function.
         *  @{
         */
        #define wlow_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define wlow_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define wlow_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define wlow_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define wlow_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define wlow_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define wlow_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define wlow_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define wlow_MASK               wlow__MASK
#define wlow_SHIFT              wlow__SHIFT
#define wlow_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in wlow_SetInterruptMode() function.
     *  @{
     */
        #define wlow_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define wlow_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define wlow_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define wlow_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(wlow__SIO)
    #define wlow_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(wlow__PC) && (CY_PSOC4_4200L)
    #define wlow_USBIO_ENABLE               ((uint32)0x80000000u)
    #define wlow_USBIO_DISABLE              ((uint32)(~wlow_USBIO_ENABLE))
    #define wlow_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define wlow_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define wlow_USBIO_ENTER_SLEEP          ((uint32)((1u << wlow_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << wlow_USBIO_SUSPEND_DEL_SHIFT)))
    #define wlow_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << wlow_USBIO_SUSPEND_SHIFT)))
    #define wlow_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << wlow_USBIO_SUSPEND_DEL_SHIFT)))
    #define wlow_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(wlow__PC)
    /* Port Configuration */
    #define wlow_PC                 (* (reg32 *) wlow__PC)
#endif
/* Pin State */
#define wlow_PS                     (* (reg32 *) wlow__PS)
/* Data Register */
#define wlow_DR                     (* (reg32 *) wlow__DR)
/* Input Buffer Disable Override */
#define wlow_INP_DIS                (* (reg32 *) wlow__PC2)

/* Interrupt configuration Registers */
#define wlow_INTCFG                 (* (reg32 *) wlow__INTCFG)
#define wlow_INTSTAT                (* (reg32 *) wlow__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define wlow_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(wlow__SIO)
    #define wlow_SIO_REG            (* (reg32 *) wlow__SIO)
#endif /* (wlow__SIO_CFG) */

/* USBIO registers */
#if !defined(wlow__PC) && (CY_PSOC4_4200L)
    #define wlow_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define wlow_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define wlow_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define wlow_DRIVE_MODE_SHIFT       (0x00u)
#define wlow_DRIVE_MODE_MASK        (0x07u << wlow_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins wlow_H */


/* [] END OF FILE */
