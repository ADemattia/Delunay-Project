list(APPEND blockchain_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_blockchain.hpp)
list(APPEND blockchain_headers ${CMAKE_CURRENT_SOURCE_DIR}/blockchain.hpp)

list(APPEND blockchain_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(blockchain_sources ${blockchain_sources} PARENT_SCOPE)
set(blockchain_headers ${blockchain_headers} PARENT_SCOPE)
set(blockchain_includes ${blockchain_includes} PARENT_SCOPE)
