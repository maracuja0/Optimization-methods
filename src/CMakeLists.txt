file(GLOB SOURCE_FILES "*.cpp")

add_executable(MOLR ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/numerics)
include_directories(${CMAKE_SOURCE_DIR}/include/numerics/linalg)
include_directories(${CMAKE_SOURCE_DIR}/include/numerics/rational)


