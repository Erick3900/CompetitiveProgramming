file(GLOB_RECURSE PROBLEMS "${CMAKE_CURRENT_LIST_DIR}/**.cpp")

foreach(FILE IN LISTS PROBLEMS)
    cmake_path(GET FILE PARENT_PATH PARENT)
    cmake_path(GET FILE STEM FILE_STEM)
    
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" PROJECT_PATH "${PARENT}")
    string(REPLACE "/" "-" PROBLEM_SOURCE "${PROJECT_PATH}")
  
    set_target_properties(
        ${PROBLEM_SOURCE}-${FILE_STEM} PROPERTIES
            CXX_STANDARD 11
    )
endforeach()
