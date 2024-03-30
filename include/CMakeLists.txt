#file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
#
#foreach(SUBDIR ${SUBDIRECTORIES})
#    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
#        # Добавляем подпапку в обработку
#        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
#    endif()
#endforeach()
