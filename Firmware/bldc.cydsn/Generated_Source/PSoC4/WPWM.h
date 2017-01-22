/*******************************************************************************
* File Name: WPWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the WPWM
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_WPWM_H)
#define CY_TCPWM_WPWM_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} WPWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  WPWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define WPWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define WPWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define WPWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define WPWM_QUAD_ENCODING_MODES            (0lu)
#define WPWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define WPWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define WPWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define WPWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define WPWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define WPWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define WPWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define WPWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define WPWM_TC_RUN_MODE                    (0lu)
#define WPWM_TC_COUNTER_MODE                (0lu)
#define WPWM_TC_COMP_CAP_MODE               (2lu)
#define WPWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define WPWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define WPWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define WPWM_TC_START_SIGNAL_MODE           (0lu)
#define WPWM_TC_STOP_SIGNAL_MODE            (0lu)
#define WPWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define WPWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define WPWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define WPWM_TC_START_SIGNAL_PRESENT        (0lu)
#define WPWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define WPWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define WPWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define WPWM_PWM_KILL_EVENT                 (0lu)
#define WPWM_PWM_STOP_EVENT                 (0lu)
#define WPWM_PWM_MODE                       (5lu)
#define WPWM_PWM_OUT_N_INVERT               (0lu)
#define WPWM_PWM_OUT_INVERT                 (0lu)
#define WPWM_PWM_ALIGN                      (2lu)
#define WPWM_PWM_RUN_MODE                   (0lu)
#define WPWM_PWM_DEAD_TIME_CYCLE            (100lu)
#define WPWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define WPWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define WPWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define WPWM_PWM_START_SIGNAL_MODE          (3lu)
#define WPWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define WPWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define WPWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define WPWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define WPWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define WPWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define WPWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define WPWM_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define WPWM_TC_PERIOD_VALUE                (65535lu)
#define WPWM_TC_COMPARE_VALUE               (65535lu)
#define WPWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define WPWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define WPWM_PWM_PERIOD_VALUE               (4096lu)
#define WPWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define WPWM_PWM_PERIOD_SWAP                (0lu)
#define WPWM_PWM_COMPARE_VALUE              (1lu)
#define WPWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define WPWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define WPWM__LEFT 0
#define WPWM__RIGHT 1
#define WPWM__CENTER 2
#define WPWM__ASYMMETRIC 3

#define WPWM__X1 0
#define WPWM__X2 1
#define WPWM__X4 2

#define WPWM__PWM 4
#define WPWM__PWM_DT 5
#define WPWM__PWM_PR 6

#define WPWM__INVERSE 1
#define WPWM__DIRECT 0

#define WPWM__CAPTURE 2
#define WPWM__COMPARE 0

#define WPWM__TRIG_LEVEL 3
#define WPWM__TRIG_RISING 0
#define WPWM__TRIG_FALLING 1
#define WPWM__TRIG_BOTH 2

#define WPWM__INTR_MASK_TC 1
#define WPWM__INTR_MASK_CC_MATCH 2
#define WPWM__INTR_MASK_NONE 0
#define WPWM__INTR_MASK_TC_CC 3

#define WPWM__UNCONFIG 8
#define WPWM__TIMER 1
#define WPWM__QUAD 3
#define WPWM__PWM_SEL 7

#define WPWM__COUNT_UP 0
#define WPWM__COUNT_DOWN 1
#define WPWM__COUNT_UPDOWN0 2
#define WPWM__COUNT_UPDOWN1 3


/* Prescaler */
#define WPWM_PRESCALE_DIVBY1                ((uint32)(0u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY2                ((uint32)(1u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY4                ((uint32)(2u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY8                ((uint32)(3u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY16               ((uint32)(4u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY32               ((uint32)(5u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY64               ((uint32)(6u << WPWM_PRESCALER_SHIFT))
#define WPWM_PRESCALE_DIVBY128              ((uint32)(7u << WPWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define WPWM_MODE_TIMER_COMPARE             ((uint32)(WPWM__COMPARE         <<  \
                                                                  WPWM_MODE_SHIFT))
#define WPWM_MODE_TIMER_CAPTURE             ((uint32)(WPWM__CAPTURE         <<  \
                                                                  WPWM_MODE_SHIFT))
#define WPWM_MODE_QUAD                      ((uint32)(WPWM__QUAD            <<  \
                                                                  WPWM_MODE_SHIFT))
#define WPWM_MODE_PWM                       ((uint32)(WPWM__PWM             <<  \
                                                                  WPWM_MODE_SHIFT))
#define WPWM_MODE_PWM_DT                    ((uint32)(WPWM__PWM_DT          <<  \
                                                                  WPWM_MODE_SHIFT))
#define WPWM_MODE_PWM_PR                    ((uint32)(WPWM__PWM_PR          <<  \
                                                                  WPWM_MODE_SHIFT))

/* Quad Modes */
#define WPWM_MODE_X1                        ((uint32)(WPWM__X1              <<  \
                                                                  WPWM_QUAD_MODE_SHIFT))
#define WPWM_MODE_X2                        ((uint32)(WPWM__X2              <<  \
                                                                  WPWM_QUAD_MODE_SHIFT))
#define WPWM_MODE_X4                        ((uint32)(WPWM__X4              <<  \
                                                                  WPWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define WPWM_COUNT_UP                       ((uint32)(WPWM__COUNT_UP        <<  \
                                                                  WPWM_UPDOWN_SHIFT))
#define WPWM_COUNT_DOWN                     ((uint32)(WPWM__COUNT_DOWN      <<  \
                                                                  WPWM_UPDOWN_SHIFT))
#define WPWM_COUNT_UPDOWN0                  ((uint32)(WPWM__COUNT_UPDOWN0   <<  \
                                                                  WPWM_UPDOWN_SHIFT))
#define WPWM_COUNT_UPDOWN1                  ((uint32)(WPWM__COUNT_UPDOWN1   <<  \
                                                                  WPWM_UPDOWN_SHIFT))

/* PWM output invert */
#define WPWM_INVERT_LINE                    ((uint32)(WPWM__INVERSE         <<  \
                                                                  WPWM_INV_OUT_SHIFT))
#define WPWM_INVERT_LINE_N                  ((uint32)(WPWM__INVERSE         <<  \
                                                                  WPWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define WPWM_TRIG_RISING                    ((uint32)WPWM__TRIG_RISING)
#define WPWM_TRIG_FALLING                   ((uint32)WPWM__TRIG_FALLING)
#define WPWM_TRIG_BOTH                      ((uint32)WPWM__TRIG_BOTH)
#define WPWM_TRIG_LEVEL                     ((uint32)WPWM__TRIG_LEVEL)

/* Interrupt mask */
#define WPWM_INTR_MASK_TC                   ((uint32)WPWM__INTR_MASK_TC)
#define WPWM_INTR_MASK_CC_MATCH             ((uint32)WPWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define WPWM_CC_MATCH_SET                   (0x00u)
#define WPWM_CC_MATCH_CLEAR                 (0x01u)
#define WPWM_CC_MATCH_INVERT                (0x02u)
#define WPWM_CC_MATCH_NO_CHANGE             (0x03u)
#define WPWM_OVERLOW_SET                    (0x00u)
#define WPWM_OVERLOW_CLEAR                  (0x04u)
#define WPWM_OVERLOW_INVERT                 (0x08u)
#define WPWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define WPWM_UNDERFLOW_SET                  (0x00u)
#define WPWM_UNDERFLOW_CLEAR                (0x10u)
#define WPWM_UNDERFLOW_INVERT               (0x20u)
#define WPWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define WPWM_PWM_MODE_LEFT                  (WPWM_CC_MATCH_CLEAR        |   \
                                                         WPWM_OVERLOW_SET           |   \
                                                         WPWM_UNDERFLOW_NO_CHANGE)
#define WPWM_PWM_MODE_RIGHT                 (WPWM_CC_MATCH_SET          |   \
                                                         WPWM_OVERLOW_NO_CHANGE     |   \
                                                         WPWM_UNDERFLOW_CLEAR)
#define WPWM_PWM_MODE_ASYM                  (WPWM_CC_MATCH_INVERT       |   \
                                                         WPWM_OVERLOW_SET           |   \
                                                         WPWM_UNDERFLOW_CLEAR)

#if (WPWM_CY_TCPWM_V2)
    #if(WPWM_CY_TCPWM_4000)
        #define WPWM_PWM_MODE_CENTER                (WPWM_CC_MATCH_INVERT       |   \
                                                                 WPWM_OVERLOW_NO_CHANGE     |   \
                                                                 WPWM_UNDERFLOW_CLEAR)
    #else
        #define WPWM_PWM_MODE_CENTER                (WPWM_CC_MATCH_INVERT       |   \
                                                                 WPWM_OVERLOW_SET           |   \
                                                                 WPWM_UNDERFLOW_CLEAR)
    #endif /* (WPWM_CY_TCPWM_4000) */
#else
    #define WPWM_PWM_MODE_CENTER                (WPWM_CC_MATCH_INVERT       |   \
                                                             WPWM_OVERLOW_NO_CHANGE     |   \
                                                             WPWM_UNDERFLOW_CLEAR)
#endif /* (WPWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define WPWM_CMD_CAPTURE                    (0u)
#define WPWM_CMD_RELOAD                     (8u)
#define WPWM_CMD_STOP                       (16u)
#define WPWM_CMD_START                      (24u)

/* Status */
#define WPWM_STATUS_DOWN                    (1u)
#define WPWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   WPWM_Init(void);
void   WPWM_Enable(void);
void   WPWM_Start(void);
void   WPWM_Stop(void);

void   WPWM_SetMode(uint32 mode);
void   WPWM_SetCounterMode(uint32 counterMode);
void   WPWM_SetPWMMode(uint32 modeMask);
void   WPWM_SetQDMode(uint32 qdMode);

void   WPWM_SetPrescaler(uint32 prescaler);
void   WPWM_TriggerCommand(uint32 mask, uint32 command);
void   WPWM_SetOneShot(uint32 oneShotEnable);
uint32 WPWM_ReadStatus(void);

void   WPWM_SetPWMSyncKill(uint32 syncKillEnable);
void   WPWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   WPWM_SetPWMDeadTime(uint32 deadTime);
void   WPWM_SetPWMInvert(uint32 mask);

void   WPWM_SetInterruptMode(uint32 interruptMask);
uint32 WPWM_GetInterruptSourceMasked(void);
uint32 WPWM_GetInterruptSource(void);
void   WPWM_ClearInterrupt(uint32 interruptMask);
void   WPWM_SetInterrupt(uint32 interruptMask);

void   WPWM_WriteCounter(uint32 count);
uint32 WPWM_ReadCounter(void);

uint32 WPWM_ReadCapture(void);
uint32 WPWM_ReadCaptureBuf(void);

void   WPWM_WritePeriod(uint32 period);
uint32 WPWM_ReadPeriod(void);
void   WPWM_WritePeriodBuf(uint32 periodBuf);
uint32 WPWM_ReadPeriodBuf(void);

void   WPWM_WriteCompare(uint32 compare);
uint32 WPWM_ReadCompare(void);
void   WPWM_WriteCompareBuf(uint32 compareBuf);
uint32 WPWM_ReadCompareBuf(void);

void   WPWM_SetPeriodSwap(uint32 swapEnable);
void   WPWM_SetCompareSwap(uint32 swapEnable);

void   WPWM_SetCaptureMode(uint32 triggerMode);
void   WPWM_SetReloadMode(uint32 triggerMode);
void   WPWM_SetStartMode(uint32 triggerMode);
void   WPWM_SetStopMode(uint32 triggerMode);
void   WPWM_SetCountMode(uint32 triggerMode);

void   WPWM_SaveConfig(void);
void   WPWM_RestoreConfig(void);
void   WPWM_Sleep(void);
void   WPWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define WPWM_BLOCK_CONTROL_REG              (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define WPWM_BLOCK_CONTROL_PTR              ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define WPWM_COMMAND_REG                    (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define WPWM_COMMAND_PTR                    ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define WPWM_INTRRUPT_CAUSE_REG             (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define WPWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define WPWM_CONTROL_REG                    (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__CTRL )
#define WPWM_CONTROL_PTR                    ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__CTRL )
#define WPWM_STATUS_REG                     (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__STATUS )
#define WPWM_STATUS_PTR                     ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__STATUS )
#define WPWM_COUNTER_REG                    (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__COUNTER )
#define WPWM_COUNTER_PTR                    ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__COUNTER )
#define WPWM_COMP_CAP_REG                   (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__CC )
#define WPWM_COMP_CAP_PTR                   ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__CC )
#define WPWM_COMP_CAP_BUF_REG               (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define WPWM_COMP_CAP_BUF_PTR               ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define WPWM_PERIOD_REG                     (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__PERIOD )
#define WPWM_PERIOD_PTR                     ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__PERIOD )
#define WPWM_PERIOD_BUF_REG                 (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define WPWM_PERIOD_BUF_PTR                 ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define WPWM_TRIG_CONTROL0_REG              (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define WPWM_TRIG_CONTROL0_PTR              ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define WPWM_TRIG_CONTROL1_REG              (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define WPWM_TRIG_CONTROL1_PTR              ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define WPWM_TRIG_CONTROL2_REG              (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define WPWM_TRIG_CONTROL2_PTR              ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define WPWM_INTERRUPT_REQ_REG              (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR )
#define WPWM_INTERRUPT_REQ_PTR              ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR )
#define WPWM_INTERRUPT_SET_REG              (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define WPWM_INTERRUPT_SET_PTR              ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define WPWM_INTERRUPT_MASK_REG             (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define WPWM_INTERRUPT_MASK_PTR             ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define WPWM_INTERRUPT_MASKED_REG           (*(reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define WPWM_INTERRUPT_MASKED_PTR           ( (reg32 *) WPWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define WPWM_MASK                           ((uint32)WPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define WPWM_RELOAD_CC_SHIFT                (0u)
#define WPWM_RELOAD_PERIOD_SHIFT            (1u)
#define WPWM_PWM_SYNC_KILL_SHIFT            (2u)
#define WPWM_PWM_STOP_KILL_SHIFT            (3u)
#define WPWM_PRESCALER_SHIFT                (8u)
#define WPWM_UPDOWN_SHIFT                   (16u)
#define WPWM_ONESHOT_SHIFT                  (18u)
#define WPWM_QUAD_MODE_SHIFT                (20u)
#define WPWM_INV_OUT_SHIFT                  (20u)
#define WPWM_INV_COMPL_OUT_SHIFT            (21u)
#define WPWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define WPWM_RELOAD_CC_MASK                 ((uint32)(WPWM_1BIT_MASK        <<  \
                                                                            WPWM_RELOAD_CC_SHIFT))
#define WPWM_RELOAD_PERIOD_MASK             ((uint32)(WPWM_1BIT_MASK        <<  \
                                                                            WPWM_RELOAD_PERIOD_SHIFT))
#define WPWM_PWM_SYNC_KILL_MASK             ((uint32)(WPWM_1BIT_MASK        <<  \
                                                                            WPWM_PWM_SYNC_KILL_SHIFT))
#define WPWM_PWM_STOP_KILL_MASK             ((uint32)(WPWM_1BIT_MASK        <<  \
                                                                            WPWM_PWM_STOP_KILL_SHIFT))
#define WPWM_PRESCALER_MASK                 ((uint32)(WPWM_8BIT_MASK        <<  \
                                                                            WPWM_PRESCALER_SHIFT))
#define WPWM_UPDOWN_MASK                    ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                            WPWM_UPDOWN_SHIFT))
#define WPWM_ONESHOT_MASK                   ((uint32)(WPWM_1BIT_MASK        <<  \
                                                                            WPWM_ONESHOT_SHIFT))
#define WPWM_QUAD_MODE_MASK                 ((uint32)(WPWM_3BIT_MASK        <<  \
                                                                            WPWM_QUAD_MODE_SHIFT))
#define WPWM_INV_OUT_MASK                   ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                            WPWM_INV_OUT_SHIFT))
#define WPWM_MODE_MASK                      ((uint32)(WPWM_3BIT_MASK        <<  \
                                                                            WPWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define WPWM_CAPTURE_SHIFT                  (0u)
#define WPWM_COUNT_SHIFT                    (2u)
#define WPWM_RELOAD_SHIFT                   (4u)
#define WPWM_STOP_SHIFT                     (6u)
#define WPWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define WPWM_CAPTURE_MASK                   ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                  WPWM_CAPTURE_SHIFT))
#define WPWM_COUNT_MASK                     ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                  WPWM_COUNT_SHIFT))
#define WPWM_RELOAD_MASK                    ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                  WPWM_RELOAD_SHIFT))
#define WPWM_STOP_MASK                      ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                  WPWM_STOP_SHIFT))
#define WPWM_START_MASK                     ((uint32)(WPWM_2BIT_MASK        <<  \
                                                                  WPWM_START_SHIFT))

/* MASK */
#define WPWM_1BIT_MASK                      ((uint32)0x01u)
#define WPWM_2BIT_MASK                      ((uint32)0x03u)
#define WPWM_3BIT_MASK                      ((uint32)0x07u)
#define WPWM_6BIT_MASK                      ((uint32)0x3Fu)
#define WPWM_8BIT_MASK                      ((uint32)0xFFu)
#define WPWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define WPWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define WPWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(WPWM_QUAD_ENCODING_MODES     << WPWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(WPWM_CONFIG                  << WPWM_MODE_SHIFT)))

#define WPWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(WPWM_PWM_STOP_EVENT          << WPWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(WPWM_PWM_OUT_INVERT          << WPWM_INV_OUT_SHIFT))         |\
         ((uint32)(WPWM_PWM_OUT_N_INVERT        << WPWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(WPWM_PWM_MODE                << WPWM_MODE_SHIFT)))

#define WPWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(WPWM_PWM_RUN_MODE         << WPWM_ONESHOT_SHIFT))
            
#define WPWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(WPWM_PWM_ALIGN            << WPWM_UPDOWN_SHIFT))

#define WPWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(WPWM_PWM_KILL_EVENT      << WPWM_PWM_SYNC_KILL_SHIFT))

#define WPWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(WPWM_PWM_DEAD_TIME_CYCLE  << WPWM_PRESCALER_SHIFT))

#define WPWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(WPWM_PWM_PRESCALER        << WPWM_PRESCALER_SHIFT))

#define WPWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(WPWM_TC_PRESCALER            << WPWM_PRESCALER_SHIFT))       |\
         ((uint32)(WPWM_TC_COUNTER_MODE         << WPWM_UPDOWN_SHIFT))          |\
         ((uint32)(WPWM_TC_RUN_MODE             << WPWM_ONESHOT_SHIFT))         |\
         ((uint32)(WPWM_TC_COMP_CAP_MODE        << WPWM_MODE_SHIFT)))
        
#define WPWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(WPWM_QUAD_PHIA_SIGNAL_MODE   << WPWM_COUNT_SHIFT))           |\
         ((uint32)(WPWM_QUAD_INDEX_SIGNAL_MODE  << WPWM_RELOAD_SHIFT))          |\
         ((uint32)(WPWM_QUAD_STOP_SIGNAL_MODE   << WPWM_STOP_SHIFT))            |\
         ((uint32)(WPWM_QUAD_PHIB_SIGNAL_MODE   << WPWM_START_SHIFT)))

#define WPWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(WPWM_PWM_SWITCH_SIGNAL_MODE  << WPWM_CAPTURE_SHIFT))         |\
         ((uint32)(WPWM_PWM_COUNT_SIGNAL_MODE   << WPWM_COUNT_SHIFT))           |\
         ((uint32)(WPWM_PWM_RELOAD_SIGNAL_MODE  << WPWM_RELOAD_SHIFT))          |\
         ((uint32)(WPWM_PWM_STOP_SIGNAL_MODE    << WPWM_STOP_SHIFT))            |\
         ((uint32)(WPWM_PWM_START_SIGNAL_MODE   << WPWM_START_SHIFT)))

#define WPWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(WPWM_TC_CAPTURE_SIGNAL_MODE  << WPWM_CAPTURE_SHIFT))         |\
         ((uint32)(WPWM_TC_COUNT_SIGNAL_MODE    << WPWM_COUNT_SHIFT))           |\
         ((uint32)(WPWM_TC_RELOAD_SIGNAL_MODE   << WPWM_RELOAD_SHIFT))          |\
         ((uint32)(WPWM_TC_STOP_SIGNAL_MODE     << WPWM_STOP_SHIFT))            |\
         ((uint32)(WPWM_TC_START_SIGNAL_MODE    << WPWM_START_SHIFT)))
        
#define WPWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((WPWM__COUNT_UPDOWN0 == WPWM_TC_COUNTER_MODE)                  ||\
                 (WPWM__COUNT_UPDOWN1 == WPWM_TC_COUNTER_MODE))

#define WPWM_PWM_UPDOWN_CNT_USED                                                            \
                ((WPWM__CENTER == WPWM_PWM_ALIGN)                               ||\
                 (WPWM__ASYMMETRIC == WPWM_PWM_ALIGN))               
        
#define WPWM_PWM_PR_INIT_VALUE              (1u)
#define WPWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_WPWM_H */

/* [] END OF FILE */
