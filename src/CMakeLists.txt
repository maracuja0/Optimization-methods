file(GLOB SOURCE_FILES "*.cpp")

add_executable(MOLR ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/numerics)

#target_include_directories(MOLR PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_include_directories(MOLR PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/numerics)

