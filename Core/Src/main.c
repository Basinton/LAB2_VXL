/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int counter) {
	//led display number 0 by enable 6 ports as follow (reset state)
	if (counter == 0) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	}
	//led display number 1 by enable 2 ports as follow (reset state)
	if (counter == 1) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	}
	//led display number 2 by enable 5 ports as follow (reset state)
	if (counter == 2) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
	//led display number 3 by enable 5 ports as follow (reset state)
	if (counter == 3) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
	//led display number 4 by enable 4 ports as follow (reset state)
	if (counter == 4) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
	//led display number 5 by enable 5 ports as follow (reset state)
	if (counter == 5) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
	//led display number 6 by enable 6 ports as follow (reset state)
	if (counter == 6) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
	//led display number 7 by enable 3 ports as follow (reset state)
	if (counter == 7) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	}
	//led display number 8 by enable 7 ports as follow (reset state)
	if (counter == 8) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
	//led display number 9 by enable 6 ports as follow (reset state)
	if (counter == 9) {
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	}
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_TIM2_Init();
	/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim2);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */

	while (1) {

	}
	/* USER CODE END WHILE */

	/* USER CODE BEGIN 3 */
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void) {

	/* USER CODE BEGIN TIM2_Init 0 */

	/* USER CODE END TIM2_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM2_Init 1 */

	/* USER CODE END TIM2_Init 1 */
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 7999;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 9;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM2_Init 2 */

	/* USER CODE END TIM2_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, LED_Pin | EN_0_Pin | EN_1_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB,
			SEG_A_Pin | SEG_B_Pin | SEG_C_Pin | SEG_D_Pin | SEG_E_Pin
					| SEG_F_Pin | SEG_G_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : LED_Pin EN_0_Pin EN_1_Pin */
	GPIO_InitStruct.Pin = LED_Pin | EN_0_Pin | EN_1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin SEG_D_Pin
	 SEG_E_Pin SEG_F_Pin SEG_G_Pin */
	GPIO_InitStruct.Pin = SEG_A_Pin | SEG_B_Pin | SEG_C_Pin | SEG_D_Pin
			| SEG_E_Pin | SEG_F_Pin | SEG_G_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//Init values
//cycle = 10ms
int counter = 50;
int status = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	//after 50 cycles, time is 0.5s
	if (counter <= 0) {
		counter = 50;
		switch (status) {
		//first 7seg led call
		case 0:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, RESET);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, SET);
			display7SEG(1);
			status = 1;
			break;
		//second 7seg led call
		case 1:
			HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, SET);
			HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, RESET);
			display7SEG(2);
			status = 0;
			break;
		default:
			break;
		}
	}
	counter--;
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
