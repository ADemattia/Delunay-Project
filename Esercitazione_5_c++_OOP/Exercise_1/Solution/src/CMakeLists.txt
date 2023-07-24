list(APPEND carSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/car.hpp)
list(APPEND carSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_car.hpp)

list(APPEND carSolution_sources ${CMAKE_CURRENT_SOURCE_DIR}/car.cpp)

list(APPEND carSolution_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(carSolution_sources ${carSolution_sources} PARENT_SCOPE)
set(carSolution_headers ${carSolution_headers} PARENT_SCOPE)
set(carSolution_includes ${carSolution_includes} PARENT_SCOPE)
