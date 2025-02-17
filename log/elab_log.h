
#ifndef ELAB_LOG_H_
#define ELAB_LOG_H_
#include <stdint.h>

#define ELAB_TAG(_tag) static const char *TAG = _tag

#define ELOG_COLOR_ENABLE (1)

enum elog_level_enum
{
    ELOG_LEVEL_NONE = 0,
    ELOG_LEVEL_ERROR,
    ELOG_LEVEL_WARNING,
    ELOG_LEVEL_INFO,
    ELOG_LEVEL_DEBUG,

    ELOG_LEVEL_MAX,
};

void elog_level_set(uint8_t level);

#ifndef ELOG_DISABLE
void _elog_printf(const char *tag, uint8_t level, const char *s_format, ...);

/* Enable error level debug message */
#define elog_error(...) _elog_printf(TAG, ELOG_LEVEL_ERROR, __VA_ARGS__)
#define elog_warn(...) _elog_printf(TAG, ELOG_LEVEL_WARNING, __VA_ARGS__)
#define elog_info(...) _elog_printf(TAG, ELOG_LEVEL_INFO, __VA_ARGS__)
#define elog_debug(...) _elog_printf(TAG, ELOG_LEVEL_DEBUG, __VA_ARGS__)

#else

#define elog_error(...)
#define elog_warn(...)
#define elog_info(...)
#define elog_debug(...)

#endif

#endif /* ELAB_LOG_H_ */

/* ----------------------------- end of file -------------------------------- */
