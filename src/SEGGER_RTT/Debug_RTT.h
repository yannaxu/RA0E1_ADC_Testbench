#ifndef DEBUG_RTT_H
#define DEBUG_RTT_H

#include <stdint.h>

#define DEBUG_RTT_ENABLE    1

#if DEBUG_RTT_ENABLE

#include "SEGGER_RTT.h"

#define Debug_RTT_WriteString(ch, str) \
    SEGGER_RTT_WriteString((ch), (str))

#define Debug_RTT_printf(ch, fmt, ...) \
    SEGGER_RTT_printf((ch), (fmt), ##__VA_ARGS__)

#else

#define Debug_RTT_WriteString(ch, str) \
    do { (void)(ch); (void)(str); } while (0)

#define Debug_RTT_printf(ch, fmt, ...) \
    do { (void)(ch); } while (0)

#endif

#endif
