#include "drv_tf_spi.h"
#include <rtdevice.h>
#include "drv_spi.h"
#include "spi_msd.h"
#include "board.h"

#ifdef BSP_USING_TF_CARD

static int rt_hw_spi0_tfcard(void)
{
    wm_spi_bus_attach_device(WM_SPI_BUS_NAME, "tf_spi", PIN_SD_CS);
    return msd_init("sd0", "tf_spi");
}
INIT_COMPONENT_EXPORT(rt_hw_spi0_tfcard);

#endif

