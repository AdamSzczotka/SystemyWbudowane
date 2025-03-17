#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define segmentyDDR DDRA
#define segmenty PORTA

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

int main(void){
	segmentyDDR=0xff;
	segmenty = 0xD8;
	while (1) {
		for (uint8_t i = 0; i < 10; i++) {
			segmenty = seg7[i];
			_delay_ms(1000);
		}
	}
}