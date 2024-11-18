set(LIB_NAME tools_export_lib)

# GLOB_RECURSE 递归子文件夹
file(GLOB LIB_SOURCES "./*.c" )
add_library(${LIB_NAME} ${LIB_SOURCES})
target_include_directories(${LIB_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# 依赖
target_link_libraries(${LIB_NAME} PRIVATE tools_cmd_lib)

