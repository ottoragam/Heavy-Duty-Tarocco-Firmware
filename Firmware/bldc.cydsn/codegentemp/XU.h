/*******************************************************************************
* File Name: XU.h  
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

#if !defined(CY_PINS_XU_H) /* Pins XU_H */
#define CY_PINS_XU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "XU_aliases.h"


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
} XU_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   XU_Read(void);
void    XU_Write(uint8 value);
uint8   XU_ReadDataReg(void);
#if defined(XU__PC) || (CY_PSOC4_4200L) 
    void    XU_SetDriveMode(uint8 mode);
#endif
void    XU_SetInterruptMode(uint16 position, uint16 mode);
uint8   XU_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void XU_Sleep(void); 
void XU_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(XU__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define XU_DRIVE_MODE_BITS        (3)
    #define XU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - XU_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the XU_SetDriveMode() function.
         *  @{
         */
        #define XU_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define XU_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define XU_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define XU_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define XU_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define XU_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define XU_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define XU_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define XU_MASK               XU__MASK
#define XU_SHIFT              XU__SHIFT
#define XU_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in XU_SetInterruptMode() function.
     *  @{
     */
        #define XU_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define XU_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define XU_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define XU_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(XU__SIO)
    #define XU_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(XU__PC) && (CY_PSOC4_4200L)
    #define XU_USBIO_ENABLE               ((uint32)0x80000000u)
    #define XU_USBIO_DISABLE              ((uint32)(~XU_USBIO_ENABLE))
    #define XU_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define XU_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define XU_USBIO_ENTER_SLEEP          ((uint32)((1u << XU_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << XU_USBIO_SUSPEND_DEL_SHIFT)))
    #define XU_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << XU_USBIO_SUSPEND_SHIFT)))
    #define XU_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << XU_USBIO_SUSPEND_DEL_SHIFT)))
    #define XU_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(XU__PC)
    /* Port Configuration */
    #define XU_PC                 (* (reg32 *) XU__PC)
#endif
/* Pin State */
#define XU_PS                     (* (reg32 *) XU__PS)
/* Data Register */
#define XU_DR                     (* (reg32 *) XU__DR)
/* Input Buffer Disable Override */
#define XU_INP_DIS                (* (reg32 *) XU__PC2)

/* Interrupt configuration Registers */
#define XU_INTCFG                 (* (reg32 *) XU__INTCFG)
#define XU_INTSTAT                (* (reg32 *) XU__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define XU_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(XU__SIO)
    #define XU_SIO_REG            (* (reg32 *) XU__SIO)
#endif /* (XU__SIO_CFG) */

/* USBIO registers */
#if !defined(XU__PC) && (CY_PSOC4_4200L)
    #define XU_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define XU_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define XU_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define XU_DRIVE_MODE_SHIFT       (0x00u)
#define XU_DRIVE_MODE_MASK        (0x07u << XU_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins XU_H */


/* [] END OF FILE */
