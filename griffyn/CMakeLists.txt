cmake_minimum_required(VERSION 3.0.0)
project(g_isp VERSION 0.1.0)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

find_package(OpenCV REQUIRED)

MESSAGE (${PROJECT_SOURCE_DIR})

include_directories(/usr/include/
                    ${OpenCV_INCLUDE_DIRS}
                    ${PROJECT_SOURCE_DIR}/include/)


link_libraries(${OpenCV_LINK_LIBS})

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} argparse jsoncpp)

