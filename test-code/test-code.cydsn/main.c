/* ========================================

    current[mA]=1000*millivolts/(20*Rsense[ohm])=5*millivolts
    current_limit[mA]=40*current_setting
    
   ======================================== */
    
#include <project.h>


int main() {
    
    //"board powered" signal
    vin_Write(1);

    VPWM_Start();
    //WPWM_Start();

    
    // Enable global interrupts
    CyGlobalIntEnable;
    
    for(;;) {
        
    VPWM_WriteCompare(1000);
    //WPWM_WriteCompare(1);

    }
}



/* [] END OF FILE */