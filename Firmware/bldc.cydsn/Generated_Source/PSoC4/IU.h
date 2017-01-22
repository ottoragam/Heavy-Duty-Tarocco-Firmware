/*******************************************************************************
* File Name: IU.h  
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

#if !defined(CY_PINS_IU_H) /* Pins IU_H */
#define CY_PINS_IU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IU_aliases.h"


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
} IU_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   IU_Read(void);
void    IU_Write(uint8 value);
uint8   IU_ReadDataReg(void);
#if defined(IU__PC) || (CY_PSOC4_4200L) 
    void    IU_SetDriveMode(uint8 mode);
#endif
void    IU_SetInterruptMode(uint16 position, uint16 mode);
uint8   IU_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void IU_Sleep(void); 
void IU_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(IU__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define IU_DRIVE_MODE_BITS        (3)
    #define IU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IU_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the IU_SetDriveMode() function.
         *  @{
         */
        #define IU_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define IU_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define IU_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define IU_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define IU_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define IU_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define IU_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define IU_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define IU_MASK               IU__MASK
#define IU_SHIFT              IU__SHIFT
#define IU_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IU_SetInterruptMode() function.
     *  @{
     */
        #define IU_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define IU_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define IU_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define IU_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(IU__SIO)
    #define IU_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(IU__PC) && (CY_PSOC4_4200L)
    #define IU_USBIO_ENABLE               ((uint32)0x80000000u)
    #define IU_USBIO_DISABLE              ((uint32)(~IU_USBIO_ENABLE))
    #define IU_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define IU_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define IU_USBIO_ENTER_SLEEP          ((uint32)((1u << IU_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << IU_USBIO_SUSPEND_DEL_SHIFT)))
    #define IU_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << IU_USBIO_SUSPEND_SHIFT)))
    #define IU_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << IU_USBIO_SUSPEND_DEL_SHIFT)))
    #define IU_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(IU__PC)
    /* Port Configuration */
    #define IU_PC                 (* (reg32 *) IU__PC)
#endif
/* Pin State */
#define IU_PS                     (* (reg32 *) IU__PS)
/* Data Register */
#define IU_DR                     (* (reg32 *) IU__DR)
/* Input Buffer Disable Override */
#define IU_INP_DIS                (* (reg32 *) IU__PC2)

/* Interrupt configuration Registers */
#define IU_INTCFG                 (* (reg32 *) IU__INTCFG)
#define IU_INTSTAT                (* (reg32 *) IU__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define IU_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(IU__SIO)
    #define IU_SIO_REG            (* (reg32 *) IU__SIO)
#endif /* (IU__SIO_CFG) */

/* USBIO registers */
#if !defined(IU__PC) && (CY_PSOC4_4200L)
    #define IU_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define IU_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define IU_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define IU_DRIVE_MODE_SHIFT       (0x00u)
#define IU_DRIVE_MODE_MASK        (0x07u << IU_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins IU_H */


/* [] END OF FILE */
