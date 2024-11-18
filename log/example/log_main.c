#include "elab_log.h"
#include <stdio.h>

ELAB_TAG("log_main.c");

int main(void)
{
    elog_level_set(ELOG_LEVEL_DEBUG);

    elog_info("debug elog_info");
    elog_debug("debug elog_debug");
    elog_error("debug elog_error");
    elog_warn("debug elog_warn");

    return 0;
}