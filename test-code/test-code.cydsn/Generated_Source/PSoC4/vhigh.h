/*******************************************************************************
* File Name: vhigh.h  
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

#if !defined(CY_PINS_vhigh_H) /* Pins vhigh_H */
#define CY_PINS_vhigh_H

#include "cytypes.h"
#include "cyfitter.h"
#include "vhigh_aliases.h"


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
} vhigh_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   vhigh_Read(void);
void    vhigh_Write(uint8 value);
uint8   vhigh_ReadDataReg(void);
#if defined(vhigh__PC) || (CY_PSOC4_4200L) 
    void    vhigh_SetDriveMode(uint8 mode);
#endif
void    vhigh_SetInterruptMode(uint16 position, uint16 mode);
uint8   vhigh_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void vhigh_Sleep(void); 
void vhigh_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(vhigh__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define vhigh_DRIVE_MODE_BITS        (3)
    #define vhigh_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - vhigh_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the vhigh_SetDriveMode() function.
         *  @{
         */
        #define vhigh_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define vhigh_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define vhigh_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define vhigh_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define vhigh_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define vhigh_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define vhigh_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define vhigh_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define vhigh_MASK               vhigh__MASK
#define vhigh_SHIFT              vhigh__SHIFT
#define vhigh_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in vhigh_SetInterruptMode() function.
     *  @{
     */
        #define vhigh_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define vhigh_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define vhigh_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define vhigh_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(vhigh__SIO)
    #define vhigh_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(vhigh__PC) && (CY_PSOC4_4200L)
    #define vhigh_USBIO_ENABLE               ((uint32)0x80000000u)
    #define vhigh_USBIO_DISABLE              ((uint32)(~vhigh_USBIO_ENABLE))
    #define vhigh_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define vhigh_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define vhigh_USBIO_ENTER_SLEEP          ((uint32)((1u << vhigh_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << vhigh_USBIO_SUSPEND_DEL_SHIFT)))
    #define vhigh_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << vhigh_USBIO_SUSPEND_SHIFT)))
    #define vhigh_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << vhigh_USBIO_SUSPEND_DEL_SHIFT)))
    #define vhigh_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(vhigh__PC)
    /* Port Configuration */
    #define vhigh_PC                 (* (reg32 *) vhigh__PC)
#endif
/* Pin State */
#define vhigh_PS                     (* (reg32 *) vhigh__PS)
/* Data Register */
#define vhigh_DR                     (* (reg32 *) vhigh__DR)
/* Input Buffer Disable Override */
#define vhigh_INP_DIS                (* (reg32 *) vhigh__PC2)

/* Interrupt configuration Registers */
#define vhigh_INTCFG                 (* (reg32 *) vhigh__INTCFG)
#define vhigh_INTSTAT                (* (reg32 *) vhigh__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define vhigh_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(vhigh__SIO)
    #define vhigh_SIO_REG            (* (reg32 *) vhigh__SIO)
#endif /* (vhigh__SIO_CFG) */

/* USBIO registers */
#if !defined(vhigh__PC) && (CY_PSOC4_4200L)
    #define vhigh_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define vhigh_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define vhigh_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define vhigh_DRIVE_MODE_SHIFT       (0x00u)
#define vhigh_DRIVE_MODE_MASK        (0x07u << vhigh_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins vhigh_H */


/* [] END OF FILE */
