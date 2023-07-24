list(APPEND quadrature_headers ${CMAKE_CURRENT_SOURCE_DIR}/quadrature.hpp)
list(APPEND quadrature_headers ${CMAKE_CURRENT_SOURCE_DIR}/mapTriangle.hpp)
list(APPEND quadrature_headers ${CMAKE_CURRENT_SOURCE_DIR}/gauss_quadrature_1D.hpp)
list(APPEND quadrature_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_quadrature.hpp)

list(APPEND quadrature_sources ${CMAKE_CURRENT_SOURCE_DIR}/quadrature.cpp)
list(APPEND quadrature_headers ${CMAKE_CURRENT_SOURCE_DIR}/mapTriangle.cpp)

list(APPEND quadrature_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(quadrature_sources ${quadrature_sources} PARENT_SCOPE)
set(quadrature_headers ${quadrature_headers} PARENT_SCOPE)
set(quadrature_includes ${quadrature_includes} PARENT_SCOPE)
