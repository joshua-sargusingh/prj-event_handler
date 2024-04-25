#min version
cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#project name
project (
    event_notifier
    LANGUAGES CXX C
)

#create library from common source files
add_library(event_lib
    src/event_notifier.c
)

#include the include folder
target_include_directories(event_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(event_lib PUBLIC -g3 -O0)

# Add executable and specify the source files
add_executable(main src/main.c)

# Link executable with the library
target_link_libraries(main PRIVATE event_lib)

# Include the tests directory for processing its CMakeLists.txt
add_subdirectory(tests)