file(GLOB SOURCE_FILES "*.cpp")

add_executable(MOLR ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR}/include)