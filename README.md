# TFT Display (ST7735R) STM32F0XX Library

This library was created for STM32F0xx series but it can be modified for the other STM32 series.

The data sheet for TFT Display can be found [here](https://cdn-shop.adafruit.com/datasheets/JD-T1800.pdf) and the datasheet for the display driver chip can be found [here](https://cdn-shop.adafruit.com/datasheets/ST7735R_V0.2.pdf).

The TFT Display was controlled by STM32F030K6Tx using SPI communication protocol.


## Getting Started

These instructions will get you started.

### Setup

```c
#include "TFT_DISPLAY.h"

int main(void){
  ST7735_Init();
  ST7735_FillScreen(ST7735_BLACK);
}
```

Following code segment shows that how SPI is configurated using STM32CubeMX software. Clock signal is 8Mhz. TFT LCD is using 4.0 MBits/s.
```C
/* USER CODE BEGIN SPI1_Init 0 */

/* USER CODE END SPI1_Init 0 */

/* USER CODE BEGIN SPI1_Init 1 */

/* USER CODE END SPI1_Init 1 */
/* SPI1 parameter configuration*/
hspi1.Instance = SPI1;
hspi1.Init.Mode = SPI_MODE_MASTER;
hspi1.Init.Direction = SPI_DIRECTION_2LINES;
hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
hspi1.Init.NSS = SPI_NSS_SOFT;
hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
hspi1.Init.CRCPolynomial = 7;
hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
if (HAL_SPI_Init(&hspi1) != HAL_OK)
{
  Error_Handler();
}
/* USER CODE BEGIN SPI1_Init 2 */

/* USER CODE END SPI1_Init 2 */
```
### Prerequisites

Include HAL library for the STM32

```c
#include "stm32f0xx_hal.h"
```

Include `Disp_HAL_SPI_TX.h` library for SPI Transmit instead of HAL SPI Transmit function. Other functions can stay the same.
This library is just for SPI Transmit.
```c
#include "Disp_HAL_SPI_TX.h"
```

Include the M90E32AS Library

```c
#include "TFT_DISPLAY.h"
```

## Running

TFT Display works as a slave device where STM32 works as a master device. Communication between the slave and master are established using SPI in MODE 3 - CPOL = HIGH (1) / CPHA - 2 EDGE (1).

* [Keil MDK](http://www.keil.com/#:~:text=Keil%20MDK%20is%20the%20complete,easy%20to%20learn%20and%20use.) - STM32CubeMX used for configuration

## Functions
```C
void ST7735_Init(void);

void ST7735_Unselect(void);
void ST7735_WriteChar(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_WriteInt(uint16_t x, uint16_t y, const int str, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_WriteFloat(uint16_t x, uint16_t y, const float str, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ST7735_WriteString(uint16_t x, uint16_t y, const char* str, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ST7735_FillScreen(uint16_t color);
void ST7735_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void ST7735_InvertColors(bool invert);
void ST7735_SetBaudRate(void);
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Credits

This library converted from [Adafruit Arduino Library](https://github.com/adafruit/Adafruit-ST7735-Library) to STM32 core. I would like to thank to Adafruit for creating this Arduino library.
