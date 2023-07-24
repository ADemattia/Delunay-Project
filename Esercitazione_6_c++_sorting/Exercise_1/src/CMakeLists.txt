list(APPEND pagerank_headers ${CMAKE_CURRENT_SOURCE_DIR}/web.hpp)
list(APPEND pagerank_headers ${CMAKE_CURRENT_SOURCE_DIR}/sorting.hpp)
list(APPEND pagerank_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_pagerank.hpp)

list(APPEND pagerank_sources ${CMAKE_CURRENT_SOURCE_DIR}/web.cpp)

list(APPEND pagerank_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(pagerank_sources ${pagerank_sources} PARENT_SCOPE)
set(pagerank_headers ${pagerank_headers} PARENT_SCOPE)
set(pagerank_includes ${pagerank_includes} PARENT_SCOPE)
