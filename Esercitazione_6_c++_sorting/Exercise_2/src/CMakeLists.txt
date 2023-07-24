list(APPEND heapsort_headers ${CMAKE_CURRENT_SOURCE_DIR}/sorting.hpp)
list(APPEND heapsort_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_sorting.hpp)

list(APPEND heapsort_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(heapsort_sources ${heapsort_sources} PARENT_SCOPE)
set(heapsort_headers ${heapsort_headers} PARENT_SCOPE)
set(heapsort_includes ${heapsort_includes} PARENT_SCOPE)
