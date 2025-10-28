# Tell CMake where to find Homebrew libraries
link_directories(/opt/homebrew/lib)
cmake_minimum_required(VERSION 3.10)
project(StudentDBMS)
set(CMAKE_CXX_STANDARD 17)

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(StudentDBMS
    src/main.cpp
    src/DatabaseManager.cpp
    src/Student.cpp
    src/Admin.cpp
)


# Explicitly add v_noabi include directories for Homebrew MongoDB C++ driver
target_include_directories(StudentDBMS PRIVATE
    /opt/homebrew/include
    /opt/homebrew/include/bsoncxx/v_noabi
    /opt/homebrew/include/mongocxx/v_noabi
)

target_link_libraries(StudentDBMS PRIVATE mongocxx bsoncxx)