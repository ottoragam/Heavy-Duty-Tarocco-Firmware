/*******************************************************************************
* File Name: UPWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the UPWM
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

#if !defined(CY_TCPWM_UPWM_H)
#define CY_TCPWM_UPWM_H


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
} UPWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  UPWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define UPWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define UPWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define UPWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define UPWM_QUAD_ENCODING_MODES            (0lu)
#define UPWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define UPWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define UPWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define UPWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define UPWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define UPWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define UPWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define UPWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define UPWM_TC_RUN_MODE                    (0lu)
#define UPWM_TC_COUNTER_MODE                (0lu)
#define UPWM_TC_COMP_CAP_MODE               (2lu)
#define UPWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define UPWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define UPWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define UPWM_TC_START_SIGNAL_MODE           (0lu)
#define UPWM_TC_STOP_SIGNAL_MODE            (0lu)
#define UPWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define UPWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define UPWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define UPWM_TC_START_SIGNAL_PRESENT        (0lu)
#define UPWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define UPWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define UPWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define UPWM_PWM_KILL_EVENT                 (0lu)
#define UPWM_PWM_STOP_EVENT                 (0lu)
#define UPWM_PWM_MODE                       (5lu)
#define UPWM_PWM_OUT_N_INVERT               (0lu)
#define UPWM_PWM_OUT_INVERT                 (0lu)
#define UPWM_PWM_ALIGN                      (2lu)
#define UPWM_PWM_RUN_MODE                   (0lu)
#define UPWM_PWM_DEAD_TIME_CYCLE            (100lu)
#define UPWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define UPWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define UPWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define UPWM_PWM_START_SIGNAL_MODE          (3lu)
#define UPWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define UPWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define UPWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define UPWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define UPWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define UPWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define UPWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define UPWM_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define UPWM_TC_PERIOD_VALUE                (65535lu)
#define UPWM_TC_COMPARE_VALUE               (65535lu)
#define UPWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define UPWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define UPWM_PWM_PERIOD_VALUE               (4096lu)
#define UPWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define UPWM_PWM_PERIOD_SWAP                (0lu)
#define UPWM_PWM_COMPARE_VALUE              (1lu)
#define UPWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define UPWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define UPWM__LEFT 0
#define UPWM__RIGHT 1
#define UPWM__CENTER 2
#define UPWM__ASYMMETRIC 3

#define UPWM__X1 0
#define UPWM__X2 1
#define UPWM__X4 2

#define UPWM__PWM 4
#define UPWM__PWM_DT 5
#define UPWM__PWM_PR 6

#define UPWM__INVERSE 1
#define UPWM__DIRECT 0

#define UPWM__CAPTURE 2
#define UPWM__COMPARE 0

#define UPWM__TRIG_LEVEL 3
#define UPWM__TRIG_RISING 0
#define UPWM__TRIG_FALLING 1
#define UPWM__TRIG_BOTH 2

#define UPWM__INTR_MASK_TC 1
#define UPWM__INTR_MASK_CC_MATCH 2
#define UPWM__INTR_MASK_NONE 0
#define UPWM__INTR_MASK_TC_CC 3

#define UPWM__UNCONFIG 8
#define UPWM__TIMER 1
#define UPWM__QUAD 3
#define UPWM__PWM_SEL 7

#define UPWM__COUNT_UP 0
#define UPWM__COUNT_DOWN 1
#define UPWM__COUNT_UPDOWN0 2
#define UPWM__COUNT_UPDOWN1 3


/* Prescaler */
#define UPWM_PRESCALE_DIVBY1                ((uint32)(0u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY2                ((uint32)(1u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY4                ((uint32)(2u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY8                ((uint32)(3u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY16               ((uint32)(4u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY32               ((uint32)(5u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY64               ((uint32)(6u << UPWM_PRESCALER_SHIFT))
#define UPWM_PRESCALE_DIVBY128              ((uint32)(7u << UPWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define UPWM_MODE_TIMER_COMPARE             ((uint32)(UPWM__COMPARE         <<  \
                                                                  UPWM_MODE_SHIFT))
#define UPWM_MODE_TIMER_CAPTURE             ((uint32)(UPWM__CAPTURE         <<  \
                                                                  UPWM_MODE_SHIFT))
#define UPWM_MODE_QUAD                      ((uint32)(UPWM__QUAD            <<  \
                                                                  UPWM_MODE_SHIFT))
#define UPWM_MODE_PWM                       ((uint32)(UPWM__PWM             <<  \
                                                                  UPWM_MODE_SHIFT))
#define UPWM_MODE_PWM_DT                    ((uint32)(UPWM__PWM_DT          <<  \
                                                                  UPWM_MODE_SHIFT))
#define UPWM_MODE_PWM_PR                    ((uint32)(UPWM__PWM_PR          <<  \
                                                                  UPWM_MODE_SHIFT))

/* Quad Modes */
#define UPWM_MODE_X1                        ((uint32)(UPWM__X1              <<  \
                                                                  UPWM_QUAD_MODE_SHIFT))
#define UPWM_MODE_X2                        ((uint32)(UPWM__X2              <<  \
                                                                  UPWM_QUAD_MODE_SHIFT))
#define UPWM_MODE_X4                        ((uint32)(UPWM__X4              <<  \
                                                                  UPWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define UPWM_COUNT_UP                       ((uint32)(UPWM__COUNT_UP        <<  \
                                                                  UPWM_UPDOWN_SHIFT))
#define UPWM_COUNT_DOWN                     ((uint32)(UPWM__COUNT_DOWN      <<  \
                                                                  UPWM_UPDOWN_SHIFT))
#define UPWM_COUNT_UPDOWN0                  ((uint32)(UPWM__COUNT_UPDOWN0   <<  \
                                                                  UPWM_UPDOWN_SHIFT))
#define UPWM_COUNT_UPDOWN1                  ((uint32)(UPWM__COUNT_UPDOWN1   <<  \
                                                                  UPWM_UPDOWN_SHIFT))

/* PWM output invert */
#define UPWM_INVERT_LINE                    ((uint32)(UPWM__INVERSE         <<  \
                                                                  UPWM_INV_OUT_SHIFT))
#define UPWM_INVERT_LINE_N                  ((uint32)(UPWM__INVERSE         <<  \
                                                                  UPWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define UPWM_TRIG_RISING                    ((uint32)UPWM__TRIG_RISING)
#define UPWM_TRIG_FALLING                   ((uint32)UPWM__TRIG_FALLING)
#define UPWM_TRIG_BOTH                      ((uint32)UPWM__TRIG_BOTH)
#define UPWM_TRIG_LEVEL                     ((uint32)UPWM__TRIG_LEVEL)

/* Interrupt mask */
#define UPWM_INTR_MASK_TC                   ((uint32)UPWM__INTR_MASK_TC)
#define UPWM_INTR_MASK_CC_MATCH             ((uint32)UPWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define UPWM_CC_MATCH_SET                   (0x00u)
#define UPWM_CC_MATCH_CLEAR                 (0x01u)
#define UPWM_CC_MATCH_INVERT                (0x02u)
#define UPWM_CC_MATCH_NO_CHANGE             (0x03u)
#define UPWM_OVERLOW_SET                    (0x00u)
#define UPWM_OVERLOW_CLEAR                  (0x04u)
#define UPWM_OVERLOW_INVERT                 (0x08u)
#define UPWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define UPWM_UNDERFLOW_SET                  (0x00u)
#define UPWM_UNDERFLOW_CLEAR                (0x10u)
#define UPWM_UNDERFLOW_INVERT               (0x20u)
#define UPWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define UPWM_PWM_MODE_LEFT                  (UPWM_CC_MATCH_CLEAR        |   \
                                                         UPWM_OVERLOW_SET           |   \
                                                         UPWM_UNDERFLOW_NO_CHANGE)
#define UPWM_PWM_MODE_RIGHT                 (UPWM_CC_MATCH_SET          |   \
                                                         UPWM_OVERLOW_NO_CHANGE     |   \
                                                         UPWM_UNDERFLOW_CLEAR)
#define UPWM_PWM_MODE_ASYM                  (UPWM_CC_MATCH_INVERT       |   \
                                                         UPWM_OVERLOW_SET           |   \
                                                         UPWM_UNDERFLOW_CLEAR)

#if (UPWM_CY_TCPWM_V2)
    #if(UPWM_CY_TCPWM_4000)
        #define UPWM_PWM_MODE_CENTER                (UPWM_CC_MATCH_INVERT       |   \
                                                                 UPWM_OVERLOW_NO_CHANGE     |   \
                                                                 UPWM_UNDERFLOW_CLEAR)
    #else
        #define UPWM_PWM_MODE_CENTER                (UPWM_CC_MATCH_INVERT       |   \
                                                                 UPWM_OVERLOW_SET           |   \
                                                                 UPWM_UNDERFLOW_CLEAR)
    #endif /* (UPWM_CY_TCPWM_4000) */
#else
    #define UPWM_PWM_MODE_CENTER                (UPWM_CC_MATCH_INVERT       |   \
                                                             UPWM_OVERLOW_NO_CHANGE     |   \
                                                             UPWM_UNDERFLOW_CLEAR)
#endif /* (UPWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define UPWM_CMD_CAPTURE                    (0u)
#define UPWM_CMD_RELOAD                     (8u)
#define UPWM_CMD_STOP                       (16u)
#define UPWM_CMD_START                      (24u)

/* Status */
#define UPWM_STATUS_DOWN                    (1u)
#define UPWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   UPWM_Init(void);
void   UPWM_Enable(void);
void   UPWM_Start(void);
void   UPWM_Stop(void);

void   UPWM_SetMode(uint32 mode);
void   UPWM_SetCounterMode(uint32 counterMode);
void   UPWM_SetPWMMode(uint32 modeMask);
void   UPWM_SetQDMode(uint32 qdMode);

void   UPWM_SetPrescaler(uint32 prescaler);
void   UPWM_TriggerCommand(uint32 mask, uint32 command);
void   UPWM_SetOneShot(uint32 oneShotEnable);
uint32 UPWM_ReadStatus(void);

void   UPWM_SetPWMSyncKill(uint32 syncKillEnable);
void   UPWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   UPWM_SetPWMDeadTime(uint32 deadTime);
void   UPWM_SetPWMInvert(uint32 mask);

void   UPWM_SetInterruptMode(uint32 interruptMask);
uint32 UPWM_GetInterruptSourceMasked(void);
uint32 UPWM_GetInterruptSource(void);
void   UPWM_ClearInterrupt(uint32 interruptMask);
void   UPWM_SetInterrupt(uint32 interruptMask);

void   UPWM_WriteCounter(uint32 count);
uint32 UPWM_ReadCounter(void);

uint32 UPWM_ReadCapture(void);
uint32 UPWM_ReadCaptureBuf(void);

void   UPWM_WritePeriod(uint32 period);
uint32 UPWM_ReadPeriod(void);
void   UPWM_WritePeriodBuf(uint32 periodBuf);
uint32 UPWM_ReadPeriodBuf(void);

void   UPWM_WriteCompare(uint32 compare);
uint32 UPWM_ReadCompare(void);
void   UPWM_WriteCompareBuf(uint32 compareBuf);
uint32 UPWM_ReadCompareBuf(void);

void   UPWM_SetPeriodSwap(uint32 swapEnable);
void   UPWM_SetCompareSwap(uint32 swapEnable);

void   UPWM_SetCaptureMode(uint32 triggerMode);
void   UPWM_SetReloadMode(uint32 triggerMode);
void   UPWM_SetStartMode(uint32 triggerMode);
void   UPWM_SetStopMode(uint32 triggerMode);
void   UPWM_SetCountMode(uint32 triggerMode);

void   UPWM_SaveConfig(void);
void   UPWM_RestoreConfig(void);
void   UPWM_Sleep(void);
void   UPWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define UPWM_BLOCK_CONTROL_REG              (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define UPWM_BLOCK_CONTROL_PTR              ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define UPWM_COMMAND_REG                    (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define UPWM_COMMAND_PTR                    ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define UPWM_INTRRUPT_CAUSE_REG             (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define UPWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define UPWM_CONTROL_REG                    (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__CTRL )
#define UPWM_CONTROL_PTR                    ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__CTRL )
#define UPWM_STATUS_REG                     (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__STATUS )
#define UPWM_STATUS_PTR                     ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__STATUS )
#define UPWM_COUNTER_REG                    (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__COUNTER )
#define UPWM_COUNTER_PTR                    ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__COUNTER )
#define UPWM_COMP_CAP_REG                   (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__CC )
#define UPWM_COMP_CAP_PTR                   ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__CC )
#define UPWM_COMP_CAP_BUF_REG               (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define UPWM_COMP_CAP_BUF_PTR               ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define UPWM_PERIOD_REG                     (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__PERIOD )
#define UPWM_PERIOD_PTR                     ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__PERIOD )
#define UPWM_PERIOD_BUF_REG                 (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define UPWM_PERIOD_BUF_PTR                 ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define UPWM_TRIG_CONTROL0_REG              (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define UPWM_TRIG_CONTROL0_PTR              ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define UPWM_TRIG_CONTROL1_REG              (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define UPWM_TRIG_CONTROL1_PTR              ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define UPWM_TRIG_CONTROL2_REG              (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define UPWM_TRIG_CONTROL2_PTR              ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define UPWM_INTERRUPT_REQ_REG              (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR )
#define UPWM_INTERRUPT_REQ_PTR              ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR )
#define UPWM_INTERRUPT_SET_REG              (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define UPWM_INTERRUPT_SET_PTR              ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define UPWM_INTERRUPT_MASK_REG             (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define UPWM_INTERRUPT_MASK_PTR             ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define UPWM_INTERRUPT_MASKED_REG           (*(reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define UPWM_INTERRUPT_MASKED_PTR           ( (reg32 *) UPWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define UPWM_MASK                           ((uint32)UPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define UPWM_RELOAD_CC_SHIFT                (0u)
#define UPWM_RELOAD_PERIOD_SHIFT            (1u)
#define UPWM_PWM_SYNC_KILL_SHIFT            (2u)
#define UPWM_PWM_STOP_KILL_SHIFT            (3u)
#define UPWM_PRESCALER_SHIFT                (8u)
#define UPWM_UPDOWN_SHIFT                   (16u)
#define UPWM_ONESHOT_SHIFT                  (18u)
#define UPWM_QUAD_MODE_SHIFT                (20u)
#define UPWM_INV_OUT_SHIFT                  (20u)
#define UPWM_INV_COMPL_OUT_SHIFT            (21u)
#define UPWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define UPWM_RELOAD_CC_MASK                 ((uint32)(UPWM_1BIT_MASK        <<  \
                                                                            UPWM_RELOAD_CC_SHIFT))
#define UPWM_RELOAD_PERIOD_MASK             ((uint32)(UPWM_1BIT_MASK        <<  \
                                                                            UPWM_RELOAD_PERIOD_SHIFT))
#define UPWM_PWM_SYNC_KILL_MASK             ((uint32)(UPWM_1BIT_MASK        <<  \
                                                                            UPWM_PWM_SYNC_KILL_SHIFT))
#define UPWM_PWM_STOP_KILL_MASK             ((uint32)(UPWM_1BIT_MASK        <<  \
                                                                            UPWM_PWM_STOP_KILL_SHIFT))
#define UPWM_PRESCALER_MASK                 ((uint32)(UPWM_8BIT_MASK        <<  \
                                                                            UPWM_PRESCALER_SHIFT))
#define UPWM_UPDOWN_MASK                    ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                            UPWM_UPDOWN_SHIFT))
#define UPWM_ONESHOT_MASK                   ((uint32)(UPWM_1BIT_MASK        <<  \
                                                                            UPWM_ONESHOT_SHIFT))
#define UPWM_QUAD_MODE_MASK                 ((uint32)(UPWM_3BIT_MASK        <<  \
                                                                            UPWM_QUAD_MODE_SHIFT))
#define UPWM_INV_OUT_MASK                   ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                            UPWM_INV_OUT_SHIFT))
#define UPWM_MODE_MASK                      ((uint32)(UPWM_3BIT_MASK        <<  \
                                                                            UPWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define UPWM_CAPTURE_SHIFT                  (0u)
#define UPWM_COUNT_SHIFT                    (2u)
#define UPWM_RELOAD_SHIFT                   (4u)
#define UPWM_STOP_SHIFT                     (6u)
#define UPWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define UPWM_CAPTURE_MASK                   ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                  UPWM_CAPTURE_SHIFT))
#define UPWM_COUNT_MASK                     ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                  UPWM_COUNT_SHIFT))
#define UPWM_RELOAD_MASK                    ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                  UPWM_RELOAD_SHIFT))
#define UPWM_STOP_MASK                      ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                  UPWM_STOP_SHIFT))
#define UPWM_START_MASK                     ((uint32)(UPWM_2BIT_MASK        <<  \
                                                                  UPWM_START_SHIFT))

/* MASK */
#define UPWM_1BIT_MASK                      ((uint32)0x01u)
#define UPWM_2BIT_MASK                      ((uint32)0x03u)
#define UPWM_3BIT_MASK                      ((uint32)0x07u)
#define UPWM_6BIT_MASK                      ((uint32)0x3Fu)
#define UPWM_8BIT_MASK                      ((uint32)0xFFu)
#define UPWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define UPWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define UPWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(UPWM_QUAD_ENCODING_MODES     << UPWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(UPWM_CONFIG                  << UPWM_MODE_SHIFT)))

#define UPWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(UPWM_PWM_STOP_EVENT          << UPWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(UPWM_PWM_OUT_INVERT          << UPWM_INV_OUT_SHIFT))         |\
         ((uint32)(UPWM_PWM_OUT_N_INVERT        << UPWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(UPWM_PWM_MODE                << UPWM_MODE_SHIFT)))

#define UPWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(UPWM_PWM_RUN_MODE         << UPWM_ONESHOT_SHIFT))
            
#define UPWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(UPWM_PWM_ALIGN            << UPWM_UPDOWN_SHIFT))

#define UPWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(UPWM_PWM_KILL_EVENT      << UPWM_PWM_SYNC_KILL_SHIFT))

#define UPWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(UPWM_PWM_DEAD_TIME_CYCLE  << UPWM_PRESCALER_SHIFT))

#define UPWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(UPWM_PWM_PRESCALER        << UPWM_PRESCALER_SHIFT))

#define UPWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(UPWM_TC_PRESCALER            << UPWM_PRESCALER_SHIFT))       |\
         ((uint32)(UPWM_TC_COUNTER_MODE         << UPWM_UPDOWN_SHIFT))          |\
         ((uint32)(UPWM_TC_RUN_MODE             << UPWM_ONESHOT_SHIFT))         |\
         ((uint32)(UPWM_TC_COMP_CAP_MODE        << UPWM_MODE_SHIFT)))
        
#define UPWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(UPWM_QUAD_PHIA_SIGNAL_MODE   << UPWM_COUNT_SHIFT))           |\
         ((uint32)(UPWM_QUAD_INDEX_SIGNAL_MODE  << UPWM_RELOAD_SHIFT))          |\
         ((uint32)(UPWM_QUAD_STOP_SIGNAL_MODE   << UPWM_STOP_SHIFT))            |\
         ((uint32)(UPWM_QUAD_PHIB_SIGNAL_MODE   << UPWM_START_SHIFT)))

#define UPWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(UPWM_PWM_SWITCH_SIGNAL_MODE  << UPWM_CAPTURE_SHIFT))         |\
         ((uint32)(UPWM_PWM_COUNT_SIGNAL_MODE   << UPWM_COUNT_SHIFT))           |\
         ((uint32)(UPWM_PWM_RELOAD_SIGNAL_MODE  << UPWM_RELOAD_SHIFT))          |\
         ((uint32)(UPWM_PWM_STOP_SIGNAL_MODE    << UPWM_STOP_SHIFT))            |\
         ((uint32)(UPWM_PWM_START_SIGNAL_MODE   << UPWM_START_SHIFT)))

#define UPWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(UPWM_TC_CAPTURE_SIGNAL_MODE  << UPWM_CAPTURE_SHIFT))         |\
         ((uint32)(UPWM_TC_COUNT_SIGNAL_MODE    << UPWM_COUNT_SHIFT))           |\
         ((uint32)(UPWM_TC_RELOAD_SIGNAL_MODE   << UPWM_RELOAD_SHIFT))          |\
         ((uint32)(UPWM_TC_STOP_SIGNAL_MODE     << UPWM_STOP_SHIFT))            |\
         ((uint32)(UPWM_TC_START_SIGNAL_MODE    << UPWM_START_SHIFT)))
        
#define UPWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((UPWM__COUNT_UPDOWN0 == UPWM_TC_COUNTER_MODE)                  ||\
                 (UPWM__COUNT_UPDOWN1 == UPWM_TC_COUNTER_MODE))

#define UPWM_PWM_UPDOWN_CNT_USED                                                            \
                ((UPWM__CENTER == UPWM_PWM_ALIGN)                               ||\
                 (UPWM__ASYMMETRIC == UPWM_PWM_ALIGN))               
        
#define UPWM_PWM_PR_INIT_VALUE              (1u)
#define UPWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_UPWM_H */

/* [] END OF FILE */
