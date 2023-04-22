#include <stm32l496xx.h>
#include <stm32l4xx.h>

typedef volatile uint32_t REG_VOLATILE_U32; // odpowiednik __IO

//operacje przesunięcia w lewo
#define SHIFT0 (1 << 0)
#define SHIFT1 (1 << 1)
#define SHIFT2 (1 << 2)
#define SHIFT3 (1 << 3)
#define SHIFT4 (1 << 4)
#define SHIFT5 (1 << 5)
#define SHIFT6 (1 << 6)
#define SHIFT7 (1 << 7)
#define SHIFT8 (1 << 8)
#define SHIFT9 (1 << 9)
#define SHIFT10 (1 << 10)
#define SHIFT11 (1 << 11)
#define SHIFT12 (1 << 12)
#define SHIFT13 (1 << 13)
#define SHIFT14 (1 << 14)
#define SHIFT15 (1 << 15)
#define SHIFT16 (1 << 16)
#define SHIFT17 (1 << 17)
#define SHIFT18 (1 << 18)
#define SHIFT19 (1 << 19)
#define SHIFT20 (1 << 2O)
#define SHIFT21 (1 << 21)
#define SHIFT22 (1 << 22)
#define SHIFT23 (1 << 23)
#define SHIFT24 (1 << 24)
#define SHIFT25 (1 << 25)
#define SHIFT26 (1 << 26)
#define SHIFT27 (1 << 27)
#define SHIFT28 (1 << 28)
#define SHIFT29 (1 << 29)
#define SHIFT30 (1 << 30)
#define SHIFT31 (1 << 31)

typedef struct //GPIO
{
	REG_VOLATILE_U32 MODER;
	REG_VOLATILE_U32 OTYPER;
	REG_VOLATILE_U32 OSPEEDR;
	REG_VOLATILE_U32 PUPDR;
	REG_VOLATILE_U32 IDR;
	REG_VOLATILE_U32 ODR;
	REG_VOLATILE_U32 BSRR;
	REG_VOLATILE_U32 LCKR;
	REG_VOLATILE_U32 AFR[2];
	REG_VOLATILE_U32 BRR;
}GPIO_Struct;

//rzutowanie wskaźników
#define MYGPIOA ((GPIO_Struct *) 0x48000000)
#define MYGPIOB ((GPIO_Struct *) 0x48000400)
#define MYGPIOC ((GPIO_Struct *) 0x48000800)
#define MYGPIOD ((GPIO_Struct *) 0x48000C00)
#define MYGPIOE ((GPIO_Struct *) 0x48001000)
#define MYGPIOF ((GPIO_Struct *) 0x48001400)
#define MYGPIOG ((GPIO_Struct *) 0x48001800)
#define MYGPIOH ((GPIO_Struct *) 0x48001C00)
#define MYGPIOI ((GPIO_Struct *) 0x48002000)

typedef struct //sterowanie zasilaniem
{
  REG_VOLATILE_U32 CR1;
  REG_VOLATILE_U32 CR2;
  REG_VOLATILE_U32 CR3;
  REG_VOLATILE_U32 CR4;
  REG_VOLATILE_U32 SR1;
  REG_VOLATILE_U32 SR2;
  REG_VOLATILE_U32 SCR;
  uint32_t RESERVED;
  REG_VOLATILE_U32 PUCRA;
  REG_VOLATILE_U32 PDCRA;
  REG_VOLATILE_U32 PUCRB;
  REG_VOLATILE_U32 PDCRB;
  REG_VOLATILE_U32 PUCRC;
  REG_VOLATILE_U32 PDCRC;
  REG_VOLATILE_U32 PUCRD;
  REG_VOLATILE_U32 PDCRD;
  REG_VOLATILE_U32 PUCRE;
  REG_VOLATILE_U32 PDCRE;
  REG_VOLATILE_U32 PUCRF;
  REG_VOLATILE_U32 PDCRF;
  REG_VOLATILE_U32 PUCRG;
  REG_VOLATILE_U32 PDCRG;
  REG_VOLATILE_U32 PUCRH;
  REG_VOLATILE_U32 PDCRH;
  REG_VOLATILE_U32 PUCRI;
  REG_VOLATILE_U32 PDCRI;
} PWR_Struct;

//rzutowanie wskaźnika
#define MYPWR ((PWR_Struct *) 0x40007000)

typedef struct// struktura RCC - sterowanie urządzeniami peryferyjnymi, ustawianie zegarów i sygnał reset
{
  REG_VOLATILE_U32 CR;
  REG_VOLATILE_U32 ICSCR;
  REG_VOLATILE_U32 CFGR;
  REG_VOLATILE_U32 PLLCFGR;
  REG_VOLATILE_U32 PLLSAI1CFGR;
  REG_VOLATILE_U32 PLLSAI2CFGR;
  REG_VOLATILE_U32 CIER;
  REG_VOLATILE_U32 CIFR;
  REG_VOLATILE_U32 CICR;
  uint32_t      RESERVED0;
  REG_VOLATILE_U32 AHB1RSTR;
  REG_VOLATILE_U32 AHB2RSTR;
  REG_VOLATILE_U32 AHB3RSTR;
  uint32_t      RESERVED1;
  REG_VOLATILE_U32 APB1RSTR1;
  REG_VOLATILE_U32 APB1RSTR2;
  REG_VOLATILE_U32 APB2RSTR;
  uint32_t      RESERVED2;
  REG_VOLATILE_U32 AHB1ENR;
  REG_VOLATILE_U32 AHB2ENR;
  REG_VOLATILE_U32 AHB3ENR;
  uint32_t      RESERVED3;
  REG_VOLATILE_U32 APB1ENR1;
  REG_VOLATILE_U32 APB1ENR2;
  REG_VOLATILE_U32 APB2ENR;
  uint32_t      RESERVED4;
  REG_VOLATILE_U32 AHB1SMENR;
  REG_VOLATILE_U32 AHB2SMENR;
  REG_VOLATILE_U32 AHB3SMENR;
  uint32_t      RESERVED5;
  REG_VOLATILE_U32 APB1SMENR1;
  REG_VOLATILE_U32 APB1SMENR2;
  REG_VOLATILE_U32 APB2SMENR;
  uint32_t      RESERVED6;
  REG_VOLATILE_U32 CCIPR;
  uint32_t      RESERVED7;
  REG_VOLATILE_U32 BDCR;
  REG_VOLATILE_U32 CSR;
  REG_VOLATILE_U32 CRRCR;
  REG_VOLATILE_U32 CCIPR2;
} RCC_Struct;

//rzutowanie wskaźnika
#define MYRCC ((RCC_Struct *) 0x40021000)

typedef struct //basic timer --1180
{
	REG_VOLATILE_U32 CR1;
	REG_VOLATILE_U32 CR2;
	REG_VOLATILE_U32 RESERVED1;
	REG_VOLATILE_U32 DIER;
	REG_VOLATILE_U32 SR;
	REG_VOLATILE_U32 EGR;
	REG_VOLATILE_U32 RESERVED2[3];
	REG_VOLATILE_U32 CNT;
	REG_VOLATILE_U32 PSC;
	REG_VOLATILE_U32 ARR;
} TIM_Struct;

//rzutowanie wskaźnika - TIM6
#define MYTIM6 ((TIM_Struct *) 0x40001000) //rzutowanie wskaźnika

//wyłączanie segmentów i cyfr
#define OFFDISPLAY MYGPIOB->ODR &= ~(SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5) // wyłączenie grup cyfr
#define OFFSEGMENTS MYGPIOG->ODR &= ~(SHIFT0 | SHIFT1 | SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5 | SHIFT6) // wyłączenie segmentów

//włączanie poszczególnych cyfr
#define DISPLAY3 MYGPIOB->ODR |= (SHIFT2) // włączenie pierwszej od lewej cyfry
#define DISPLAY2 MYGPIOB->ODR |= (SHIFT3) // włącznie drugiej cyfry
#define DISPLAY1 MYGPIOB->ODR |= (SHIFT4) // włącznie trzeciej cyfry
#define DISPLAY0 MYGPIOB->ODR |= (SHIFT5) // włącznie czwartej cyfry (pierwsza z prawej)

//funkcje konfigurujące
void Power_Config(void); // konfiguracja zasilania
void Display_Config(void); // konfiguracja wyświetlacza
void LED_Config(void); // konfiguracja diod led
void Clock_Config(void); // konfiguracja zegara TIM6
void Off_LED(void); // wyłączenie diod led



//funkcje obsługujące działanie programu
static void PrintNumber(uint16_t number); // obsługa wyświetlania liczb
static void SetInDisplay(uint8_t number); // wyświetlenie liczby na ekranie
static void Delay(uint32_t miliseconds); // delay, oraz obsługa joystick'a
// flaga w funkcji PrintNumber i Delay służy do możliwości blokady weryfikacji wciśnięcia joystick'a
// number umożliwia wyświetlanie liczby w pętli do momentu puszczenia przycisku


int main(void)
{
	Power_Config();// ustawienie zasilania dla GPIOG
	Clock_Config();// ustawienie zegara TIM6
	Display_Config();//ustawienie wyświetlacza
	LED_Config();//ustawienie ledów
	Off_LED();//wyłączenie ledów


	//funkcje PrintNumber w pętli main posiadają flagę ustawioną na 1. Przekazywana jest ona następnie do funkcji Delay
	//1 - możliwość sprawdzenia czy przycisk jest wsiśnięty
	//0 - brak możliwości sprawdzenia
	while(1)
	{
		for(uint16_t counter = 0; counter <= 9999; counter++)
		{
			PrintNumber(counter);
		}
	}

}

void Power_Config(void)
{
	/*	 PWREN i VOS zrobione na podstawie HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1)
				 Configure the main internal regulator output voltage*/
	MYRCC->APB1ENR1 |= (SHIFT28); // ustawiamy Power interface clock
	MYPWR->CR1 |= (SHIFT9); // ustawiamy Voltage scaling range na Range 1
}

void Display_Config(void)
{
	//This bit is used to validate the VDDIO2 supply for electrical and logical isolation purpose.
	MYPWR->CR2 |= (SHIFT9); //VDDIO2 Independent I/Os supply valid (zasilanie dla protów I/O PG[15:2]) zdjęcie izolacji --155

	MYRCC->AHB2ENR |= (SHIFT1);// odpalenie zegara
	MYGPIOB->MODER |= (SHIFT4) | (SHIFT6) | (SHIFT8) | (SHIFT10);// ustawienie jako output
	MYGPIOB->MODER &= ~(SHIFT5) & ~(SHIFT7) & ~(SHIFT9) & ~(SHIFT11);

	MYRCC->AHB2ENR |= (SHIFT6);
	MYGPIOG->MODER |= (SHIFT0) | (SHIFT2) | (SHIFT4) | (SHIFT6) | (SHIFT8) | (SHIFT10) | (SHIFT12);
	MYGPIOG->MODER &= ~(SHIFT1) & ~(SHIFT3) & ~(SHIFT5) & ~(SHIFT7) & ~(SHIFT9) & ~(SHIFT11) & ~(SHIFT13);

	OFFSEGMENTS;// ustawienie segmentów na 0
	OFFSEGMENTS;// ustawienie "cyfr" na 0
}

void LED_Config(void)
{
	//PC6 PC7 PC8 PC9
	MYRCC->AHB2ENR |= (SHIFT2);

	MYGPIOC->MODER |= (SHIFT12) | (SHIFT14) | (SHIFT16) | (SHIFT18);
	MYGPIOC->MODER &= ~(SHIFT13) & ~(SHIFT15) & ~(SHIFT17) & ~(SHIFT19);

	//PE4 PE5 PE6
	MYRCC->AHB2ENR |= (SHIFT4);

	MYGPIOE->MODER |= (SHIFT8) | (SHIFT10) | (SHIFT12);
	MYGPIOE->MODER &= ~(SHIFT9) & ~(SHIFT11) & ~(SHIFT13);

	//PD3
	MYRCC->AHB2ENR |= (SHIFT3);

	MYGPIOD->MODER |= (SHIFT6);
	MYGPIOD->MODER &= ~(SHIFT7);
}

void Off_LED(void)
{
	//PC6 PC7 PC8 PC9
	MYGPIOC->ODR &= ~(SHIFT6) & ~(SHIFT7) & ~(SHIFT8) & ~(SHIFT9);

	//PE4 PE5 PE6
	MYGPIOE->ODR &= ~(SHIFT4) & ~(SHIFT5) & ~(SHIFT6);

	//PD3
	MYGPIOD->ODR &= ~(SHIFT3);
}

void Clock_Config(void)
{
	MYRCC->APB1ENR1 |= (SHIFT4); //uruchomienie zegara TIM6 -  TIM6 timer clock enable --253

	MYTIM6->CR1 |= (SHIFT0); //CEN - uruchomienie zegara / odliczanie // counter enable
	//The counter is clocked by the prescaler output CK_CNT, which is enabled only when the
	//counter enable bit (CEN) in the TIMx_CR1 register is set.

	//Frequency = ClockFreq / ((PSC + 1) * (ARR + 1)) wzór na

	MYTIM6->PSC = 4u; // ustawienie prescaler'a na 1
	MYTIM6->ARR = 1000U; // wartość do której musi dojść licznik by wywołać przerwanie

	//częstotliwość_przerwania = częstotliwość_zagar 1) * (1 +a/(ARR+1)(PSC+1)
	//częstotliwość_przerwania = 4 000 000 / (1999 + 1)
	//częstotliwość_przerwania = 1000Hz = 0.001s = 1ms
}


static void PrintNumber(uint16_t number)
{
	uint8_t first = 0, second = 0, third = 0, fourth;

	if(number >= 0 && number <= 9)
	{
		OFFDISPLAY;
		first = number;
		DISPLAY0;
		SetInDisplay(first);
		Delay(500);
	}
	else if(number >= 10 && number <= 99)
	{
		first = number/10;
		second = number%10;
		for(uint8_t i = 0; i < 50; i++)
		{
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(second);
			DISPLAY0;
			Delay(5);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(first);
			DISPLAY1;
			Delay(5);
		}
	}
	else if(number >= 100 && number <= 999)
	{
		first = number / 100;
		second = number % 100 / 10;
		third = number %100 %10;
		for(uint8_t i = 0; i < 33; i++)
		{
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(third);
			DISPLAY0;
			Delay(5);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(second);
			DISPLAY1;
			Delay(5);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(first);
			DISPLAY2;
			Delay(5);
		}
	} else if(number >= 1000 && number <=9999)
	{
		first = number/1000;
		second = number/100%10;
		third = number % 100 / 10;
		fourth = number %100 %10;
		for(uint8_t i = 0; i < 32; i++)
		{
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(fourth);
			DISPLAY0;
			Delay(5);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(third);
			DISPLAY1;
			Delay(5);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(second);
			DISPLAY2;
			Delay(5);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(first);
			DISPLAY3;
			Delay(5);
		}
	}
}

static void SetInDisplay(uint8_t number)
{
	OFFSEGMENTS;
	switch (number)
	{
		case 0:
			MYGPIOG->ODR |= SHIFT0 | SHIFT1 | SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5;
			break;
		case 1:
			MYGPIOG->ODR |= SHIFT1 | SHIFT2;
			break;
		case 2:
			MYGPIOG->ODR |= SHIFT0 | SHIFT1 | SHIFT3 | SHIFT4 | SHIFT6;
			break;
		case 3:
			MYGPIOG->ODR |= SHIFT0 | SHIFT1 | SHIFT2 | SHIFT3 | SHIFT6;
			break;
		case 4:
			MYGPIOG->ODR |= SHIFT1 | SHIFT2 | SHIFT5 | SHIFT6;
			break;
		case 5:
			MYGPIOG->ODR |= SHIFT0 | SHIFT2 | SHIFT3 | SHIFT5 | SHIFT6;
			break;
		case 6:
			MYGPIOG->ODR |= SHIFT0 | SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5 | SHIFT6;
			break;
		case 7:
			MYGPIOG->ODR |= SHIFT0 | SHIFT1 | SHIFT2;
			break;
		case 8:
			MYGPIOG->ODR |= SHIFT0 | SHIFT1 | SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5 | SHIFT6;
			break;
		case 9:
			MYGPIOG->ODR |= SHIFT0 | SHIFT1 | SHIFT2 | SHIFT3 | SHIFT5 | SHIFT6;
			break;
		default:
			break;
	}
}


//Pełny cykl zegara trwa 1ms - inkrementacja zmiennej następuje po nastąpieniu przerwania
static void Delay(uint32_t miliseconds)
{
	uint16_t howManyOverflowsOccur = 0; // zmienna odmierzający czas, a dokładniej ilość przepełnień/przerwań

	MYTIM6->CNT = 0u; // ustawienie licznika zegara na 0
	MYTIM6->SR &= ~(SHIFT0); // usunięcie flagi przerwania
	//przygotowanie do zagara do poprawnego odliczenia czasu
	while (howManyOverflowsOccur < miliseconds)
	{
		if (MYTIM6->SR & (1<<0)) // sprawdzenie flagi przerwania UIF --1178
		{
			MYTIM6->SR &= ~(SHIFT0); // ustawienie flagi przerwania na 0
			howManyOverflowsOccur++; // inkrementacja zmiennej
		}
	}
}








