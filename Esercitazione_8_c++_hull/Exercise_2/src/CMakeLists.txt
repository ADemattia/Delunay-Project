list(APPEND convexHull_headers ${CMAKE_CURRENT_SOURCE_DIR}/convexHull.hpp)
list(APPEND convexHull_headers ${CMAKE_CURRENT_SOURCE_DIR}/sorting.hpp)
list(APPEND convexHull_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_convexHull.hpp)

list(APPEND convexHull_sources ${CMAKE_CURRENT_SOURCE_DIR}/convexHull.cpp)

list(APPEND convexHull_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(convexHull_sources ${convexHull_sources} PARENT_SCOPE)
set(convexHull_headers ${convexHull_headers} PARENT_SCOPE)
set(convexHull_includes ${convexHull_includes} PARENT_SCOPE)
