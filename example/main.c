/* Copyright (c) 2020 huayuan, <wanghuayuan0@163.com>
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include "test.h"

#include "mlog_config.h"
#define MLOG_MODULE         "main"
// #define MLOG_LEVEL          APP_LOG_LEVEL
#include "mlog.h"


int main(void)
{
    uint8_t data[] = {0x11, 0x22, 0x33, 0x44};

    printf("main log level is %d\n", MLOG_LEVEL);

    mlog_assertln(false, "main log test %s, %d", "xxx", 123);
    mlog_errorln("main log test %s, %d", "xxx", 123);
    mlog_warnln("main log test %s, %d", "xxx", 123);
    mlog_noticeln("main log test %s, %d", "xxx", 123);
    mlog_infoln("main log test %s, %d", "xxx", 123);
    mlog_debugln("main log test %s, %d", "xxx", 123);
    mlog_verboseln("main log test %s, %d", "xxx", 123);
    mlog_info("main log test, dump: ");
    mlog_dump_i(data, sizeof(data));

    printf("----------------\n");

    test_static();
    test_dynamic();

    return 0;
}
