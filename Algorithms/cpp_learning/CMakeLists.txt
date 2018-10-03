cmake_minimum_required(VERSION 3.6)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 14)

# サブディレクトリ内のソースをすべてプロジェクトにぶちこむマクロ
MACRO(ADD_ALL_SUBDIR)
    FILE(GLOB children *)
#    FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
    FOREACH(child ${children})
        message(${child})
        IF(IS_DIRECTORY ${child})
            # CMakeがディレクトリにあるか(1のパターン)無いか(2のパターン)で分岐
            IF(EXISTS ${child}/CMakeLists.txt)
                add_subdirectory(${child})
            ELSE()
                aux_source_directory(${child} SOURCE)
            ENDIF()
        ENDIF()
    ENDFOREACH()
ENDMACRO()

ADD_ALL_SUBDIR()

add_executable(main main.cpp lib.cpp lib.h)

IF(SOURCE)
    add_executable(asf ${SOURCE})
ENDIF()
