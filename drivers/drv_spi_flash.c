#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"


#include "drv_spi.h"
#include "string.h"
#include "spi_flash.h"
#include "spi_flash_sfud.h"

int wm_nor_flash_init(void)
{
    rt_spi_flash_device_t spi_device;

    wm_spi_bus_attach_device(WM_SPI_BUS_NAME, SPI_FLASH_DEVICE_NAME, PIN_FLASH_CS);
    spi_device = rt_sfud_flash_probe(SPI_FLASH_TYPE_NAME, SPI_FLASH_DEVICE_NAME);
    if (spi_device == RT_NULL)
    {
        return -RT_ERROR;
    }
    return 0;
}
INIT_DEVICE_EXPORT(wm_nor_flash_init);
