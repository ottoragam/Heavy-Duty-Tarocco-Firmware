/*******************************************************************************
* File Name: vlow.h  
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

#if !defined(CY_PINS_vlow_H) /* Pins vlow_H */
#define CY_PINS_vlow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "vlow_aliases.h"


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
} vlow_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   vlow_Read(void);
void    vlow_Write(uint8 value);
uint8   vlow_ReadDataReg(void);
#if defined(vlow__PC) || (CY_PSOC4_4200L) 
    void    vlow_SetDriveMode(uint8 mode);
#endif
void    vlow_SetInterruptMode(uint16 position, uint16 mode);
uint8   vlow_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void vlow_Sleep(void); 
void vlow_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(vlow__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define vlow_DRIVE_MODE_BITS        (3)
    #define vlow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - vlow_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the vlow_SetDriveMode() function.
         *  @{
         */
        #define vlow_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define vlow_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define vlow_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define vlow_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define vlow_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define vlow_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define vlow_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define vlow_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define vlow_MASK               vlow__MASK
#define vlow_SHIFT              vlow__SHIFT
#define vlow_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in vlow_SetInterruptMode() function.
     *  @{
     */
        #define vlow_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define vlow_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define vlow_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define vlow_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(vlow__SIO)
    #define vlow_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(vlow__PC) && (CY_PSOC4_4200L)
    #define vlow_USBIO_ENABLE               ((uint32)0x80000000u)
    #define vlow_USBIO_DISABLE              ((uint32)(~vlow_USBIO_ENABLE))
    #define vlow_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define vlow_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define vlow_USBIO_ENTER_SLEEP          ((uint32)((1u << vlow_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << vlow_USBIO_SUSPEND_DEL_SHIFT)))
    #define vlow_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << vlow_USBIO_SUSPEND_SHIFT)))
    #define vlow_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << vlow_USBIO_SUSPEND_DEL_SHIFT)))
    #define vlow_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(vlow__PC)
    /* Port Configuration */
    #define vlow_PC                 (* (reg32 *) vlow__PC)
#endif
/* Pin State */
#define vlow_PS                     (* (reg32 *) vlow__PS)
/* Data Register */
#define vlow_DR                     (* (reg32 *) vlow__DR)
/* Input Buffer Disable Override */
#define vlow_INP_DIS                (* (reg32 *) vlow__PC2)

/* Interrupt configuration Registers */
#define vlow_INTCFG                 (* (reg32 *) vlow__INTCFG)
#define vlow_INTSTAT                (* (reg32 *) vlow__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define vlow_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(vlow__SIO)
    #define vlow_SIO_REG            (* (reg32 *) vlow__SIO)
#endif /* (vlow__SIO_CFG) */

/* USBIO registers */
#if !defined(vlow__PC) && (CY_PSOC4_4200L)
    #define vlow_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define vlow_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define vlow_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define vlow_DRIVE_MODE_SHIFT       (0x00u)
#define vlow_DRIVE_MODE_MASK        (0x07u << vlow_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins vlow_H */


/* [] END OF FILE */
