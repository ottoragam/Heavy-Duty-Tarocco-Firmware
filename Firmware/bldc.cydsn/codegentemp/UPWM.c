/*******************************************************************************
* File Name: UPWM.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the UPWM
*  component
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

#include "UPWM.h"

uint8 UPWM_initVar = 0u;


/*******************************************************************************
* Function Name: UPWM_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default UPWM configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (UPWM__QUAD == UPWM_CONFIG)
        UPWM_CONTROL_REG = UPWM_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        UPWM_TRIG_CONTROL1_REG  = UPWM_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        UPWM_SetInterruptMode(UPWM_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        UPWM_SetCounterMode(UPWM_COUNT_DOWN);
        UPWM_WritePeriod(UPWM_QUAD_PERIOD_INIT_VALUE);
        UPWM_WriteCounter(UPWM_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (UPWM__QUAD == UPWM_CONFIG) */

    #if (UPWM__TIMER == UPWM_CONFIG)
        UPWM_CONTROL_REG = UPWM_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        UPWM_TRIG_CONTROL1_REG  = UPWM_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        UPWM_SetInterruptMode(UPWM_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        UPWM_WritePeriod(UPWM_TC_PERIOD_VALUE );

        #if (UPWM__COMPARE == UPWM_TC_COMP_CAP_MODE)
            UPWM_WriteCompare(UPWM_TC_COMPARE_VALUE);

            #if (1u == UPWM_TC_COMPARE_SWAP)
                UPWM_SetCompareSwap(1u);
                UPWM_WriteCompareBuf(UPWM_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == UPWM_TC_COMPARE_SWAP) */
        #endif  /* (UPWM__COMPARE == UPWM_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (UPWM_CY_TCPWM_V2 && UPWM_TIMER_UPDOWN_CNT_USED && !UPWM_CY_TCPWM_4000)
            UPWM_WriteCounter(1u);
        #elif(UPWM__COUNT_DOWN == UPWM_TC_COUNTER_MODE)
            UPWM_WriteCounter(UPWM_TC_PERIOD_VALUE);
        #else
            UPWM_WriteCounter(0u);
        #endif /* (UPWM_CY_TCPWM_V2 && UPWM_TIMER_UPDOWN_CNT_USED && !UPWM_CY_TCPWM_4000) */
    #endif  /* (UPWM__TIMER == UPWM_CONFIG) */

    #if (UPWM__PWM_SEL == UPWM_CONFIG)
        UPWM_CONTROL_REG = UPWM_CTRL_PWM_BASE_CONFIG;

        #if (UPWM__PWM_PR == UPWM_PWM_MODE)
            UPWM_CONTROL_REG |= UPWM_CTRL_PWM_RUN_MODE;
            UPWM_WriteCounter(UPWM_PWM_PR_INIT_VALUE);
        #else
            UPWM_CONTROL_REG |= UPWM_CTRL_PWM_ALIGN | UPWM_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (UPWM_CY_TCPWM_V2 && UPWM_PWM_UPDOWN_CNT_USED && !UPWM_CY_TCPWM_4000)
                UPWM_WriteCounter(1u);
            #elif (UPWM__RIGHT == UPWM_PWM_ALIGN)
                UPWM_WriteCounter(UPWM_PWM_PERIOD_VALUE);
            #else 
                UPWM_WriteCounter(0u);
            #endif  /* (UPWM_CY_TCPWM_V2 && UPWM_PWM_UPDOWN_CNT_USED && !UPWM_CY_TCPWM_4000) */
        #endif  /* (UPWM__PWM_PR == UPWM_PWM_MODE) */

        #if (UPWM__PWM_DT == UPWM_PWM_MODE)
            UPWM_CONTROL_REG |= UPWM_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (UPWM__PWM_DT == UPWM_PWM_MODE) */

        #if (UPWM__PWM == UPWM_PWM_MODE)
            UPWM_CONTROL_REG |= UPWM_CTRL_PWM_PRESCALER;
        #endif  /* (UPWM__PWM == UPWM_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        UPWM_TRIG_CONTROL1_REG  = UPWM_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        UPWM_SetInterruptMode(UPWM_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (UPWM__PWM_PR == UPWM_PWM_MODE)
            UPWM_TRIG_CONTROL2_REG =
                    (UPWM_CC_MATCH_NO_CHANGE    |
                    UPWM_OVERLOW_NO_CHANGE      |
                    UPWM_UNDERFLOW_NO_CHANGE);
        #else
            #if (UPWM__LEFT == UPWM_PWM_ALIGN)
                UPWM_TRIG_CONTROL2_REG = UPWM_PWM_MODE_LEFT;
            #endif  /* ( UPWM_PWM_LEFT == UPWM_PWM_ALIGN) */

            #if (UPWM__RIGHT == UPWM_PWM_ALIGN)
                UPWM_TRIG_CONTROL2_REG = UPWM_PWM_MODE_RIGHT;
            #endif  /* ( UPWM_PWM_RIGHT == UPWM_PWM_ALIGN) */

            #if (UPWM__CENTER == UPWM_PWM_ALIGN)
                UPWM_TRIG_CONTROL2_REG = UPWM_PWM_MODE_CENTER;
            #endif  /* ( UPWM_PWM_CENTER == UPWM_PWM_ALIGN) */

            #if (UPWM__ASYMMETRIC == UPWM_PWM_ALIGN)
                UPWM_TRIG_CONTROL2_REG = UPWM_PWM_MODE_ASYM;
            #endif  /* (UPWM__ASYMMETRIC == UPWM_PWM_ALIGN) */
        #endif  /* (UPWM__PWM_PR == UPWM_PWM_MODE) */

        /* Set other values from customizer */
        UPWM_WritePeriod(UPWM_PWM_PERIOD_VALUE );
        UPWM_WriteCompare(UPWM_PWM_COMPARE_VALUE);

        #if (1u == UPWM_PWM_COMPARE_SWAP)
            UPWM_SetCompareSwap(1u);
            UPWM_WriteCompareBuf(UPWM_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == UPWM_PWM_COMPARE_SWAP) */

        #if (1u == UPWM_PWM_PERIOD_SWAP)
            UPWM_SetPeriodSwap(1u);
            UPWM_WritePeriodBuf(UPWM_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == UPWM_PWM_PERIOD_SWAP) */
    #endif  /* (UPWM__PWM_SEL == UPWM_CONFIG) */
    
}


/*******************************************************************************
* Function Name: UPWM_Enable
********************************************************************************
*
* Summary:
*  Enables the UPWM.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    UPWM_BLOCK_CONTROL_REG |= UPWM_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (UPWM__PWM_SEL == UPWM_CONFIG)
        #if (0u == UPWM_PWM_START_SIGNAL_PRESENT)
            UPWM_TriggerCommand(UPWM_MASK, UPWM_CMD_START);
        #endif /* (0u == UPWM_PWM_START_SIGNAL_PRESENT) */
    #endif /* (UPWM__PWM_SEL == UPWM_CONFIG) */

    #if (UPWM__TIMER == UPWM_CONFIG)
        #if (0u == UPWM_TC_START_SIGNAL_PRESENT)
            UPWM_TriggerCommand(UPWM_MASK, UPWM_CMD_START);
        #endif /* (0u == UPWM_TC_START_SIGNAL_PRESENT) */
    #endif /* (UPWM__TIMER == UPWM_CONFIG) */
    
    #if (UPWM__QUAD == UPWM_CONFIG)
        #if (0u != UPWM_QUAD_AUTO_START)
            UPWM_TriggerCommand(UPWM_MASK, UPWM_CMD_RELOAD);
        #endif /* (0u != UPWM_QUAD_AUTO_START) */
    #endif  /* (UPWM__QUAD == UPWM_CONFIG) */
}


/*******************************************************************************
* Function Name: UPWM_Start
********************************************************************************
*
* Summary:
*  Initializes the UPWM with default customizer
*  values when called the first time and enables the UPWM.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UPWM_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time UPWM_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the UPWM_Start() routine.
*
*******************************************************************************/
void UPWM_Start(void)
{
    if (0u == UPWM_initVar)
    {
        UPWM_Init();
        UPWM_initVar = 1u;
    }

    UPWM_Enable();
}


/*******************************************************************************
* Function Name: UPWM_Stop
********************************************************************************
*
* Summary:
*  Disables the UPWM.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_BLOCK_CONTROL_REG &= (uint32)~UPWM_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the UPWM. This function is used when
*  configured as a generic UPWM and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the UPWM to operate in
*   Values:
*   - UPWM_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - UPWM_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - UPWM_MODE_QUAD - Quadrature decoder
*         - UPWM_MODE_PWM - PWM
*         - UPWM_MODE_PWM_DT - PWM with dead time
*         - UPWM_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_MODE_MASK;
    UPWM_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - UPWM_MODE_X1 - Counts on phi 1 rising
*         - UPWM_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - UPWM_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_QUAD_MODE_MASK;
    UPWM_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - UPWM_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - UPWM_PRESCALE_DIVBY2    - Divide by 2
*         - UPWM_PRESCALE_DIVBY4    - Divide by 4
*         - UPWM_PRESCALE_DIVBY8    - Divide by 8
*         - UPWM_PRESCALE_DIVBY16   - Divide by 16
*         - UPWM_PRESCALE_DIVBY32   - Divide by 32
*         - UPWM_PRESCALE_DIVBY64   - Divide by 64
*         - UPWM_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_PRESCALER_MASK;
    UPWM_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the UPWM runs
*  continuously or stops when terminal count is reached.  By default the
*  UPWM operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_ONESHOT_MASK;
    UPWM_CONTROL_REG |= ((uint32)((oneShotEnable & UPWM_1BIT_MASK) <<
                                                               UPWM_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPWMMode(uint32 modeMask)
{
    UPWM_TRIG_CONTROL2_REG = (modeMask & UPWM_6BIT_MASK);
}



/*******************************************************************************
* Function Name: UPWM_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_PWM_SYNC_KILL_MASK;
    UPWM_CONTROL_REG |= ((uint32)((syncKillEnable & UPWM_1BIT_MASK)  <<
                                               UPWM_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_PWM_STOP_KILL_MASK;
    UPWM_CONTROL_REG |= ((uint32)((stopOnKillEnable & UPWM_1BIT_MASK)  <<
                                                         UPWM_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_PRESCALER_MASK;
    UPWM_CONTROL_REG |= ((uint32)((deadTime & UPWM_8BIT_MASK) <<
                                                          UPWM_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - UPWM_INVERT_LINE   - Inverts the line output
*         - UPWM_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_INV_OUT_MASK;
    UPWM_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: UPWM_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_WriteCounter(uint32 count)
{
    UPWM_COUNTER_REG = (count & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 UPWM_ReadCounter(void)
{
    return (UPWM_COUNTER_REG & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - UPWM_COUNT_UP       - Counts up
*     - UPWM_COUNT_DOWN     - Counts down
*     - UPWM_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - UPWM_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_UPDOWN_MASK;
    UPWM_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_WritePeriod(uint32 period)
{
    UPWM_PERIOD_REG = (period & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 UPWM_ReadPeriod(void)
{
    return (UPWM_PERIOD_REG & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_RELOAD_CC_MASK;
    UPWM_CONTROL_REG |= (swapEnable & UPWM_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_WritePeriodBuf(uint32 periodBuf)
{
    UPWM_PERIOD_BUF_REG = (periodBuf & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 UPWM_ReadPeriodBuf(void)
{
    return (UPWM_PERIOD_BUF_REG & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_CONTROL_REG &= (uint32)~UPWM_RELOAD_PERIOD_MASK;
    UPWM_CONTROL_REG |= ((uint32)((swapEnable & UPWM_1BIT_MASK) <<
                                                            UPWM_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void UPWM_WriteCompare(uint32 compare)
{
    #if (UPWM_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (UPWM_CY_TCPWM_4000) */

    #if (UPWM_CY_TCPWM_4000)
        currentMode = ((UPWM_CONTROL_REG & UPWM_UPDOWN_MASK) >> UPWM_UPDOWN_SHIFT);

        if (((uint32)UPWM__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)UPWM__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (UPWM_CY_TCPWM_4000) */
    
    UPWM_COMP_CAP_REG = (compare & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 UPWM_ReadCompare(void)
{
    #if (UPWM_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (UPWM_CY_TCPWM_4000) */

    #if (UPWM_CY_TCPWM_4000)
        currentMode = ((UPWM_CONTROL_REG & UPWM_UPDOWN_MASK) >> UPWM_UPDOWN_SHIFT);
        
        regVal = UPWM_COMP_CAP_REG;
        
        if (((uint32)UPWM__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)UPWM__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & UPWM_16BIT_MASK);
    #else
        return (UPWM_COMP_CAP_REG & UPWM_16BIT_MASK);
    #endif /* (UPWM_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: UPWM_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void UPWM_WriteCompareBuf(uint32 compareBuf)
{
    #if (UPWM_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (UPWM_CY_TCPWM_4000) */

    #if (UPWM_CY_TCPWM_4000)
        currentMode = ((UPWM_CONTROL_REG & UPWM_UPDOWN_MASK) >> UPWM_UPDOWN_SHIFT);

        if (((uint32)UPWM__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)UPWM__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (UPWM_CY_TCPWM_4000) */
    
    UPWM_COMP_CAP_BUF_REG = (compareBuf & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 UPWM_ReadCompareBuf(void)
{
    #if (UPWM_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (UPWM_CY_TCPWM_4000) */

    #if (UPWM_CY_TCPWM_4000)
        currentMode = ((UPWM_CONTROL_REG & UPWM_UPDOWN_MASK) >> UPWM_UPDOWN_SHIFT);

        regVal = UPWM_COMP_CAP_BUF_REG;
        
        if (((uint32)UPWM__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)UPWM__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & UPWM_16BIT_MASK);
    #else
        return (UPWM_COMP_CAP_BUF_REG & UPWM_16BIT_MASK);
    #endif /* (UPWM_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: UPWM_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 UPWM_ReadCapture(void)
{
    return (UPWM_COMP_CAP_REG & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 UPWM_ReadCaptureBuf(void)
{
    return (UPWM_COMP_CAP_BUF_REG & UPWM_16BIT_MASK);
}


/*******************************************************************************
* Function Name: UPWM_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UPWM_TRIG_LEVEL     - Level
*     - UPWM_TRIG_RISING    - Rising edge
*     - UPWM_TRIG_FALLING   - Falling edge
*     - UPWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_TRIG_CONTROL1_REG &= (uint32)~UPWM_CAPTURE_MASK;
    UPWM_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UPWM_TRIG_LEVEL     - Level
*     - UPWM_TRIG_RISING    - Rising edge
*     - UPWM_TRIG_FALLING   - Falling edge
*     - UPWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_TRIG_CONTROL1_REG &= (uint32)~UPWM_RELOAD_MASK;
    UPWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UPWM_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UPWM_TRIG_LEVEL     - Level
*     - UPWM_TRIG_RISING    - Rising edge
*     - UPWM_TRIG_FALLING   - Falling edge
*     - UPWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_TRIG_CONTROL1_REG &= (uint32)~UPWM_START_MASK;
    UPWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UPWM_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UPWM_TRIG_LEVEL     - Level
*     - UPWM_TRIG_RISING    - Rising edge
*     - UPWM_TRIG_FALLING   - Falling edge
*     - UPWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_TRIG_CONTROL1_REG &= (uint32)~UPWM_STOP_MASK;
    UPWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UPWM_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - UPWM_TRIG_LEVEL     - Level
*     - UPWM_TRIG_RISING    - Rising edge
*     - UPWM_TRIG_FALLING   - Falling edge
*     - UPWM_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_TRIG_CONTROL1_REG &= (uint32)~UPWM_COUNT_MASK;
    UPWM_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << UPWM_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - UPWM_CMD_CAPTURE    - Trigger Capture/Switch command
*     - UPWM_CMD_RELOAD     - Trigger Reload/Index command
*     - UPWM_CMD_STOP       - Trigger Stop/Kill command
*     - UPWM_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    UPWM_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UPWM_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the UPWM.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - UPWM_STATUS_DOWN    - Set if counting down
*     - UPWM_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 UPWM_ReadStatus(void)
{
    return ((UPWM_STATUS_REG >> UPWM_RUNNING_STATUS_SHIFT) |
            (UPWM_STATUS_REG & UPWM_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: UPWM_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - UPWM_INTR_MASK_TC       - Terminal count mask
*     - UPWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetInterruptMode(uint32 interruptMask)
{
    UPWM_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: UPWM_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - UPWM_INTR_MASK_TC       - Terminal count mask
*     - UPWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 UPWM_GetInterruptSourceMasked(void)
{
    return (UPWM_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: UPWM_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - UPWM_INTR_MASK_TC       - Terminal count mask
*     - UPWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 UPWM_GetInterruptSource(void)
{
    return (UPWM_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: UPWM_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - UPWM_INTR_MASK_TC       - Terminal count mask
*     - UPWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_ClearInterrupt(uint32 interruptMask)
{
    UPWM_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: UPWM_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - UPWM_INTR_MASK_TC       - Terminal count mask
*     - UPWM_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void UPWM_SetInterrupt(uint32 interruptMask)
{
    UPWM_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
