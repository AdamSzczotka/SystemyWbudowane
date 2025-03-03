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
 
 int main(void)
 {
     diodyDDR = 0xff;
     diody = 0b11111111;
     _delay_ms(500);
     diody = 0b00000000;
     while (1) 
     {
     }
 }
 
 