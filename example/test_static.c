/* Copyright (c) 2020 huayuan, <wanghuayuan0@163.com>
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "mlog_config.h"
#define MLOG_MODULE         "static"
#define MLOG_LEVEL          TEST_STATIC_LOG_LEVEL
#include "mlog.h"

void test_static(void)
{
    uint8_t data[] = {0x11, 0x22, 0x33, 0x44};

    printf("test_static log level is %d\n", MLOG_LEVEL);

    mlog_assertln(false, "static log test %s, %d", "xxx", 123);
    mlog_errorln("static log test %s, %d", "xxx", 123);
    mlog_warnln("static log test %s, %d", "xxx", 123);
    mlog_noticeln("static log test %s, %d", "xxx", 123);
    mlog_infoln("static log test %s, %d", "xxx", 123);
    mlog_debugln("static log test %s, %d", "xxx", 123);
    mlog_verboseln("static log test %s, %d", "xxx", 123);
    mlog_info("static log test, dump: ");
    mlog_dump_i(data, sizeof(data));

    printf("----------------\n");
}
