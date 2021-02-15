
#include "main.h"
#include "stm32f4xx_hal.h"
#include "TA_STM32_Delay_Us.h"
#define FT_ORDER 661

int x[FT_ORDER];
float h[FT_ORDER] = {-4.5315e-05,-3.7263e-05,-2.8583e-05,-1.9394e-05,-9.8218e-06,-1.5448e-19,9.9337e-06,1.9838e-05,2.957e-05,3.8987e-05,4.7948e-05,5.6314e-05,6.3954e-05,7.0743e-05,7.6562e-05,8.1308e-05,8.4886e-05,8.7217e-05,8.8235e-05,8.7893e-05,8.6162e-05,8.303e-05,7.8506e-05,7.2619e-05,6.5419e-05,5.6976e-05,4.7382e-05,3.6748e-05,2.5205e-05,1.29e-05,-1.5365e-19,-1.3315e-05,-2.6853e-05,-4.0408e-05,-5.377e-05,-6.6722e-05,-7.9046e-05,-9.0523e-05,-0.00010094,-0.0001101,-0.0001178,-0.00012387,-0.00012815,-0.0001305,-0.00013082,-0.00012901,-0.00012504,-0.00011887,-0.00011052,-0.00010005,-8.7544e-05,-7.3121e-05,-5.6944e-05,-3.9207e-05,-2.0139e-05,8.025e-19,2.0923e-05,4.2319e-05,6.3854e-05,8.518e-05,0.00010594,0.00012577,0.0001443,0.00016119,0.00017608,0.00018865,0.00019861,0.00020569,0.00020965,0.00021032,0.00020755,0.00020124,0.00019139,0.00017799,0.00016115,0.000141,0.00011776,9.169e-05,6.3112e-05,3.2406e-05,-3.226e-19,-3.3634e-05,-6.7985e-05,-0.00010251,-0.00013664,-0.00016981,-0.00020141,-0.00023088,-0.00025763,-0.00028114,-0.00030089,-0.00031642,-0.00032731,-0.00033321,-0.00033385,-0.00032902,-0.00031862,-0.0003026,-0.00028104,-0.00025409,-0.00022201,-0.00018515,-0.00014395,-9.894e-05,-5.0727e-05,4.538e-19,5.2491e-05,0.00010594,0.0001595,0.00021228,0.00026339,0.00031193,0.00035702,0.00039778,0.0004334,0.00046312,0.00048626,0.00050221,0.00051048,0.00051067,0.00050251,0.00048587,0.00046074,0.00042725,0.0003857,0.0003365,0.00028021,0.00021753,0.00014929,7.6427e-05,-6.0685e-19,-7.8853e-05,-0.00015891,-0.00023891,-0.00031751,-0.00039341,-0.00046525,-0.00053175,-0.00059164,-0.00064374,-0.00068696,-0.00072031,-0.00074296,-0.00075419,-0.00075349,-0.0007405,-0.00071507,-0.00067723,-0.00062723,-0.00056553,-0.00049279,-0.00040986,-0.00031781,-0.00021785,-0.0001114,7.7311e-19,0.00011468,0.00023086,0.00034669,0.00046028,0.00056969,0.00067304,0.00076845,0.00085415,0.00092846,0.00098984,0.0010369,0.0010685,0.0010837,0.0010817,0.0010621,0.0010248,0.00096974,0.00089742,0.0008085,0.00070395,0.00058505,0.00045331,0.00031051,0.00015867,-9.4321e-19,-0.00016312,-0.00032817,-0.00049252,-0.00065348,-0.00080836,-0.00095446,-0.0010892,-0.00121,-0.0013146,-0.0014009,-0.0014668,-0.0015109,-0.0015317,-0.0015283,-0.0015001,-0.0014469,-0.0013687,-0.0012663,-0.0011405,-0.00099279,-0.00082491,-0.00063903,-0.00043766,-0.00022361,1.1076e-18,0.00022983,0.00046235,0.00069386,0.00092062,0.0011388,0.0013447,0.0015346,0.0017051,0.0018527,0.0019746,0.0020679,0.0021305,0.0021604,0.0021563,0.0021171,0.0020427,0.0019331,0.0017892,0.0016122,0.0014041,0.0011673,0.00090475,0.00062001,0.00031699,-1.2569e-18,-0.00032626,-0.00065684,-0.00098654,-0.0013101,-0.001622,-0.0019171,-0.00219,-0.0024357,-0.0026495,-0.002827,-0.0029642,-0.0030577,-0.0031047,-0.0031029,-0.003051,-0.002948,-0.0027942,-0.0025902,-0.0023379,-0.0020396,-0.0016987,-0.0013191,-0.00090575,-0.00046401,1.3828e-18,0.00047964,0.0009678,0.001457,0.0019396,0.0024075,0.002853,0.0032681,0.0036451,0.0039768,0.0042562,0.004477,0.0046334,0.0047207,0.0047348,0.0046727,0.0045324,0.004313,0.0040148,0.0036393,0.0031892,0.0026684,0.0020822,0.0014369,0.00073998,-1.4782e-18,-0.00077345,-0.0015699,-0.002378,-0.003186,-0.0039812,-0.0047509,-0.0054819,-0.0061611,-0.0067754,-0.0073121,-0.0077587,-0.0081036,-0.0083358,-0.0084451,-0.0084228,-0.008261,-0.0079534,-0.0074951,-0.0068828,-0.0061147,-0.0051909,-0.0041131,-0.0028849,-0.0015115,1.5376e-18,0.0016409,0.0034008,0.0052678,0.0072286,0.0092685,0.011372,0.013521,0.0157,0.017888,0.020069,0.022222,0.024328,0.02637,0.028327,0.030182,0.031918,0.033519,0.034969,0.036255,0.037365,0.038288,0.039016,0.03954,0.039857,0.039963,0.039857,0.03954,0.039016,0.038288,0.037365,0.036255,0.034969,0.033519,0.031918,0.030182,0.028327,0.02637,0.024328,0.022222,0.020069,0.017888,0.0157,0.013521,0.011372,0.0092685,0.0072286,0.0052678,0.0034008,0.0016409,1.5376e-18,-0.0015115,-0.0028849,-0.0041131,-0.0051909,-0.0061147,-0.0068828,-0.0074951,-0.0079534,-0.008261,-0.0084228,-0.0084451,-0.0083358,-0.0081036,-0.0077587,-0.0073121,-0.0067754,-0.0061611,-0.0054819,-0.0047509,-0.0039812,-0.003186,-0.002378,-0.0015699,-0.00077345,-1.4782e-18,0.00073998,0.0014369,0.0020822,0.0026684,0.0031892,0.0036393,0.0040148,0.004313,0.0045324,0.0046727,0.0047348,0.0047207,0.0046334,0.004477,0.0042562,0.0039768,0.0036451,0.0032681,0.002853,0.0024075,0.0019396,0.001457,0.0009678,0.00047964,1.3828e-18,-0.00046401,-0.00090575,-0.0013191,-0.0016987,-0.0020396,-0.0023379,-0.0025902,-0.0027942,-0.002948,-0.003051,-0.0031029,-0.0031047,-0.0030577,-0.0029642,-0.002827,-0.0026495,-0.0024357,-0.00219,-0.0019171,-0.001622,-0.0013101,-0.00098654,-0.00065684,-0.00032626,-1.2569e-18,0.00031699,0.00062001,0.00090475,0.0011673,0.0014041,0.0016122,0.0017892,0.0019331,0.0020427,0.0021171,0.0021563,0.0021604,0.0021305,0.0020679,0.0019746,0.0018527,0.0017051,0.0015346,0.0013447,0.0011388,0.00092062,0.00069386,0.00046235,0.00022983,1.1076e-18,-0.00022361,-0.00043766,-0.00063903,-0.00082491,-0.00099279,-0.0011405,-0.0012663,-0.0013687,-0.0014469,-0.0015001,-0.0015283,-0.0015317,-0.0015109,-0.0014668,-0.0014009,-0.0013146,-0.00121,-0.0010892,-0.00095446,-0.00080836,-0.00065348,-0.00049252,-0.00032817,-0.00016312,-9.4321e-19,0.00015867,0.00031051,0.00045331,0.00058505,0.00070395,0.0008085,0.00089742,0.00096974,0.0010248,0.0010621,0.0010817,0.0010837,0.0010685,0.0010369,0.00098984,0.00092846,0.00085415,0.00076845,0.00067304,0.00056969,0.00046028,0.00034669,0.00023086,0.00011468,7.7311e-19,-0.0001114,-0.00021785,-0.00031781,-0.00040986,-0.00049279,-0.00056553,-0.00062723,-0.00067723,-0.00071507,-0.0007405,-0.00075349,-0.00075419,-0.00074296,-0.00072031,-0.00068696,-0.00064374,-0.00059164,-0.00053175,-0.00046525,-0.00039341,-0.00031751,-0.00023891,-0.00015891,-7.8853e-05,-6.0685e-19,7.6427e-05,0.00014929,0.00021753,0.00028021,0.0003365,0.0003857,0.00042725,0.00046074,0.00048587,0.00050251,0.00051067,0.00051048,0.00050221,0.00048626,0.00046312,0.0004334,0.00039778,0.00035702,0.00031193,0.00026339,0.00021228,0.0001595,0.00010594,5.2491e-05,4.538e-19,-5.0727e-05,-9.894e-05,-0.00014395,-0.00018515,-0.00022201,-0.00025409,-0.00028104,-0.0003026,-0.00031862,-0.00032902,-0.00033385,-0.00033321,-0.00032731,-0.00031642,-0.00030089,-0.00028114,-0.00025763,-0.00023088,-0.00020141,-0.00016981,-0.00013664,-0.00010251,-6.7985e-05,-3.3634e-05,-3.226e-19,3.2406e-05,6.3112e-05,9.169e-05,0.00011776,0.000141,0.00016115,0.00017799,0.00019139,0.00020124,0.00020755,0.00021032,0.00020965,0.00020569,0.00019861,0.00018865,0.00017608,0.00016119,0.0001443,0.00012577,0.00010594,8.518e-05,6.3854e-05,4.2319e-05,2.0923e-05,8.025e-19,-2.0139e-05,-3.9207e-05,-5.6944e-05,-7.3121e-05,-8.7544e-05,-0.00010005,-0.00011052,-0.00011887,-0.00012504,-0.00012901,-0.00013082,-0.0001305,-0.00012815,-0.00012387,-0.0001178,-0.0001101,-0.00010094,-9.0523e-05,-7.9046e-05,-6.6722e-05,-5.377e-05,-4.0408e-05,-2.6853e-05,-1.3315e-05,-1.5365e-19,1.29e-05,2.5205e-05,3.6748e-05,4.7382e-05,5.6976e-05,6.5419e-05,7.2619e-05,7.8506e-05,8.303e-05,8.6162e-05,8.7893e-05,8.8235e-05,8.7217e-05,8.4886e-05,8.1308e-05,7.6562e-05,7.0743e-05,6.3954e-05,5.6314e-05,4.7948e-05,3.8987e-05,2.957e-05,1.9838e-05,9.9337e-06,-1.5448e-19,-9.8218e-06,-1.9394e-05,-2.8583e-05,-3.7263e-05,-4.5315e-05};

ADC_HandleTypeDef hadc1;

DAC_HandleTypeDef hdac;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DAC_Init(void);
static void MX_ADC1_Init(void);

int adc_value = 0;
int main(void)
{
	Delay_Us_Init();
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DAC_Init();
  MX_ADC1_Init();
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	
	
  while (1)
  {
		float y = 0;
		for(uint16_t i = 0; i < FT_ORDER; i++)
		{
			y = y + x[i] * h[FT_ORDER - i - 1];
		}
		
		for(uint16_t i = 0; i < FT_ORDER-1; i++)
		{
			x[i] = x[i+1];
		}
		
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 1000);
		adc_value = HAL_ADC_GetValue(&hadc1);
		x[660] = adc_value;
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (int)y);
		delay_us(250); 
  }

}



void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* DAC init function */
static void MX_DAC_Init(void)
{

  DAC_ChannelConfTypeDef sConfig;

    /**DAC Initialization 
    */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**DAC channel OUT1 config 
    */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
