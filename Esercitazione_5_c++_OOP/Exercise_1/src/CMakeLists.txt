list(APPEND car_headers ${CMAKE_CURRENT_SOURCE_DIR}/car.hpp)
list(APPEND car_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_car.hpp)

list(APPEND car_sources ${CMAKE_CURRENT_SOURCE_DIR}/car.cpp)

list(APPEND car_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(car_sources ${car_sources} PARENT_SCOPE)
set(car_headers ${car_headers} PARENT_SCOPE)
set(car_includes ${car_includes} PARENT_SCOPE)
