list(APPEND pagerankSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/web.hpp)
list(APPEND pagerankSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/sorting.hpp)
list(APPEND pagerankSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_pagerank.hpp)

list(APPEND pagerankSolution_sources ${CMAKE_CURRENT_SOURCE_DIR}/web.cpp)

list(APPEND pagerankSolution_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(pagerankSolution_sources ${pagerankSolution_sources} PARENT_SCOPE)
set(pagerankSolution_headers ${pagerankSolution_headers} PARENT_SCOPE)
set(pagerankSolution_includes ${pagerankSolution_includes} PARENT_SCOPE)
