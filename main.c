//CKSEL = "1010".

#include <avr/io.h>

#define DLIT_PACHKI 2000 //2000 мкс длительность пачки
#define MIN_DLIT_PAUSE 8000 //8000 мкс минимальная пауза
#define DLIT_IMPULSE 50 //100 мкс период, 50 мкс импульс

int main(void)
{
	//Инициализация
	int z = 0;
	
	//Запрещаем прерывания
	SREG = 0;
	
	//АЦП
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADSC); //ацп разрешен, прескейлер 128
	ADCSRB = 0; 
	ADMUX = (1 << ADLAR) | (1 << MUX0); // adch 8 bit, ИОН - напряжение питания, используем PB2
	ADCH = 0;
	
	//Таймер счетчик 0
	TCCR0A = 0;
	TCCR0B = (1 << CS00); //без прескейлера
	TIMSK = 0;
	
	//Порты ввода-вывода
	DDRB = (1 << PORTB0); //с PB0 будет генерироваться пачка импульсов
	PORTB = (1 << PORTB0);
	
    while (1) 
    {
		//Основной цикл
		ADCSRA |= (1 << ADSC); //старт АЦ преобразования
		
		//генерирование пачки
		for(z = 0; z <= DLIT_PACHKI; z = z + 2 * DLIT_IMPULSE)
		{
			TCNT0 = 0; //обнуляем таймер счетчик
			while (TCNT0 <= DLIT_IMPULSE)
			{
				PORTB |= (1 << PORTB0);
			}
			while (TCNT0 <= 2*DLIT_IMPULSE)
			{
				PORTB &= ~(1 << PORTB0);
			}
		}
		//минимальная пауза между пачками
		TCNT0 = 0; //обнуляем таймер счетчик
		for (z = 0; z <= 10; z++)
		{
			while (TCNT0 <= 200)
			{
				PORTB &= ~(1 << PORTB0);
			}
			TCNT0 = 0;
		}
		//увеличение паузы по числу с ацп до 96 000 мкс
		// 96 000/256 = 375
		for(z = 0; z <= ADCH; z++)
		{
			while (TCNT0 <= 200)
			{
				PORTB &= ~(1 << PORTB0);
			}
			TCNT0 = 0;
			while (TCNT0 <= 175)
			{
				PORTB &= ~(1 << PORTB0);
			}
			TCNT0 = 0;
		}
    }
}
