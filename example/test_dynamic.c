/* Copyright (c) 2020 huayuan, <wanghuayuan0@163.com>
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "mlog_config.h"
#define MLOG_MODULE         "dynamic"
#include "mlog.h"


void test_dynamic(void)
{
    uint8_t data[] = {0x11, 0x22, 0x33, 0x44};

    mlogd_level_set(MLOG_LEVEL_VERBOSE);

    printf("test_dynamic log level set to %d\n", mlogd_level_get());

    mlogd_assertln(false, "dynamic log test %s, %d", "xxx", 123);
    mlogd_errorln("dynamic log test %s, %d", "xxx", 123);
    mlogd_warnln("dynamic log test %s, %d", "xxx", 123);
    mlogd_noticeln("dynamic log test %s, %d", "xxx", 123);
    mlogd_infoln("dynamic log test %s, %d", "xxx", 123);
    mlogd_debugln("dynamic log test %s, %d", "xxx", 123);
    mlogd_verboseln("dynamic log test %s, %d", "xxx", 123);
    mlogd_info("dynamic log test, dump: ");
    mlogd_dump_i(data, sizeof(data));

    printf("----------------\n");

    mlogd_level_set(MLOG_LEVEL_NOTICE);

    printf("test_dynamic log level set to %d\n", mlogd_level_get());

    mlogd_assertln(false, "dynamic log test %s, %d", "xxx", 123);
    mlogd_errorln("dynamic log test %s, %d", "xxx", 123);
    mlogd_warnln("dynamic log test %s, %d", "xxx", 123);
    mlogd_noticeln("dynamic log test %s, %d", "xxx", 123);
    mlogd_infoln("dynamic log test %s, %d", "xxx", 123);
    mlogd_debugln("dynamic log test %s, %d", "xxx", 123);
    mlogd_verboseln("dynamic log test %s, %d", "xxx", 123);
    mlogd_info("dynamic log test, dump: ");
    mlogd_dump_i(data, sizeof(data));
}
