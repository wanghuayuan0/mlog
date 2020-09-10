/* Copyright (c) 2020 huayuan, <wanghuayuan0@163.com>
 *
 */

#ifndef MLOG_CONFIG_H__
#define MLOG_CONFIG_H__

/**
 * Redefine the log format
 */
//#define MLOG_ASSERT_FORMAT                       ""
//#define MLOG_ERROR_FORMAT                        ""
//#define MLOG_WARN_FORMAT                         ""
//#define MLOG_NOTICE_FORMAT                       ""
//#define MLOG_INFO_FORMAT                         ""
//#define MLOG_DEBUG_FORMAT                        ""
//#define MLOG_VERBOSE_FORMAT                      ""
//#deifne MLOG_DUMP_FORMAT                         ""

//#define MLOG_LINE_ENDING                        "\r\n"

//#define MLOG_PRINTF                             xx_print

#define MAIN_LOG_LEVEL                          MLOG_LEVEL_INFO
#define TEST_STATIC_LOG_LEVEL                   MLOG_LEVEL_NOTICE

#endif