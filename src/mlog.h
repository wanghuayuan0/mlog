/* Copyright (c) 2020 huayuan, <wanghuayuan0@163.com>
 *
 */

#ifndef MLOG_H__
#define MLOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>

#ifdef MLOG_ENABLE

#define MLOG_LEVEL_DISABLED                     0
#define MLOG_LEVEL_ASSERT                       1
#define MLOG_LEVEL_ERROR                        2
#define MLOG_LEVEL_WARN                         3
#define MLOG_LEVEL_NOTICE                       4
#define MLOG_LEVEL_INFO                         5
#define MLOG_LEVEL_DEBUG                        6
#define MLOG_LEVEL_VERBOSE                      7

#ifndef MLOG_LEVEL_DEFAULT
#define MLOG_LEVEL_DEFAULT                      MLOG_LEVEL_DEBUG
#endif

#ifndef MLOG_LEVEL
#define MLOG_LEVEL                              MLOG_LEVEL_DEFAULT
#endif

#if defined(__CC_ARM)

#ifndef MLOG_MODULE
#define MLOG_MODULE                             __MODULE__
#endif

#else // defined(__CC_ARM)

#ifndef MLOG_MODULE
#define MLOG_MODULE                             "undefined"
#endif

#endif // defined(__CC_ARM)


#ifndef MLOG_ASSERT_FORMAT
#define MLOG_ASSERT_FORMAT                      "%-10s\t%4d [A] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_ERROR_FORMAT
#define MLOG_ERROR_FORMAT                       "%-10s\t%4d [E] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_WARN_FORMAT
#define MLOG_WARN_FORMAT                        "%-10s\t%4d [W] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_NOTICE_FORMAT
#define MLOG_NOTICE_FORMAT                      "%-10s\t%4d [N] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_INFO_FORMAT
#define MLOG_INFO_FORMAT                        "%-10s\t%4d [I] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_DEBUG_FORMAT
#define MLOG_DEBUG_FORMAT                       "%-10s\t%4d [D] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_VERBOSE_FORMAT
#define MLOG_VERBOSE_FORMAT                     "%-10s\t%4d [V] ", MLOG_MODULE, __LINE__
#endif

#ifndef MLOG_DUMP_FORMAT
#define MLOG_DUMP_FORMAT                        "%02X"
#endif

#ifndef MLOG_LINE_ENDING
#define MLOG_LINE_ENDING                        "\n"
#endif

#ifndef MLOG_PRINTF
#define MLOG_PRINTF                             printf
#endif

#define mlog_printf                             MLOG_PRINTF

/**
 * log macro static
 */

#define MLOG_FORMAT_PRINT(format, msg, ...)                     \
do {                                                            \
    MLOG_PRINTF(format);                                        \
    MLOG_PRINTF(msg, ##__VA_ARGS__);                            \
} while(0)


#if MLOG_LEVEL >= MLOG_LEVEL_ASSERT
#define mlog_assert(value, msg, ...)    {if(!value){MLOG_FORMAT_PRINT(MLOG_ASSERT_FORMAT, msg, ##__VA_ARGS__);}}
#define mlog_assertln(value, msg, ...)  {if(!value){MLOG_FORMAT_PRINT(MLOG_ASSERT_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__);}}
#define mlog_dump_a                     mlog_dump
#else
#define mlog_assert(msg, ...)
#define mlog_assertln(msg, ...)
#define mlog_dump_a(...)
#endif

#if MLOG_LEVEL >= MLOG_LEVEL_ERROR
#define mlog_error(msg, ...)            MLOG_FORMAT_PRINT(MLOG_ERROR_FORMAT, msg, ##__VA_ARGS__)
#define mlog_errorln(msg, ...)          MLOG_FORMAT_PRINT(MLOG_ERROR_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlog_dump_e                     mlog_dump
#else
#define mlog_error(msg, ...)
#define mlog_errorln(msg, ...)
#define mlog_dump_e(...)
#endif

#if MLOG_LEVEL >= MLOG_LEVEL_WARN
#define mlog_warn(msg, ...)             MLOG_FORMAT_PRINT(MLOG_WARN_FORMAT, msg, ##__VA_ARGS__)
#define mlog_warnln(msg, ...)           MLOG_FORMAT_PRINT(MLOG_WARN_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlog_dump_w                     mlog_dump
#else
#define mlog_warn(msg, ...)
#define mlog_warnln(msg, ...)
#define mlog_dump_w(...)
#endif

#if MLOG_LEVEL >= MLOG_LEVEL_NOTICE
#define mlog_notice(msg, ...)           MLOG_FORMAT_PRINT(MLOG_NOTICE_FORMAT, msg, ##__VA_ARGS__)
#define mlog_noticeln(msg, ...)         MLOG_FORMAT_PRINT(MLOG_NOTICE_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlog_dump_n                     mlog_dump
#else
#define mlog_notice(msg, ...)
#define mlog_noticeln(msg, ...)
#define mlog_dump_n(...)
#endif

#if MLOG_LEVEL >= MLOG_LEVEL_INFO
#define mlog_info(msg, ...)             MLOG_FORMAT_PRINT(MLOG_INFO_FORMAT, msg, ##__VA_ARGS__)
#define mlog_infoln(msg, ...)           MLOG_FORMAT_PRINT(MLOG_INFO_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlog_dump_i                     mlog_dump
#else
#define mlog_info(msg, ...)
#define mlog_infoln(msg, ...)
#define mlog_dump_i(...)
#endif

#if MLOG_LEVEL >= MLOG_LEVEL_DEBUG
#define mlog_debug(msg, ...)            MLOG_FORMAT_PRINT(MLOG_DEBUG_FORMAT, msg, ##__VA_ARGS__)
#define mlog_debugln(msg, ...)          MLOG_FORMAT_PRINT(MLOG_DEBUG_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlog_dump_d                     mlog_dump
#else
#define mlog_debug(msg, ...)
#define mlog_debugln(msg, ...)
#define mlog_dump_d(...)
#endif

#if MLOG_LEVEL == MLOG_LEVEL_VERBOSE
#define mlog_verbose(msg, ...)          MLOG_FORMAT_PRINT(MLOG_VERBOSE_FORMAT, msg, ##__VA_ARGS__)
#define mlog_verboseln(msg, ...)        MLOG_FORMAT_PRINT(MLOG_VERBOSE_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlog_dump_v                     mlog_dump
#else
#define mlog_verbose(msg, ...)
#define mlog_verboseln(msg, ...)
#define mlog_dump_v(...)
#endif


/**
 * log macro with dynamic level
 */

#define MLOGD_FORMAT_PRINT(level, format, msg, ...)             \
do {                                                            \
    if(mlogd_level_get() >= (level)){                           \
        MLOG_PRINTF(format);                                    \
        MLOG_PRINTF(msg, ##__VA_ARGS__);                        \
    }                                                           \
} while(0)

#define MLOGD_DUMP(level, p_buffer, len)                        \
do {                                                            \
    if(mlogd_level_get() >= (level))                            \
        mlog_dump(p_buffer,len);                                \
} while(0)

#define mlogd_assert(value, msg, ...)    {if(!(value)){MLOGD_FORMAT_PRINT(MLOG_LEVEL_ASSERT, MLOG_ASSERT_FORMAT, msg, ##__VA_ARGS__);}}
#define mlogd_assertln(value, msg, ...)  {if(!(value)){MLOGD_FORMAT_PRINT(MLOG_LEVEL_ASSERT, MLOG_ASSERT_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__);}}
#define mlogd_dump_a(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_ASSERT, p_buffer, len);

#define mlogd_error(msg, ...)            MLOGD_FORMAT_PRINT(MLOG_LEVEL_ERROR, MLOG_ERROR_FORMAT, msg, ##__VA_ARGS__)
#define mlogd_errorln(msg, ...)          MLOGD_FORMAT_PRINT(MLOG_LEVEL_ERROR, MLOG_ERROR_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlogd_dump_e(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_ERROR, p_buffer, len);

#define mlogd_warn(msg, ...)             MLOGD_FORMAT_PRINT(MLOG_LEVEL_WARN, MLOG_WARN_FORMAT, msg, ##__VA_ARGS__)
#define mlogd_warnln(msg, ...)           MLOGD_FORMAT_PRINT(MLOG_LEVEL_WARN, MLOG_WARN_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlogd_dump_w(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_WARN, p_buffer, len);

#define mlogd_notice(msg, ...)           MLOGD_FORMAT_PRINT(MLOG_LEVEL_NOTICE, MLOG_NOTICE_FORMAT, msg, ##__VA_ARGS__)
#define mlogd_noticeln(msg, ...)         MLOGD_FORMAT_PRINT(MLOG_LEVEL_NOTICE, MLOG_NOTICE_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlogd_dump_n(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_NOTICE, p_buffer, len);

#define mlogd_debug(msg, ...)            MLOGD_FORMAT_PRINT(MLOG_LEVEL_DEBUG, MLOG_DEBUG_FORMAT, msg, ##__VA_ARGS__)
#define mlogd_debugln(msg, ...)          MLOGD_FORMAT_PRINT(MLOG_LEVEL_DEBUG, MLOG_DEBUG_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlogd_dump_d(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_DEBUG, p_buffer, len);

#define mlogd_info(msg, ...)             MLOGD_FORMAT_PRINT(MLOG_LEVEL_INFO, MLOG_INFO_FORMAT, msg, ##__VA_ARGS__)
#define mlogd_infoln(msg, ...)           MLOGD_FORMAT_PRINT(MLOG_LEVEL_INFO, MLOG_INFO_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlogd_dump_i(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_INFO, p_buffer, len);

#define mlogd_verbose(msg, ...)          MLOGD_FORMAT_PRINT(MLOG_LEVEL_VERBOSE, MLOG_VERBOSE_FORMAT, msg, ##__VA_ARGS__)
#define mlogd_verboseln(msg, ...)        MLOGD_FORMAT_PRINT(MLOG_LEVEL_VERBOSE, MLOG_VERBOSE_FORMAT, msg MLOG_LINE_ENDING, ##__VA_ARGS__)
#define mlogd_dump_v(p_buffer,len)       MLOGD_DUMP(MLOG_LEVEL_VERBOSE, p_buffer, len);

/**
 * Dump a buffer.
 *
 * @param    p_buffer    Buffer to dump
 * @param    len         Buffer length
 */
void mlog_dump(void * p_buffer, uint32_t len);

/**
 * mlogd level set
 *
 * @param    level    mlogd level
 */
void mlogd_level_set(uint32_t level);

/**
 * mlogd level get
 *
 * @retval        mlogd level
 */
uint32_t mlogd_level_get(void);

#else // MLOG_ENABLE

#define mlog_init(...)
#define mlog_printf(...)
#define mlog_dump(...)
#define mlogd_level_set(...)
#define mlogd_level_get()   0

#define mlog_assert(...)
#define mlog_assertln(...)
#define mlog_dump_a(...)
#define mlogd_assert(...)
#define mlogd_assertln(...)
#define mlogd_dump_a(...)

#define mlog_error(...)
#define mlog_errorln(...)
#define mlog_dump_e(...)
#define mlogd_error(...)
#define mlogd_errorln(...)
#define mlogd_dump_e(...)

#define mlog_warn(...)
#define mlog_warnln(...)
#define mlog_dump_w(...)
#define mlogd_warn(...)
#define mlogd_warnln(...)
#define mlogd_dump_w(...)

#define mlog_notice(...)
#define mlog_noticeln(...)
#define mlog_dump_n(...)
#define mlogd_notice(...)
#define mlogd_noticeln(...)
#define mlogd_dump_n(...)

#define mlog_info(...)
#define mlog_infoln(...)
#define mlog_dump_i(...)
#define mlogd_info(...)
#define mlogd_infoln(...)
#define mlogd_dump_i(...)

#define mlog_debug(...)
#define mlog_debugln(...)
#define mlog_dump_d(...)
#define mlogd_debug(...)
#define mlogd_debugln(...)
#define mlogd_dump_d(...)

#define mlog_verbose(...)
#define mlog_verboseln(...)
#define mlog_dump_v(...)
#define mlogd_verbose(...)
#define mlogd_verboseln(...)
#define mlogd_dump_v(...)

#endif // MLOG_ENABLE

#ifdef __cplusplus
}
#endif

#endif
