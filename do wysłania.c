/*
Z MRYGANIEM
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#define segmentyDDR DDRA
#define segmenty PORTA
#define cyfraDDR DDRB
#define cyfra PORTB


uint8_t seg7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

uint8_t dane[] = {2, 0, 2, 5};

ISR(TIMER1_COMPA_vect){
	static uint8_t i = 0;
	cyfra |= (1<<i);
	if (i++==3) i=0;
	segmenty = seg7[dane[i]];
	cyfra &= ~(1<<i);
}

int main(void)
{	
	segmentyDDR = 0xff;
	segmenty = 0xff;
	cyfraDDR = 0x0f;
	TCCR1B = (1<<WGM12)|(1<<CS12); // tryb CTC i preskaler 256
	OCR1A = 62500;
	TIMSK = (1<<OCIE1A); // w??czenie przerwania od porównania czesci A
	sei(); //globalne w??czenie przerwa? (biblioteka interupt)
	
	
	
    while (1) 
    {
		
	}
}

/*
BEZ MRYGANIA 
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #define F_CPU 16000000UL
 #define segmentyDDR DDRA
 #define segmenty PORTA
 #define cyfraDDR DDRB
 #define cyfra PORTB
 
 
 uint8_t seg7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
 
 uint8_t dane[] = {2, 0, 2, 5};
 
 ISR(TIMER1_COMPA_vect){
	 static uint8_t i = 0;
	 cyfra |= (1<<i);
	 if (i++==3) i=0;
	 segmenty = seg7[dane[i]];
	 cyfra &= ~(1<<i);
 }
 
 ISR(TIMER0_OVF_vect)
 {
	 static uint8_t i = 0;
	 cyfra |= (1<<i);
	 if (i++==3) i=0;
	 segmenty = seg7[dane[i]];
	 cyfra &= ~(1<<i);
 }
 
 int main(void)
 {	
	 segmentyDDR = 0xff;
	 segmenty = 0xff;
	 cyfraDDR = 0x0f;
	 TCCR1B = (1<<WGM12)|(1<<CS12); // tryb CTC i preskaler 256
	 OCR1A = 62500;
	 TIMSK = (1<<OCIE1A); // w??czenie przerwania od porównania Timer1 czesci A
	 TCCR0 = (1<<CS02);
	 TIMSK |= (1<<TOIE0);//włączenie przerwanie od przepełnienia Timer0 gdy nie dasz | to tracisz rejestr
	 
	 sei(); //globalne w??czenie przerwa? (biblioteka interupt)
	 
	 
	 
	 while (1) 
	 {
		 
	 }
 }
 
 /*
 * 17_03_2025.c
 *
 * Created: 17/03/2025 10:42:43
 * Author :
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#define segmentyDDR DDRA
#define segmenty PORTA
#define cyfraDDR DDRB
#define cyfra PORTB


uint8_t seg7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

uint8_t dane[] = {2, 0, 2, 5};

ISR(TIMER1_COMPA_vect)
{
    // Inkrementacja tablicy dane jako liczby
    for (int8_t i = 3; i >= 0; i--) {
        if (dane[i] < 9) {
            dane[i]++;
            break;
        } else {
            dane[i] = 0;
        }
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint8_t i = 0;
	cyfra |= (1<<i);
	if (i++==3) i=0;
	segmenty = seg7[dane[i]];
	cyfra &= ~(1<<i);
}

int main(void)
{    
	segmentyDDR = 0xff;
	segmenty = 0xff;
	cyfraDDR = 0x0f;
	TCCR1B = (1<<WGM12)|(1<<CS12); // tryb CTC i preskaler 256
	OCR1A = 62500;
	TIMSK = (1<<OCIE1A); // włączenie przerwania od porównania Timer1 część A
	TCCR0 = (1<<CS02);
	TIMSK |= (1<<TOIE0);// włączenie przerwania od przepełnienia Timer0
	
	sei(); // globalne włączenie przerwań
	
    while (1) 
    {
        
    }
}
// przycisk w timerze, badamy dwa razy czy kliknięty i dwa czy puszczony
/*
 * 17_03_2025.c
 *
 * Created: 17/03/2025 10:42:43
 * Author :
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #define F_CPU 16000000UL
 #define segmentyDDR DDRA
 #define segmenty PORTA
 #define cyfraDDR DDRB
 #define cyfra PORTB
 #define przycisk1 7
 #define klawiatura PINB // sprawdzam czy przycisk 1 ma wartośc 0 gdy jest wciśnięty
 volatile uint8_t klawisz1=0; // nie optamilizuj zmiennej ; służy do liczenia wciśnięć
 
 
 uint8_t seg7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
 
 volatile uint8_t dane[] = {2, 0, 2, 5};
 
 ISR(TIMER1_COMPA_vect)
 {
	 // Inkrementacja tablicy dane jako liczby
	 for (int8_t i = 3; i >= 0; i--) {
		 if (dane[i] < 9) {
			 dane[i]++;
			 break;
		 } else {
			 dane[i] = 0;
		 }
	 }
 }
 
 ISR(TIMER0_OVF_vect)
 {
	 static uint8_t i = 0;
	 cyfra |= (1<<i);
	 if (i++==3) i=0;
	 segmenty = seg7[dane[i]];
	 cyfra &= ~(1<<i);
	 // przyciski tak jest źle
	 if (!(klawiatura & (1<<przycisk1)))
	 {
		 if (dane[0]++==9)
		 {
			 dane[0]=0;
		 }
	 }
 }
 
 int main(void)
 {    
	 segmentyDDR = 0xff;
	 segmenty = 0xff;
	 cyfraDDR = 0x0f;
	 cyfra |= (1<<przycisk1);//włączenie rezystora polaryzującego pullup
	 TCCR1B = (1<<WGM12)|(1<<CS12); // tryb CTC i preskaler 256
	 OCR1A = 62500;
	 TIMSK = (1<<OCIE1A); // włączenie przerwania od porównania Timer1 część A
	 TCCR0 = (1<<CS02);
	 TIMSK |= (1<<TOIE0);// włączenie przerwania od przepełnienia Timer0
	 
	 sei(); // globalne włączenie przerwań
	 
	 while (1) 
	 {
		 
	 }
 }
 
 /*
 * 17_03_2025.c
 *
 * Created: 17/03/2025 10:42:43
 * Author :
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#define segmentyDDR DDRA
#define segmenty PORTA
#define cyfraDDR DDRB
#define cyfra PORTB
#define przycisk1 7
#define klawiatura PINB // sprawdzam czy przycisk 1 ma wartośc 0 gdy jest wciśnięty
volatile uint8_t klawisz1=0; // nie optamilizuj zmiennej ; służy do liczenia wciśnięć


uint8_t seg7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

volatile uint8_t dane[] = {2, 0, 2, 5};

ISR(TIMER1_COMPA_vect)
{
    // Inkrementacja tablicy dane jako liczby
    for (int8_t i = 3; i >= 0; i--) {
        if (dane[i] < 9) {
            dane[i]++;
            break;
        } else {
            dane[i] = 0;
        }
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint8_t i = 0;
	cyfra |= (1<<i);
	if (i++==3) i=0;
	segmenty = seg7[dane[i]];
	cyfra &= ~(1<<i);
	// przyciski tak jest git
	if (!(klawiatura & (1<<przycisk1)))
	{
		switch(klawisz1)
		{
			case  0:
			klawisz1 = 1;
			break;
			
			case 1:
			klawisz1 = 2;
			break;
		}
	}
	else
	{
		switch(klawisz1)
		{
			case  3:
			klawisz1 = 4;
			break;
			
			case 4:
			klawisz1 = 0;
			break;
		}
	}
}

int main(void)
{    
	segmentyDDR = 0xff;
	segmenty = 0xff;
	cyfraDDR = 0x0f;
	cyfra |= (1<<przycisk1);//włączenie rezystora polaryzującego pullup
	TCCR1B = (1<<WGM12)|(1<<CS12); // tryb CTC i preskaler 256
	OCR1A = 62500;
	TIMSK = (1<<OCIE1A); // włączenie przerwania od porównania Timer1 część A
	TCCR0 = (1<<CS02);
	TIMSK |= (1<<TOIE0);// włączenie przerwania od przepełnienia Timer0
	
	sei(); // globalne włączenie przerwań
	
    while (1) 
    {
        if (klawisz1 == 2)
        {
			if (dane[0]++==9)
			{
				dane[0]=0;
			}
			klawisz1=3;
        }
    }
}

// prawie działa
/*
 * 17_03_2025.c
 *
 * Created: 17/03/2025 10:42:43
 * Author :
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #define F_CPU 16000000UL
 #define segmentyDDR DDRA
 #define segmenty PORTA
 #define cyfraDDR DDRB
 #define cyfra PORTB
 #define przycisk1 7
 #define klawiatura PINB // sprawdzam czy przycisk 1 ma wartośc 0 gdy jest wciśnięty
 volatile uint8_t klawisz1=0; // nie optamilizuj zmiennej ; służy do liczenia wciśnięć
 #define przycisk2 6
 volatile uint8_t klawisz2=0;
 
 
 uint8_t seg7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
 
 volatile uint8_t dane[] = {2, 0, 2, 5};
 
 ISR(TIMER1_COMPA_vect)
 {
	 // Inkrementacja tablicy dane jako liczby
	 for (int8_t i = 3; i >= 0; i--) {
		 if (dane[i] < 9) {
			 dane[i]++;
			 break;
		 } else {
			 dane[i] = 0;
		 }
	 }
 }
 
 ISR(TIMER0_OVF_vect)
 {
	 static uint8_t i = 0;
	 cyfra |= (1<<i);
	 if (i++==3) i=0;
	 segmenty = seg7[dane[i]];
	 cyfra &= ~(1<<i);
	 // przyciski tak jest git
	 if (!(klawiatura & (1<<przycisk1)))
	 {
		 switch(klawisz1)
		 {
			 case  0:
			 klawisz1 = 1;
			 break;
			 
			 case 1:
			 klawisz1 = 2;
			 break;
		 }
	 }
	 else
	 {
		 switch(klawisz1)
		 {
			 case  3:
			 klawisz1 = 4;
			 break;
			 
			 case 4:
			 klawisz1 = 0;
			 break;
		 }
	 }
	 
	 if (!(klawiatura & (1<<przycisk2)))
	 {
		 switch(klawisz2)
		 {
			 case  0:
			 klawisz2 = 1;
			 break;
			 
			 case 1:
			 klawisz2 = 2;
			 break;
		 }
	 }
	 else
	 {
		 switch(klawisz2)
		 {
			 case  3:
			 klawisz2 = 4;
			 break;
			 
			 case 4:
			 klawisz2 = 0;
			 break;
		 }
	 }
 }
 
 int main(void)
 {    
	 segmentyDDR = 0xff;
	 segmenty = 0xff;
	 cyfraDDR = 0x0f;
	 cyfra |= (1<<przycisk1);//włączenie rezystora polaryzującego pullup
	 cyfra |= (1<<przycisk2);
	 TCCR1B = (1<<WGM12)|(1<<CS12); // tryb CTC i preskaler 256
	 OCR1A = 62500;
	 TIMSK = (1<<OCIE1A); // włączenie przerwania od porównania Timer1 część A
	 TCCR0 = (1<<CS02);
	 TIMSK |= (1<<TOIE0);// włączenie przerwania od przepełnienia Timer0
	 
	 sei(); // globalne włączenie przerwań
	 
	 while (1) 
	 {
		 if (klawisz1 == 2)
		 {
			 if (dane[0]++==9)
			 {
				 dane[0]=0;
			 }
			 klawisz1=3;
		 }
		 
		 if (klawisz2 == 2)
		 {
			 if (dane[0]--==9)
			 {
				 dane[0]=0;
			 }
			 klawisz2=3;
		 }
	 }
 }
 
 