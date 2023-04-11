cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(CompetitiveProgrammingLib)

add_library(
    Lib INTERFACE
)

target_include_directories(
    Lib INTERFACE
        include
)

file(GLOB_RECURSE SAMPLES_SOURCES "Samples/**.cpp")

foreach(FILE IN LISTS SAMPLES_SOURCES)
    cmake_path(GET FILE PARENT_PATH PARENT)
    cmake_path(GET PARENT STEM PARENT_STEM)
    cmake_path(GET FILE STEM FILE_STEM)

    add_executable(
        Samples-${PARENT_STEM}-${FILE_STEM} 
            ${FILE}
    )

    target_link_libraries(
        Samples-${PARENT_STEM}-${FILE_STEM} PRIVATE 
            Lib
    )

    set_target_properties(
        Samples-${PARENT_STEM}-${FILE_STEM} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${PARENT}/bin
            RUNTIME_OUTPUT_NAME ${FILE_STEM}
            SUFFIX ""
    )
endforeach()

file(GLOB_RECURSE PROBLEMS_SOURCES "Problems/**.cpp")

foreach(FILE IN LISTS PROBLEMS_SOURCES)
    cmake_path(GET FILE PARENT_PATH PARENT)
    cmake_path(GET PARENT STEM PARENT_STEM)
    cmake_path(GET FILE STEM FILE_STEM)

    add_executable(
        Problems-${PARENT_STEM}-${FILE_STEM} 
            ${FILE}
    )

    target_link_libraries(
        Problems-${PARENT_STEM}-${FILE_STEM} PRIVATE 
            Lib
    )

    set_target_properties(
        Problems-${PARENT_STEM}-${FILE_STEM} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${PARENT}/bin
            RUNTIME_OUTPUT_NAME ${FILE_STEM}
            SUFFIX ""
    )
endforeach()
