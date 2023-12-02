cmake_minimum_required(VERSION 3.15)
project(gil)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8  -fexec-charset=UTF-8")

# target_include_directories(${PROJECT_NAME}
#     "include"
# )

# set(GIL_SOURCE
    
# )

# add_executable(${PROJECT_NAME}
#     ${GIL_SOURCE}
# )

add_executable(test_read_file
    test/test_read_file.cpp
)

add_executable(test_read_file2
    test/test_read_file2.cpp
)