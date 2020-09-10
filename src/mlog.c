/* Copyright (c) 2020 huayuan, <wanghuayuan0@163.com>
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "mlog.h"

#ifdef MLOG_ENABLE

static uint32_t m_mlogd_level = MLOG_LEVEL_DEFAULT;

void mlog_dump(void * p_buffer, uint32_t len)
{
    uint8_t *p = (uint8_t *)p_buffer;
    for (uint32_t i = 0; i <  len; i++)
    {
        MLOG_PRINTF(MLOG_DUMP_FORMAT, p[i]);
    }
    MLOG_PRINTF(MLOG_LINE_ENDING);
}

void mlogd_level_set(uint32_t level)
{
    m_mlogd_level = level;
}

uint32_t mlogd_level_get(void)
{
    return m_mlogd_level;
}

#endif // MLOG_ENABLE
