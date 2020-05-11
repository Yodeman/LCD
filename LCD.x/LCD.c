
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>
#include "LCD.h"
#define _XTAL_FREQ 20000000

void main(void){
    
    PORTA=PORTB=PORTC=PORTE=0;
    TRISD = 0b00000000;
    PORTD = 0b00000000;
    
    Config_Display();
    
    __delay_ms(100);
    Clear_Screen();
    Set_Cursor(1);
    WriteString("Hello Michael Frodo");
    Set_Cursor(2);
    WriteString("How are you?");
    
    while(1){
        for(int i=0; i < 4; i++){
            __delay_ms(100);
            Display_Right();
        }
        for (int i=0; i < 4; i++){
            __delay_ms(100);
            Display_Left();
        }
    }

    
}