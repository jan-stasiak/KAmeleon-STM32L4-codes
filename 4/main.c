#include <stm32l496xx.h>
#include <stm32l4xx.h>

typedef volatile uint32_t Reg_V_u32; // odpowiednik __IO


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



typedef struct //struktura GPIO
{
	Reg_V_u32 MODER;
	Reg_V_u32 OTYPER;
	Reg_V_u32 OSPEEDR;
	Reg_V_u32 PUPDR;
	Reg_V_u32 IDR;
	Reg_V_u32 ODR;
	Reg_V_u32 BSRR;
	Reg_V_u32 LCKR;
	Reg_V_u32 AFR[2];
	Reg_V_u32 BRR;
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

typedef struct //power controler? The PWR peripheral is used to control the device power supply configuration.
{
  Reg_V_u32 CR1;
  Reg_V_u32 CR2;
  Reg_V_u32 CR3;
  Reg_V_u32 CR4;
  Reg_V_u32 SR1;
  Reg_V_u32 SR2;
  Reg_V_u32 SCR;
  uint32_t RESERVED;
  Reg_V_u32 PUCRA;
  Reg_V_u32 PDCRA;
  Reg_V_u32 PUCRB;
  Reg_V_u32 PDCRB;
  Reg_V_u32 PUCRC;
  Reg_V_u32 PDCRC;
  Reg_V_u32 PUCRD;
  Reg_V_u32 PDCRD;
  Reg_V_u32 PUCRE;
  Reg_V_u32 PDCRE;
  Reg_V_u32 PUCRF;
  Reg_V_u32 PDCRF;
  Reg_V_u32 PUCRG;
  Reg_V_u32 PDCRG;
  Reg_V_u32 PUCRH;
  Reg_V_u32 PDCRH;
  Reg_V_u32 PUCRI;
  Reg_V_u32 PDCRI;
} PWR_Struct;

#define MYPWR ((PWR_Struct *) 0x40007000)

typedef struct// struktura RCC - sterowanie urządzeniami peryferyjnymi, ustawianie zegarów i sygnał reset
{
  Reg_V_u32 CR;
  Reg_V_u32 ICSCR;
  Reg_V_u32 CFGR;
  Reg_V_u32 PLLCFGR;
  Reg_V_u32 PLLSAI1CFGR;
  Reg_V_u32 PLLSAI2CFGR;
  Reg_V_u32 CIER;
  Reg_V_u32 CIFR;
  Reg_V_u32 CICR;
  uint32_t      RESERVED0;
  Reg_V_u32 AHB1RSTR;
  Reg_V_u32 AHB2RSTR;
  Reg_V_u32 AHB3RSTR;
  uint32_t      RESERVED1;
  Reg_V_u32 APB1RSTR1;
  Reg_V_u32 APB1RSTR2;
  Reg_V_u32 APB2RSTR;
  uint32_t      RESERVED2;
  Reg_V_u32 AHB1ENR;
  Reg_V_u32 AHB2ENR;
  Reg_V_u32 AHB3ENR;
  uint32_t      RESERVED3;
  Reg_V_u32 APB1ENR1;
  Reg_V_u32 APB1ENR2;
  Reg_V_u32 APB2ENR;
  uint32_t      RESERVED4;
  Reg_V_u32 AHB1SMENR;
  Reg_V_u32 AHB2SMENR;
  Reg_V_u32 AHB3SMENR;
  uint32_t      RESERVED5;
  Reg_V_u32 APB1SMENR1;
  Reg_V_u32 APB1SMENR2;
  Reg_V_u32 APB2SMENR;
  uint32_t      RESERVED6;
  Reg_V_u32 CCIPR;
  uint32_t      RESERVED7;
  Reg_V_u32 BDCR;
  Reg_V_u32 CSR;
  Reg_V_u32 CRRCR;
  Reg_V_u32 CCIPR2;
} RCC_Struct;


#define MYRCC ((RCC_Struct *) 0x40021000)

#define MILISEC 2000

#define OFFDISPLAY MYGPIOB->ODR &= ~(SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5) // wyłączenie grup cyfr
#define OFFSEGMENTS MYGPIOG->ODR &= ~(SHIFT0 | SHIFT1 | SHIFT2 | SHIFT3 | SHIFT4 | SHIFT5 | SHIFT6) // wyłączenie segmentów

#define DISPLAY3 MYGPIOB->ODR |= (SHIFT2) // włączenie pierwszej od lewej cyfry
#define DISPLAY2 MYGPIOB->ODR |= (SHIFT3)	// włącznie drugiej cyfry
#define DISPLAY1 MYGPIOB->ODR |= (SHIFT4) // włącznie trzeciej cyfry
#define DISPLAY0 MYGPIOB->ODR |= (SHIFT5) // włącznie czwartej cyfry (pierwsza z prawej)


void Power_Config(void);
void Set_Display(void);
void Set_LED(void);
void Off_LED(void);
static void PrintNumber(uint16_t number, uint8_t div, uint8_t mul);
static void SetInDisplay(uint8_t number);
static void Delay(uint16_t time);


int main(void)
{
	Power_Config();// ustawienie zasilania dla GPIOG
	Set_Display();//ustawienie wyświetlacza
	Set_LED();//ustawienie ledów
	Off_LED();//wyłączenie ledów

	uint16_t counter = 0;

	while(1)
	{
		for(counter = 0; counter <= 9999; counter++)
		{
			PrintNumber(counter, 6, 1);
		}
	}
}

void Power_Config(void)
{
	/*	 PWREN i VOS zrobione na podstawie HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1)
				 Configure the main internal regulator output voltage*/
	MYRCC->APB1ENR1 |= RCC_APB1ENR1_PWREN; // ustawiamy Power interface clock
	MYPWR->CR1 |= PWR_CR1_VOS_0; // ustawiamy Voltage scaling range na Range 1
}

void Set_Display(void)
{
	//This bit is used to validate the VDDIO2 supply for electrical and logical isolation purpose.
	MYPWR->CR2 |= PWR_CR2_IOSV; //VDDIO2 Independent I/Os supply valid (zasilanie dla protów I/O PG[15:2]) zdjęcie izolacji

	MYRCC->AHB2ENR |= (SHIFT1);// odpalenie zegara
	MYGPIOB->MODER |= (SHIFT4) | (SHIFT6) | (SHIFT8) | (SHIFT10);// ustawienie jako output
	MYGPIOB->MODER &= ~(SHIFT5) & ~(SHIFT7) & ~(SHIFT9) & ~(SHIFT11);

	MYRCC->AHB2ENR |= (SHIFT6);
	MYGPIOG->MODER |= (SHIFT0) | (SHIFT2) | (SHIFT4) | (SHIFT6) | (SHIFT8) | (SHIFT10) | (SHIFT12);
	MYGPIOG->MODER &= ~(SHIFT1) & ~(SHIFT3) & ~(SHIFT5) & ~(SHIFT7) & ~(SHIFT9) & ~(SHIFT11) & ~(SHIFT13);

	OFFSEGMENTS;// ustawienie segmentów na 0
	OFFSEGMENTS;// ustawienie "cyfr" na 0
}

void Set_LED(void)
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


static void PrintNumber(uint16_t number, uint8_t div, uint8_t mul)
{
	uint8_t first = 0, second = 0, third = 0, fourth;
	if(number >= 0 && number <= 9)
	{
		OFFDISPLAY;
		first = number;
		DISPLAY0;
		SetInDisplay(first);
		Delay((300/div)*mul);
	}
	else if(number >= 10 && number <= 99)
	{
		first = number/10;
		second = number%10;
		for(uint8_t i = 0; i < (75/div)*mul; i++)
		{
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(second);
			DISPLAY0;
			Delay(2);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(first);
			DISPLAY1;
			Delay(2);
		}
	}
	else if(number >= 100 && number <= 999)
	{
		first = number / 100;
		second = number % 100 / 10;
		third = number %100 %10;
		for(uint8_t i = 0; i < (100/div)*mul; i++)
				{
					OFFDISPLAY;
					OFFSEGMENTS;
					SetInDisplay(third);
					DISPLAY0;
					Delay(1);
					OFFDISPLAY;
					OFFSEGMENTS;
					SetInDisplay(second);
					DISPLAY1;
					Delay(1);
					OFFDISPLAY;
					OFFSEGMENTS;
					SetInDisplay(first);
					DISPLAY2;
					Delay(1);
				}
	} else if(number >= 1000 && number <=9999)
	{
		first = number/1000;
		second = number/100%10;
		third = number % 100 / 10;
		fourth = number %100 %10;
		for(uint8_t i = 0; i < (100/div)*mul; i++)
		{
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(fourth);
			DISPLAY0;
			Delay(1);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(third);
			DISPLAY1;
			Delay(1);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(second);
			DISPLAY2;
			Delay(1);
			OFFDISPLAY;
			OFFSEGMENTS;
			SetInDisplay(first);
			DISPLAY3;
			Delay(1);
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

static void Delay(uint16_t time)
{
	for(uint16_t i = 0; i < time; i++)
	{
		for(uint32_t j = 0; j < MILISEC; j++);
	}
}
