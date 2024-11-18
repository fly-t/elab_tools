/*
 * eLab Project
 * Copyright (c) 2023, EventOS Team, <event-os@outlook.com>
 */

/* include ------------------------------------------------------------------ */
#include <stdio.h>
#include <stdarg.h>
#include "elab_log.h"

#define ELAB_LOG_BUFF_SIZE (256)

/* define printf color */
#define NONE "\033[0;0m"
#define LIGHT_RED "\033[1;31m"
#define YELLOW "\033[0;33m"
#define LIGHT_BLUE "\033[1;34m"
#define ORANGE "\033[38;5;214m" // 214 是在 256 色模式下接近橙色的编号
#define GREEN "\033[0;32m"
#define RESET_COLOR "\033[0m" // ANSI 转义码，重置颜色

static uint8_t elog_level = ELOG_LEVEL_DEBUG;

#if (ELOG_COLOR_ENABLE != 0)
static const char *const elog_color_table[ELOG_LEVEL_MAX] =
    {
        NONE,
        LIGHT_RED,
        YELLOW,
        GREEN,
        ORANGE,
};
#endif

static const char elog_level_lable[ELOG_LEVEL_MAX] =
    {
        ' ',
        'E',
        'W',
        'I',
        'D',
};

static char _buff[ELAB_LOG_BUFF_SIZE];
__attribute__((weak)) uint32_t elab_time_ms(void);

void elog_level_set(uint8_t level)
{
    elog_level = level;
}

void _elog_printf(const char *name, uint8_t level, const char *s_format, ...)
{
    if (elog_level >= level)
    {
        printf("%s %c:(%u) %s ", elog_color_table[level],
               elog_level_lable[level], elab_time_ms(), name);
        va_list param_list;
        va_start(param_list, s_format);
        int count = vsnprintf(_buff, (ELAB_LOG_BUFF_SIZE - 1), s_format, param_list);
        va_end(param_list);
        _buff[count] = 0;
        printf("%s", _buff);
        printf("\r\n");
        printf(RESET_COLOR);
    }
}
#include "stm32f4xx_hal.h"
/* 移植获取 systick 的函数 */
__attribute__((weak)) uint32_t elab_time_ms(void)
{
    return HAL_GetTick();;
}
