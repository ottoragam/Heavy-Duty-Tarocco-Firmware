/*******************************************************************************
* File Name: whigh.h  
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

#if !defined(CY_PINS_whigh_H) /* Pins whigh_H */
#define CY_PINS_whigh_H

#include "cytypes.h"
#include "cyfitter.h"
#include "whigh_aliases.h"


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
} whigh_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   whigh_Read(void);
void    whigh_Write(uint8 value);
uint8   whigh_ReadDataReg(void);
#if defined(whigh__PC) || (CY_PSOC4_4200L) 
    void    whigh_SetDriveMode(uint8 mode);
#endif
void    whigh_SetInterruptMode(uint16 position, uint16 mode);
uint8   whigh_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void whigh_Sleep(void); 
void whigh_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(whigh__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define whigh_DRIVE_MODE_BITS        (3)
    #define whigh_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - whigh_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the whigh_SetDriveMode() function.
         *  @{
         */
        #define whigh_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define whigh_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define whigh_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define whigh_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define whigh_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define whigh_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define whigh_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define whigh_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define whigh_MASK               whigh__MASK
#define whigh_SHIFT              whigh__SHIFT
#define whigh_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in whigh_SetInterruptMode() function.
     *  @{
     */
        #define whigh_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define whigh_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define whigh_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define whigh_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(whigh__SIO)
    #define whigh_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(whigh__PC) && (CY_PSOC4_4200L)
    #define whigh_USBIO_ENABLE               ((uint32)0x80000000u)
    #define whigh_USBIO_DISABLE              ((uint32)(~whigh_USBIO_ENABLE))
    #define whigh_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define whigh_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define whigh_USBIO_ENTER_SLEEP          ((uint32)((1u << whigh_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << whigh_USBIO_SUSPEND_DEL_SHIFT)))
    #define whigh_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << whigh_USBIO_SUSPEND_SHIFT)))
    #define whigh_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << whigh_USBIO_SUSPEND_DEL_SHIFT)))
    #define whigh_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(whigh__PC)
    /* Port Configuration */
    #define whigh_PC                 (* (reg32 *) whigh__PC)
#endif
/* Pin State */
#define whigh_PS                     (* (reg32 *) whigh__PS)
/* Data Register */
#define whigh_DR                     (* (reg32 *) whigh__DR)
/* Input Buffer Disable Override */
#define whigh_INP_DIS                (* (reg32 *) whigh__PC2)

/* Interrupt configuration Registers */
#define whigh_INTCFG                 (* (reg32 *) whigh__INTCFG)
#define whigh_INTSTAT                (* (reg32 *) whigh__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define whigh_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(whigh__SIO)
    #define whigh_SIO_REG            (* (reg32 *) whigh__SIO)
#endif /* (whigh__SIO_CFG) */

/* USBIO registers */
#if !defined(whigh__PC) && (CY_PSOC4_4200L)
    #define whigh_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define whigh_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define whigh_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define whigh_DRIVE_MODE_SHIFT       (0x00u)
#define whigh_DRIVE_MODE_MASK        (0x07u << whigh_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins whigh_H */


/* [] END OF FILE */
