include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/numerics)

add_executable(test_oneDimensional oneDimensional_test.cpp)

add_test(NAME TestOneDimensional COMMAND test_oneDimensional)