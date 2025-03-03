/*
 * Zadanie_1.c
 *
 * Created: 03.03.2025 11:09:54
 * Author : student
 */ 

 #include <avr/io.h>
 #define F_CPU 16000000UL //określamy jaki jest zegar przed biblioteką
 #include <util/delay.h>
 
 #define diodyDDR DDRA
 #define diody PORTA
 uint8_t i;
 uint8_t a;
 
 int main(void)
 {
     diodyDDR = 0xff;
     diody = 0b11111111;	
     while (1) 
     {
         for(i=0; i<8;i++){
             diody = (1<<i);
             _delay_ms(500);
             }
     }
 }
 
 