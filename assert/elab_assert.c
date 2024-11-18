#include <stdio.h>
#include <stddef.h>
#include "elab_assert.h"

/**
 * @brief  The internal assert function when assert fails.
 * @param  str_     The given string information, such as object name.
 * @param  id_      The given uint32_t information, such as object ID.
 * @param  tag      The file name setted by ELAG_TAG macro.
 * @param  location The assert location in file.
 */
void _assert(const char *str_, uint32_t id_, const char *tag, uint32_t location)
{
    printf("\033[1;31m"
           "Assert failure!\r\n");
    printf("Location: %s %d.\r\n", tag, location);
    if (str_ != NULL)
        printf("Assert info: %s.\r\n", str_);
    else
        printf("Assert info: %d.\r\n", id_);
    while (1)
    {
    }
}
