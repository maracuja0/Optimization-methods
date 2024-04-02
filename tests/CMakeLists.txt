include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(test_oneDimensional oneDimensional_test.cpp)

add_test(NAME TestOneDimensional COMMAND test_oneDimensional)