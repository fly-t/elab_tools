/*
 * eLab Project
 * Copyright (c) 2023, EventOS Team, <event-os@outlook.com>
 */

#ifndef ELAB_DEF_H
#define ELAB_DEF_H

#include <stdint.h>

typedef enum elab_err
{
    ELAB_OK = 0,
    ELAB_ERROR = -1,
    ELAB_ERR_EMPTY = -2,
    ELAB_ERR_FULL = -3,
    ELAB_ERR_TIMEOUT = -4,
    ELAB_ERR_BUSY = -5,
    ELAB_ERR_NO_MEMORY = -6,
    ELAB_ERR_IO = -7,
    ELAB_ERR_INVALID = -8,
    ELAB_ERR_MEM_OVERLAY = -9,
    ELAB_ERR_MALLOC = -10,
    ELAB_ERR_NOT_ENOUGH = -11,
} elab_err_t;

typedef struct elab_date
{
    uint32_t year : 16;
    uint32_t month : 8;
    uint32_t day : 8;
} elab_date_t;

typedef struct elab_time
{
    uint8_t hour;
    uint8_t minute;
    uint16_t second : 6;
    uint16_t ms : 10;
} elab_time_t;

/**
 * Cast a member of a structure out to the containing structure.
 * @ptr:    the pointer to the member.
 * @type:   the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 */
#ifndef container_of
#define container_of(pointer, type, member)             \
    ({                                                  \
        void *__pointer = (void *)(pointer);            \
        ((type *)(__pointer - offsetof(type, member))); \
    })
#endif

#ifndef offsetof
#define offsetof(type, member) ((uint32_t) & ((type *)0)->member)
#endif

#include <stdarg.h>
#define ELAB_SECTION(x) __attribute__((section(x)))
#define ELAB_USED __attribute__((used))
#define ELAB_ALIGN(n) __attribute__((aligned(n)))
#define ELAB_WEAK __attribute__((weak))
#define ELAB_INLINE static __inline

#endif
