/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-17     armink       the first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtconfig.h>
#include <board.h>

#define NOR_FLASH_DEV_NAME             "norflash0"

/* ===================== Flash device Configuration ========================= */
extern struct fal_flash_dev w601_onchip_flash;
extern struct fal_flash_dev nor_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &w601_onchip_flash,                                           \
    &nor_flash0,                                                     \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define FAL_PART_TABLE                                                               \
{                                                                                    \
    {FAL_PART_MAGIC_WROD, "app",        "w60x_onchip",                                         0, 959 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD, "easyflash",  NOR_FLASH_DEV_NAME,                                   0, 1024 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD, "download",   NOR_FLASH_DEV_NAME,                       (1024) * 1024, 1024 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD, "font",       NOR_FLASH_DEV_NAME,            (1024 + 1024) * 1024, 7 * 1024 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD, "filesystem", NOR_FLASH_DEV_NAME, (1024 + 1024 + 7 * 1024) * 1024, 7 * 1024 * 1024, 0}, \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
