/*******************************************************************************
* File Name: VPWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the VPWM
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

#if !defined(CY_TCPWM_VPWM_H)
#define CY_TCPWM_VPWM_H


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
} VPWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  VPWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define VPWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define VPWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define VPWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define VPWM_QUAD_ENCODING_MODES            (0lu)
#define VPWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define VPWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define VPWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define VPWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define VPWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define VPWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define VPWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define VPWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define VPWM_TC_RUN_MODE                    (0lu)
#define VPWM_TC_COUNTER_MODE                (0lu)
#define VPWM_TC_COMP_CAP_MODE               (2lu)
#define VPWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define VPWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define VPWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define VPWM_TC_START_SIGNAL_MODE           (0lu)
#define VPWM_TC_STOP_SIGNAL_MODE            (0lu)
#define VPWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define VPWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define VPWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define VPWM_TC_START_SIGNAL_PRESENT        (0lu)
#define VPWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define VPWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define VPWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define VPWM_PWM_KILL_EVENT                 (0lu)
#define VPWM_PWM_STOP_EVENT                 (0lu)
#define VPWM_PWM_MODE                       (5lu)
#define VPWM_PWM_OUT_N_INVERT               (0lu)
#define VPWM_PWM_OUT_INVERT                 (0lu)
#define VPWM_PWM_ALIGN                      (2lu)
#define VPWM_PWM_RUN_MODE                   (0lu)
#define VPWM_PWM_DEAD_TIME_CYCLE            (255lu)
#define VPWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define VPWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define VPWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define VPWM_PWM_START_SIGNAL_MODE          (3lu)
#define VPWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define VPWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define VPWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define VPWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define VPWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define VPWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define VPWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define VPWM_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define VPWM_TC_PERIOD_VALUE                (65535lu)
#define VPWM_TC_COMPARE_VALUE               (65535lu)
#define VPWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define VPWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define VPWM_PWM_PERIOD_VALUE               (4096lu)
#define VPWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define VPWM_PWM_PERIOD_SWAP                (0lu)
#define VPWM_PWM_COMPARE_VALUE              (1lu)
#define VPWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define VPWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define VPWM__LEFT 0
#define VPWM__RIGHT 1
#define VPWM__CENTER 2
#define VPWM__ASYMMETRIC 3

#define VPWM__X1 0
#define VPWM__X2 1
#define VPWM__X4 2

#define VPWM__PWM 4
#define VPWM__PWM_DT 5
#define VPWM__PWM_PR 6

#define VPWM__INVERSE 1
#define VPWM__DIRECT 0

#define VPWM__CAPTURE 2
#define VPWM__COMPARE 0

#define VPWM__TRIG_LEVEL 3
#define VPWM__TRIG_RISING 0
#define VPWM__TRIG_FALLING 1
#define VPWM__TRIG_BOTH 2

#define VPWM__INTR_MASK_TC 1
#define VPWM__INTR_MASK_CC_MATCH 2
#define VPWM__INTR_MASK_NONE 0
#define VPWM__INTR_MASK_TC_CC 3

#define VPWM__UNCONFIG 8
#define VPWM__TIMER 1
#define VPWM__QUAD 3
#define VPWM__PWM_SEL 7

#define VPWM__COUNT_UP 0
#define VPWM__COUNT_DOWN 1
#define VPWM__COUNT_UPDOWN0 2
#define VPWM__COUNT_UPDOWN1 3


/* Prescaler */
#define VPWM_PRESCALE_DIVBY1                ((uint32)(0u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY2                ((uint32)(1u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY4                ((uint32)(2u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY8                ((uint32)(3u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY16               ((uint32)(4u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY32               ((uint32)(5u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY64               ((uint32)(6u << VPWM_PRESCALER_SHIFT))
#define VPWM_PRESCALE_DIVBY128              ((uint32)(7u << VPWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define VPWM_MODE_TIMER_COMPARE             ((uint32)(VPWM__COMPARE         <<  \
                                                                  VPWM_MODE_SHIFT))
#define VPWM_MODE_TIMER_CAPTURE             ((uint32)(VPWM__CAPTURE         <<  \
                                                                  VPWM_MODE_SHIFT))
#define VPWM_MODE_QUAD                      ((uint32)(VPWM__QUAD            <<  \
                                                                  VPWM_MODE_SHIFT))
#define VPWM_MODE_PWM                       ((uint32)(VPWM__PWM             <<  \
                                                                  VPWM_MODE_SHIFT))
#define VPWM_MODE_PWM_DT                    ((uint32)(VPWM__PWM_DT          <<  \
                                                                  VPWM_MODE_SHIFT))
#define VPWM_MODE_PWM_PR                    ((uint32)(VPWM__PWM_PR          <<  \
                                                                  VPWM_MODE_SHIFT))

/* Quad Modes */
#define VPWM_MODE_X1                        ((uint32)(VPWM__X1              <<  \
                                                                  VPWM_QUAD_MODE_SHIFT))
#define VPWM_MODE_X2                        ((uint32)(VPWM__X2              <<  \
                                                                  VPWM_QUAD_MODE_SHIFT))
#define VPWM_MODE_X4                        ((uint32)(VPWM__X4              <<  \
                                                                  VPWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define VPWM_COUNT_UP                       ((uint32)(VPWM__COUNT_UP        <<  \
                                                                  VPWM_UPDOWN_SHIFT))
#define VPWM_COUNT_DOWN                     ((uint32)(VPWM__COUNT_DOWN      <<  \
                                                                  VPWM_UPDOWN_SHIFT))
#define VPWM_COUNT_UPDOWN0                  ((uint32)(VPWM__COUNT_UPDOWN0   <<  \
                                                                  VPWM_UPDOWN_SHIFT))
#define VPWM_COUNT_UPDOWN1                  ((uint32)(VPWM__COUNT_UPDOWN1   <<  \
                                                                  VPWM_UPDOWN_SHIFT))

/* PWM output invert */
#define VPWM_INVERT_LINE                    ((uint32)(VPWM__INVERSE         <<  \
                                                                  VPWM_INV_OUT_SHIFT))
#define VPWM_INVERT_LINE_N                  ((uint32)(VPWM__INVERSE         <<  \
                                                                  VPWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define VPWM_TRIG_RISING                    ((uint32)VPWM__TRIG_RISING)
#define VPWM_TRIG_FALLING                   ((uint32)VPWM__TRIG_FALLING)
#define VPWM_TRIG_BOTH                      ((uint32)VPWM__TRIG_BOTH)
#define VPWM_TRIG_LEVEL                     ((uint32)VPWM__TRIG_LEVEL)

/* Interrupt mask */
#define VPWM_INTR_MASK_TC                   ((uint32)VPWM__INTR_MASK_TC)
#define VPWM_INTR_MASK_CC_MATCH             ((uint32)VPWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define VPWM_CC_MATCH_SET                   (0x00u)
#define VPWM_CC_MATCH_CLEAR                 (0x01u)
#define VPWM_CC_MATCH_INVERT                (0x02u)
#define VPWM_CC_MATCH_NO_CHANGE             (0x03u)
#define VPWM_OVERLOW_SET                    (0x00u)
#define VPWM_OVERLOW_CLEAR                  (0x04u)
#define VPWM_OVERLOW_INVERT                 (0x08u)
#define VPWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define VPWM_UNDERFLOW_SET                  (0x00u)
#define VPWM_UNDERFLOW_CLEAR                (0x10u)
#define VPWM_UNDERFLOW_INVERT               (0x20u)
#define VPWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define VPWM_PWM_MODE_LEFT                  (VPWM_CC_MATCH_CLEAR        |   \
                                                         VPWM_OVERLOW_SET           |   \
                                                         VPWM_UNDERFLOW_NO_CHANGE)
#define VPWM_PWM_MODE_RIGHT                 (VPWM_CC_MATCH_SET          |   \
                                                         VPWM_OVERLOW_NO_CHANGE     |   \
                                                         VPWM_UNDERFLOW_CLEAR)
#define VPWM_PWM_MODE_ASYM                  (VPWM_CC_MATCH_INVERT       |   \
                                                         VPWM_OVERLOW_SET           |   \
                                                         VPWM_UNDERFLOW_CLEAR)

#if (VPWM_CY_TCPWM_V2)
    #if(VPWM_CY_TCPWM_4000)
        #define VPWM_PWM_MODE_CENTER                (VPWM_CC_MATCH_INVERT       |   \
                                                                 VPWM_OVERLOW_NO_CHANGE     |   \
                                                                 VPWM_UNDERFLOW_CLEAR)
    #else
        #define VPWM_PWM_MODE_CENTER                (VPWM_CC_MATCH_INVERT       |   \
                                                                 VPWM_OVERLOW_SET           |   \
                                                                 VPWM_UNDERFLOW_CLEAR)
    #endif /* (VPWM_CY_TCPWM_4000) */
#else
    #define VPWM_PWM_MODE_CENTER                (VPWM_CC_MATCH_INVERT       |   \
                                                             VPWM_OVERLOW_NO_CHANGE     |   \
                                                             VPWM_UNDERFLOW_CLEAR)
#endif /* (VPWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define VPWM_CMD_CAPTURE                    (0u)
#define VPWM_CMD_RELOAD                     (8u)
#define VPWM_CMD_STOP                       (16u)
#define VPWM_CMD_START                      (24u)

/* Status */
#define VPWM_STATUS_DOWN                    (1u)
#define VPWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   VPWM_Init(void);
void   VPWM_Enable(void);
void   VPWM_Start(void);
void   VPWM_Stop(void);

void   VPWM_SetMode(uint32 mode);
void   VPWM_SetCounterMode(uint32 counterMode);
void   VPWM_SetPWMMode(uint32 modeMask);
void   VPWM_SetQDMode(uint32 qdMode);

void   VPWM_SetPrescaler(uint32 prescaler);
void   VPWM_TriggerCommand(uint32 mask, uint32 command);
void   VPWM_SetOneShot(uint32 oneShotEnable);
uint32 VPWM_ReadStatus(void);

void   VPWM_SetPWMSyncKill(uint32 syncKillEnable);
void   VPWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   VPWM_SetPWMDeadTime(uint32 deadTime);
void   VPWM_SetPWMInvert(uint32 mask);

void   VPWM_SetInterruptMode(uint32 interruptMask);
uint32 VPWM_GetInterruptSourceMasked(void);
uint32 VPWM_GetInterruptSource(void);
void   VPWM_ClearInterrupt(uint32 interruptMask);
void   VPWM_SetInterrupt(uint32 interruptMask);

void   VPWM_WriteCounter(uint32 count);
uint32 VPWM_ReadCounter(void);

uint32 VPWM_ReadCapture(void);
uint32 VPWM_ReadCaptureBuf(void);

void   VPWM_WritePeriod(uint32 period);
uint32 VPWM_ReadPeriod(void);
void   VPWM_WritePeriodBuf(uint32 periodBuf);
uint32 VPWM_ReadPeriodBuf(void);

void   VPWM_WriteCompare(uint32 compare);
uint32 VPWM_ReadCompare(void);
void   VPWM_WriteCompareBuf(uint32 compareBuf);
uint32 VPWM_ReadCompareBuf(void);

void   VPWM_SetPeriodSwap(uint32 swapEnable);
void   VPWM_SetCompareSwap(uint32 swapEnable);

void   VPWM_SetCaptureMode(uint32 triggerMode);
void   VPWM_SetReloadMode(uint32 triggerMode);
void   VPWM_SetStartMode(uint32 triggerMode);
void   VPWM_SetStopMode(uint32 triggerMode);
void   VPWM_SetCountMode(uint32 triggerMode);

void   VPWM_SaveConfig(void);
void   VPWM_RestoreConfig(void);
void   VPWM_Sleep(void);
void   VPWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define VPWM_BLOCK_CONTROL_REG              (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define VPWM_BLOCK_CONTROL_PTR              ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define VPWM_COMMAND_REG                    (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define VPWM_COMMAND_PTR                    ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define VPWM_INTRRUPT_CAUSE_REG             (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define VPWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define VPWM_CONTROL_REG                    (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__CTRL )
#define VPWM_CONTROL_PTR                    ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__CTRL )
#define VPWM_STATUS_REG                     (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__STATUS )
#define VPWM_STATUS_PTR                     ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__STATUS )
#define VPWM_COUNTER_REG                    (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__COUNTER )
#define VPWM_COUNTER_PTR                    ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__COUNTER )
#define VPWM_COMP_CAP_REG                   (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__CC )
#define VPWM_COMP_CAP_PTR                   ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__CC )
#define VPWM_COMP_CAP_BUF_REG               (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define VPWM_COMP_CAP_BUF_PTR               ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define VPWM_PERIOD_REG                     (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__PERIOD )
#define VPWM_PERIOD_PTR                     ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__PERIOD )
#define VPWM_PERIOD_BUF_REG                 (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define VPWM_PERIOD_BUF_PTR                 ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define VPWM_TRIG_CONTROL0_REG              (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define VPWM_TRIG_CONTROL0_PTR              ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define VPWM_TRIG_CONTROL1_REG              (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define VPWM_TRIG_CONTROL1_PTR              ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define VPWM_TRIG_CONTROL2_REG              (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define VPWM_TRIG_CONTROL2_PTR              ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define VPWM_INTERRUPT_REQ_REG              (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR )
#define VPWM_INTERRUPT_REQ_PTR              ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR )
#define VPWM_INTERRUPT_SET_REG              (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define VPWM_INTERRUPT_SET_PTR              ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define VPWM_INTERRUPT_MASK_REG             (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define VPWM_INTERRUPT_MASK_PTR             ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define VPWM_INTERRUPT_MASKED_REG           (*(reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define VPWM_INTERRUPT_MASKED_PTR           ( (reg32 *) VPWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define VPWM_MASK                           ((uint32)VPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define VPWM_RELOAD_CC_SHIFT                (0u)
#define VPWM_RELOAD_PERIOD_SHIFT            (1u)
#define VPWM_PWM_SYNC_KILL_SHIFT            (2u)
#define VPWM_PWM_STOP_KILL_SHIFT            (3u)
#define VPWM_PRESCALER_SHIFT                (8u)
#define VPWM_UPDOWN_SHIFT                   (16u)
#define VPWM_ONESHOT_SHIFT                  (18u)
#define VPWM_QUAD_MODE_SHIFT                (20u)
#define VPWM_INV_OUT_SHIFT                  (20u)
#define VPWM_INV_COMPL_OUT_SHIFT            (21u)
#define VPWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define VPWM_RELOAD_CC_MASK                 ((uint32)(VPWM_1BIT_MASK        <<  \
                                                                            VPWM_RELOAD_CC_SHIFT))
#define VPWM_RELOAD_PERIOD_MASK             ((uint32)(VPWM_1BIT_MASK        <<  \
                                                                            VPWM_RELOAD_PERIOD_SHIFT))
#define VPWM_PWM_SYNC_KILL_MASK             ((uint32)(VPWM_1BIT_MASK        <<  \
                                                                            VPWM_PWM_SYNC_KILL_SHIFT))
#define VPWM_PWM_STOP_KILL_MASK             ((uint32)(VPWM_1BIT_MASK        <<  \
                                                                            VPWM_PWM_STOP_KILL_SHIFT))
#define VPWM_PRESCALER_MASK                 ((uint32)(VPWM_8BIT_MASK        <<  \
                                                                            VPWM_PRESCALER_SHIFT))
#define VPWM_UPDOWN_MASK                    ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                            VPWM_UPDOWN_SHIFT))
#define VPWM_ONESHOT_MASK                   ((uint32)(VPWM_1BIT_MASK        <<  \
                                                                            VPWM_ONESHOT_SHIFT))
#define VPWM_QUAD_MODE_MASK                 ((uint32)(VPWM_3BIT_MASK        <<  \
                                                                            VPWM_QUAD_MODE_SHIFT))
#define VPWM_INV_OUT_MASK                   ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                            VPWM_INV_OUT_SHIFT))
#define VPWM_MODE_MASK                      ((uint32)(VPWM_3BIT_MASK        <<  \
                                                                            VPWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define VPWM_CAPTURE_SHIFT                  (0u)
#define VPWM_COUNT_SHIFT                    (2u)
#define VPWM_RELOAD_SHIFT                   (4u)
#define VPWM_STOP_SHIFT                     (6u)
#define VPWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define VPWM_CAPTURE_MASK                   ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                  VPWM_CAPTURE_SHIFT))
#define VPWM_COUNT_MASK                     ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                  VPWM_COUNT_SHIFT))
#define VPWM_RELOAD_MASK                    ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                  VPWM_RELOAD_SHIFT))
#define VPWM_STOP_MASK                      ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                  VPWM_STOP_SHIFT))
#define VPWM_START_MASK                     ((uint32)(VPWM_2BIT_MASK        <<  \
                                                                  VPWM_START_SHIFT))

/* MASK */
#define VPWM_1BIT_MASK                      ((uint32)0x01u)
#define VPWM_2BIT_MASK                      ((uint32)0x03u)
#define VPWM_3BIT_MASK                      ((uint32)0x07u)
#define VPWM_6BIT_MASK                      ((uint32)0x3Fu)
#define VPWM_8BIT_MASK                      ((uint32)0xFFu)
#define VPWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define VPWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define VPWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(VPWM_QUAD_ENCODING_MODES     << VPWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(VPWM_CONFIG                  << VPWM_MODE_SHIFT)))

#define VPWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(VPWM_PWM_STOP_EVENT          << VPWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(VPWM_PWM_OUT_INVERT          << VPWM_INV_OUT_SHIFT))         |\
         ((uint32)(VPWM_PWM_OUT_N_INVERT        << VPWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(VPWM_PWM_MODE                << VPWM_MODE_SHIFT)))

#define VPWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(VPWM_PWM_RUN_MODE         << VPWM_ONESHOT_SHIFT))
            
#define VPWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(VPWM_PWM_ALIGN            << VPWM_UPDOWN_SHIFT))

#define VPWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(VPWM_PWM_KILL_EVENT      << VPWM_PWM_SYNC_KILL_SHIFT))

#define VPWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(VPWM_PWM_DEAD_TIME_CYCLE  << VPWM_PRESCALER_SHIFT))

#define VPWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(VPWM_PWM_PRESCALER        << VPWM_PRESCALER_SHIFT))

#define VPWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(VPWM_TC_PRESCALER            << VPWM_PRESCALER_SHIFT))       |\
         ((uint32)(VPWM_TC_COUNTER_MODE         << VPWM_UPDOWN_SHIFT))          |\
         ((uint32)(VPWM_TC_RUN_MODE             << VPWM_ONESHOT_SHIFT))         |\
         ((uint32)(VPWM_TC_COMP_CAP_MODE        << VPWM_MODE_SHIFT)))
        
#define VPWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(VPWM_QUAD_PHIA_SIGNAL_MODE   << VPWM_COUNT_SHIFT))           |\
         ((uint32)(VPWM_QUAD_INDEX_SIGNAL_MODE  << VPWM_RELOAD_SHIFT))          |\
         ((uint32)(VPWM_QUAD_STOP_SIGNAL_MODE   << VPWM_STOP_SHIFT))            |\
         ((uint32)(VPWM_QUAD_PHIB_SIGNAL_MODE   << VPWM_START_SHIFT)))

#define VPWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(VPWM_PWM_SWITCH_SIGNAL_MODE  << VPWM_CAPTURE_SHIFT))         |\
         ((uint32)(VPWM_PWM_COUNT_SIGNAL_MODE   << VPWM_COUNT_SHIFT))           |\
         ((uint32)(VPWM_PWM_RELOAD_SIGNAL_MODE  << VPWM_RELOAD_SHIFT))          |\
         ((uint32)(VPWM_PWM_STOP_SIGNAL_MODE    << VPWM_STOP_SHIFT))            |\
         ((uint32)(VPWM_PWM_START_SIGNAL_MODE   << VPWM_START_SHIFT)))

#define VPWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(VPWM_TC_CAPTURE_SIGNAL_MODE  << VPWM_CAPTURE_SHIFT))         |\
         ((uint32)(VPWM_TC_COUNT_SIGNAL_MODE    << VPWM_COUNT_SHIFT))           |\
         ((uint32)(VPWM_TC_RELOAD_SIGNAL_MODE   << VPWM_RELOAD_SHIFT))          |\
         ((uint32)(VPWM_TC_STOP_SIGNAL_MODE     << VPWM_STOP_SHIFT))            |\
         ((uint32)(VPWM_TC_START_SIGNAL_MODE    << VPWM_START_SHIFT)))
        
#define VPWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((VPWM__COUNT_UPDOWN0 == VPWM_TC_COUNTER_MODE)                  ||\
                 (VPWM__COUNT_UPDOWN1 == VPWM_TC_COUNTER_MODE))

#define VPWM_PWM_UPDOWN_CNT_USED                                                            \
                ((VPWM__CENTER == VPWM_PWM_ALIGN)                               ||\
                 (VPWM__ASYMMETRIC == VPWM_PWM_ALIGN))               
        
#define VPWM_PWM_PR_INIT_VALUE              (1u)
#define VPWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_VPWM_H */

/* [] END OF FILE */
