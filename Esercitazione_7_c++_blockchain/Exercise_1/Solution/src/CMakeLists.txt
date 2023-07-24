list(APPEND blockchainSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/test_blockchain.hpp)
list(APPEND blockchainSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/blockchain.hpp)

list(APPEND blockchainSolution_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(blockchainSolution_sources ${blockchainSolution_sources} PARENT_SCOPE)
set(blockchainSolution_headers ${blockchainSolution_headers} PARENT_SCOPE)
set(blockchainSolution_includes ${blockchainSolution_includes} PARENT_SCOPE)
