list(APPEND delaunay_headers ${CMAKE_CURRENT_SOURCE_DIR}/empty_class.hpp)

list(APPEND delaunay_sources ${CMAKE_CURRENT_SOURCE_DIR}/empty_class.cpp)

list(APPEND delaunay_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(delaunay_sources ${delaunay_sources} PARENT_SCOPE)
set(delaunay_headers ${delaunay_headers} PARENT_SCOPE)
set(delaunay_includes ${delaunay_includes} PARENT_SCOPE)
