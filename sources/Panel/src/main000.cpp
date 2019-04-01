#include "stm32f4xx_hal.h"
#include "Hardware/HAL.h"
#include "Keyboard/Keyboard.h"
#include "Display/Draw/Draw.h"
#include "Display/Set/DisplaySet.h"

//LTDC_HandleTypeDef hltdc;

//uint32_t ColorTable[4] = {0x00FFFFFF, 0xFF0000, 0x00FF00, 0x0000FF};
//uint8_t RGB565_240x320[240][320]={0x00000000};


static void MX_GPIO_Init(void);
//static void MX_LTDC_Init(void);
//void DrawRectangle(int, int, int, int, int);
//void Clear(void);
 
int main(void)
{
    HAL::Init();
	Keyboard::Init();
    MX_GPIO_Init();
    //MX_LTDC_Init();
	
    //HAL_LTDC_EnableCLUT(&hltdc, 0);
	
    //HAL_LTDC_ConfigCLUT(&hltdc, ColorTable, 4, 0);
    Draw::Rectangle(1, 2, 4, 5, 1);
    //HAL_LTDC_SetAddress(&hltdc,(uint32_t)&RGB565_240x320, 0);
    uint8_t x = 0;
    uint8_t y = 0;
	
    while (1)
    {
		Keyboard::Update();
		/*
		DrawRectangle(0, 0, 100, 100, 0);
			HAL_Delay(100);
		DrawRectangle(0, 0, 100, 100, 1);
			HAL_Delay(100);
		DrawRectangle(0, 0, 100, 100, 2);
			HAL_Delay(100);
		DrawRectangle(0, 0, 100, 100, 3);
			HAL_Delay(100);*/
    }
}
/*
static void MX_LTDC_Init(void)
{

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AH;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IIPC;
  hltdc.Init.HorizontalSync = 0;
  hltdc.Init.VerticalSync = 0;
  hltdc.Init.AccumulatedHBP = 70;
  hltdc.Init.AccumulatedVBP = 13;
  hltdc.Init.AccumulatedActiveW = 390;
  hltdc.Init.AccumulatedActiveH = 253;
  hltdc.Init.TotalWidth = 408;
  hltdc.Init.TotalHeigh = 263;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 320;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 240;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_L8;
  pLayerCfg.Alpha = 0xFF;
  pLayerCfg.Alpha0 = 0xFF;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = (uint32_t)&(RGB565_240x320[0][0]);
  pLayerCfg.ImageWidth = 320;
  pLayerCfg.ImageHeight = 240;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }

}

static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct = {0};
//--------------------------------------------
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

  
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
*/
//------------------------------------------------------------------------------------------------
/*
void DrawRectangle(int x, int y, int height, int width, int color)
{
	for (int i = x; i < x + width ; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			RGB565_240x320[j][i] = color;
		}
	}
}


void Clear()
{
	uint32_t h = 240;
	uint32_t w = 320;
	for (int y = 0; y < w ; y++)
	{
		for (int x = 0; x < h; x++)
		{
			RGB565_240x320[x][y] = 0;
		}
	}
} 
*/