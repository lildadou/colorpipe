cmake_minimum_required(VERSION 3.10)

project(colorpipe
        LANGUAGES CXX
        DESCRIPTION "Color adjustements library"
        VERSION 0.0.1
)

add_library(colorpipe
        src/libcolorpipe.cc
        )

target_include_directories(colorpipe
        PUBLIC include
        )

target_compile_features(colorpipe
        PUBLIC
            cxx_alias_templates
            cxx_std_11
)


add_subdirectory(test)
#install(TARGETS colorpipe
#        EXPORT colorpipe-export
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#)
