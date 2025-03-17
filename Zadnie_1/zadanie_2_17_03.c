#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define segmentyDDR DDRA
#define segmenty PORTA
#include <avr/interrupt.h> // biblioteka przerwa�

uint8_t seg7[] = {0xC0, // 0
	0xF9, // 1
	0xA4, // 2
	0xB0, // 3
	0x99, // 4
	0x92, // 5
	0x82, // 6
	0xD8, // 7
	0x80, // 8
	0x90  // 9
};
// do zrobioenia

volatile int8_t licznik = 3;
volatile int8_t kierunek = 1; // 1 - ro�nie, -1 - maleje

ISR(TIMER1_COMPA_vect) {
	licznik += kierunek;
	
	if (licznik > 9) {
		licznik = 9;
		kierunek = -1;
		} else if (licznik < 0) {
		licznik = 0;
		kierunek = 1;
	}
	
	segmenty = seg7[licznik];
}


int main(void) {
	segmentyDDR = 0xff;
	segmenty = seg7[0];  // ustawienie pocz�tkowego wy�wietlenia na 0
	
	TCCR1B = (1 << WGM12) | (1 << CS12); // tryb CTC i prescaler 256
	OCR1A = 62500;
	TIMSK = (1 << OCIE1A); // w��czenie przerwania od por�wnania cz�ci A
	sei(); // globalne w��czenie przerwa�
	
	while (1) {
		// P�tla g��wna - dzia�anie w przerwaniach
	}
}

