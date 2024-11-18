#ifndef ELAB_ASSERT_H
#define ELAB_ASSERT_H

#include <stdint.h>
#include "elab_log.h"

#define elab_assert(test_)                     \
    do                                         \
    {                                          \
        if (!(test_))                          \
            _assert(#test_, 0, TAG, __LINE__); \
    } while (0)

#define assert(test_) elab_assert(test_)

void _assert(const char *str_, uint32_t id_, const char *tag, uint32_t location);

#endif // ELAB_ASSERT_H
