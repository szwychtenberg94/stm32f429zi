/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
//#include "stm32f429i_discovery.h"
			

int main(void)
{
	 //SystemCoreClock = 8000000; // taktowanie 8Mhz
	 SystemCoreClockUpdate();
	 HAL_Init();

	 __HAL_RCC_GPIOG_CLK_ENABLE(); //port z ledami PG13 i PG14
	 __HAL_RCC_GPIOA_CLK_ENABLE();//port z przyciskiem

	 GPIO_InitTypeDef gpio; // obiekt gpio b�d�cy konfiguracj� port�w GPIO
	 gpio.Pin = GPIO_PIN_13 | GPIO_PIN_14; // konfigurujemy pin 13 i pin 14
	 gpio.Mode = GPIO_MODE_OUTPUT_PP; // jako wyj�cie
	 gpio.Pull = GPIO_PULLDOWN; // rezystor �ci�gaj�cy do masy
	 gpio.Speed = GPIO_SPEED_FREQ_MEDIUM; // wystarcz� �rednie cz�stotliwo�ci prze��czania
	 HAL_GPIO_Init(GPIOG, &gpio); // inicjalizacja modu�u GPIOA

	 gpio.Pin = GPIO_PIN_0; // konfigurujemy pin 0
	 gpio.Mode = GPIO_MODE_INPUT; // jako wyj�cie
	 gpio.Pull = GPIO_NOPULL; //
	 HAL_GPIO_Init(GPIOA, &gpio); // inicjalizacja modu�u GPIOA

HAL_Delay(500);


	while(1){
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==GPIO_PIN_SET){
		 HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET); // zapalenie diody
		 HAL_Delay(200);
	}
		 else{
		 HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET); // zgaszenie diody
		 }
//		 HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
//		  HAL_Delay(3000);
	 	 //}
	}
}
