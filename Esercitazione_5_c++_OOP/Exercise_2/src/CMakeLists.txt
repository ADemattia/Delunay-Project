list(APPEND polygon_headers ${CMAKE_CURRENT_SOURCE_DIR}/shape.hpp)
list(APPEND polygon_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_shape.hpp)

list(APPEND polygon_sources ${CMAKE_CURRENT_SOURCE_DIR}/shape.cpp)

list(APPEND polygon_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(polygon_sources ${polygon_sources} PARENT_SCOPE)
set(polygon_headers ${polygon_headers} PARENT_SCOPE)
set(polygon_includes ${polygon_includes} PARENT_SCOPE)
