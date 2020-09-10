
## mlog

mlog 是一套简单易用的日志宏

特性:
- 支持全局开关日志
- 支持全局设置静态日志默认级别
- 支持按文件设置静态日志级别
- 支持动态日志级别设置
- 支持配置日志格式, 打印函数, 换行符

### 使用

- 编译选项 `-DMLOG_ENALBE` 开启日志

- 编译选项 `-DMLOG_LEVEL_DEFAULT=MLOG_LEVEL_XXX` 设置默认级别

- .c 文件中, 添加

```
#include "mlog_config.h"                        // 对该文件的 mlog 配置
#define MLOG_MODULE         "xxx"               // 设置module, 不定义的话, keil 和 iar 下 module 为文件名, gcc 下 为 undefined
#define MLOG_LEVEL          XXX_LOG_LEVEL       // 设置该文件的静态日志级别, 不定义的话, 使用默认级别
#include "mlog.h"

```

- `mlog_xxx` 为静态编译日志, 级别在编译期间确定, 运行过程中不可修改. `mlogd_xxx` 为动态级别日志, 可在运行过程中修改级别

## 示例运行

```
make; make run
```