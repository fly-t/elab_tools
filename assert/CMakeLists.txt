set(LIB_NAME tools_assert_lib)

file(GLOB LIB_SOURCES "./*.c" )
add_library(${LIB_NAME} ${LIB_SOURCES})
target_include_directories(${LIB_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# 依赖
target_link_libraries(${LIB_NAME} PRIVATE tools_log_lib)

