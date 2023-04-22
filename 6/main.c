#include <stm32l496xx.h>
#include <stm32l4xx.h>
#include <string.h>

void Clock_Config(void); // konfiguracja zegara TIM6
static void Delay(uint32_t miliseconds);
void LPUART_Config(void);
void LPUART_SendString(char* stringToSend);

int main(void)
{
	Clock_Config();
	LPUART_Config();

	while (1)
	{
		LPUART_SendString("SYSTEMY WBUDOWANE\r\n");
		Delay(1000);
	}
}

void LPUART_Config(void)
{
	RCC->AHB2ENR |= (1 << 2); //włączenie zegara GPIOC --251
	RCC->APB1ENR2 |= (1 << 0); // włączenie zegara dla LPUART --256

	GPIOC->MODER |= (1 << 3) | (1 << 1); //ustawienie funkcji alternatywnej
	GPIOC->MODER &= ~(1 << 2) & ~(1 << 0);

	GPIOC->AFR[0] = 0x00000088; // ustawienie funkcji alternatywnej AF8 dla PC0 i PC1 --110
	LPUART1->BRR = 17778; // ustawienie baud rate --1412
	LPUART1->CR1 |= (1 << 0); //uruchomienie LPUART
	LPUART1->CR1 |= (1 << 3); //uruchomenie transmitera
}

void LPUART_SendString(char* stringToSend)
{
	uint8_t *ptr = (uint8_t*)stringToSend;
    uint8_t size = strlen(stringToSend);
    int8_t counter = size;
    while (counter > 0u)
    {
  	  if((LPUART1->ISR >> 7) & 1)
  	  {
  		  LPUART1->TDR = *ptr;
		  ptr++;
		  counter--;
  	  }
    }
}

void Clock_Config(void)
{
	RCC->APB1ENR1 |= (1 << 4); //uruchomienie zegara TIM6 -  TIM6 timer clock enable --253

	TIM6->CR1 |= (1 << 0); //CEN - uruchomienie zegara / odliczanie // counter enable

	TIM6->PSC = 4u; // ustawienie prescaler'a na 1
	TIM6->ARR = 1000U; // wartość do której musi dojść licznik by wywołać przerwanie
}

static void Delay(uint32_t miliseconds)
{
	uint16_t howManyOverflowsOccur = 0; // zmienna odmierzający czas, a dokładniej ilość przepełnień/przerwań

	while (howManyOverflowsOccur < miliseconds)
	{
		if (TIM6->SR & (1 << 0)) // sprawdzenie flagi przerwania UIF --1178
		{
			TIM6->SR &= ~(1 << 0); // ustawienie flagi przerwania na 0
			howManyOverflowsOccur++; // inkrementacja zmiennej
		}
	}
}
