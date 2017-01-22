/*******************************************************************************
* File Name: XW.h  
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

#if !defined(CY_PINS_XW_H) /* Pins XW_H */
#define CY_PINS_XW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "XW_aliases.h"


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
} XW_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   XW_Read(void);
void    XW_Write(uint8 value);
uint8   XW_ReadDataReg(void);
#if defined(XW__PC) || (CY_PSOC4_4200L) 
    void    XW_SetDriveMode(uint8 mode);
#endif
void    XW_SetInterruptMode(uint16 position, uint16 mode);
uint8   XW_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void XW_Sleep(void); 
void XW_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(XW__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define XW_DRIVE_MODE_BITS        (3)
    #define XW_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - XW_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the XW_SetDriveMode() function.
         *  @{
         */
        #define XW_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define XW_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define XW_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define XW_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define XW_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define XW_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define XW_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define XW_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define XW_MASK               XW__MASK
#define XW_SHIFT              XW__SHIFT
#define XW_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in XW_SetInterruptMode() function.
     *  @{
     */
        #define XW_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define XW_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define XW_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define XW_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(XW__SIO)
    #define XW_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(XW__PC) && (CY_PSOC4_4200L)
    #define XW_USBIO_ENABLE               ((uint32)0x80000000u)
    #define XW_USBIO_DISABLE              ((uint32)(~XW_USBIO_ENABLE))
    #define XW_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define XW_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define XW_USBIO_ENTER_SLEEP          ((uint32)((1u << XW_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << XW_USBIO_SUSPEND_DEL_SHIFT)))
    #define XW_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << XW_USBIO_SUSPEND_SHIFT)))
    #define XW_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << XW_USBIO_SUSPEND_DEL_SHIFT)))
    #define XW_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(XW__PC)
    /* Port Configuration */
    #define XW_PC                 (* (reg32 *) XW__PC)
#endif
/* Pin State */
#define XW_PS                     (* (reg32 *) XW__PS)
/* Data Register */
#define XW_DR                     (* (reg32 *) XW__DR)
/* Input Buffer Disable Override */
#define XW_INP_DIS                (* (reg32 *) XW__PC2)

/* Interrupt configuration Registers */
#define XW_INTCFG                 (* (reg32 *) XW__INTCFG)
#define XW_INTSTAT                (* (reg32 *) XW__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define XW_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(XW__SIO)
    #define XW_SIO_REG            (* (reg32 *) XW__SIO)
#endif /* (XW__SIO_CFG) */

/* USBIO registers */
#if !defined(XW__PC) && (CY_PSOC4_4200L)
    #define XW_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define XW_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define XW_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define XW_DRIVE_MODE_SHIFT       (0x00u)
#define XW_DRIVE_MODE_MASK        (0x07u << XW_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins XW_H */


/* [] END OF FILE */
