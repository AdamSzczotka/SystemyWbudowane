/*
 * Zadanie_1.c
 *
 * Created: 03.03.2025 11:09:54
 * Author : student
 */ 

 #include <avr/io.h>
 #define diodyDDR DDRA
 #define diody PORTA
 
 int main(void)
 {
     diodyDDR = 0xff;
     diody = 0b00110011;
     while (1) 
     {
     }
 }
 
 