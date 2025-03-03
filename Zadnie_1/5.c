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
 #define dioda 4
 
 int main(void)
 {
     diodyDDR = 0xff;
     diody = 0b11111111;
     _delay_ms(1000);
     diody &= ~(1<<dioda);//0b11101111 wyzerowanie wybranego bitu
     _delay_ms(1000);
     diody |=(1<<dioda);//ustawienie bitu
     _delay_ms(1000);
     //axor 0 = bez negacji
     //axor 1 = negacje
     diody ^= (1<<dioda);
     while (1) 
     {
     }
 }
 
 