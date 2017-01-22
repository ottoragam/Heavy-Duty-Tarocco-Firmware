/*******************************************************************************
* File Name: XV.h  
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

#if !defined(CY_PINS_XV_H) /* Pins XV_H */
#define CY_PINS_XV_H

#include "cytypes.h"
#include "cyfitter.h"
#include "XV_aliases.h"


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
} XV_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   XV_Read(void);
void    XV_Write(uint8 value);
uint8   XV_ReadDataReg(void);
#if defined(XV__PC) || (CY_PSOC4_4200L) 
    void    XV_SetDriveMode(uint8 mode);
#endif
void    XV_SetInterruptMode(uint16 position, uint16 mode);
uint8   XV_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void XV_Sleep(void); 
void XV_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(XV__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define XV_DRIVE_MODE_BITS        (3)
    #define XV_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - XV_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the XV_SetDriveMode() function.
         *  @{
         */
        #define XV_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define XV_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define XV_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define XV_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define XV_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define XV_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define XV_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define XV_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define XV_MASK               XV__MASK
#define XV_SHIFT              XV__SHIFT
#define XV_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in XV_SetInterruptMode() function.
     *  @{
     */
        #define XV_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define XV_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define XV_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define XV_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(XV__SIO)
    #define XV_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(XV__PC) && (CY_PSOC4_4200L)
    #define XV_USBIO_ENABLE               ((uint32)0x80000000u)
    #define XV_USBIO_DISABLE              ((uint32)(~XV_USBIO_ENABLE))
    #define XV_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define XV_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define XV_USBIO_ENTER_SLEEP          ((uint32)((1u << XV_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << XV_USBIO_SUSPEND_DEL_SHIFT)))
    #define XV_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << XV_USBIO_SUSPEND_SHIFT)))
    #define XV_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << XV_USBIO_SUSPEND_DEL_SHIFT)))
    #define XV_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(XV__PC)
    /* Port Configuration */
    #define XV_PC                 (* (reg32 *) XV__PC)
#endif
/* Pin State */
#define XV_PS                     (* (reg32 *) XV__PS)
/* Data Register */
#define XV_DR                     (* (reg32 *) XV__DR)
/* Input Buffer Disable Override */
#define XV_INP_DIS                (* (reg32 *) XV__PC2)

/* Interrupt configuration Registers */
#define XV_INTCFG                 (* (reg32 *) XV__INTCFG)
#define XV_INTSTAT                (* (reg32 *) XV__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define XV_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(XV__SIO)
    #define XV_SIO_REG            (* (reg32 *) XV__SIO)
#endif /* (XV__SIO_CFG) */

/* USBIO registers */
#if !defined(XV__PC) && (CY_PSOC4_4200L)
    #define XV_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define XV_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define XV_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define XV_DRIVE_MODE_SHIFT       (0x00u)
#define XV_DRIVE_MODE_MASK        (0x07u << XV_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins XV_H */


/* [] END OF FILE */
