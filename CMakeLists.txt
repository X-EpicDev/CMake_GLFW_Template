# -------------------- PROJECT SETUP -------------------- #
cmake_minimum_required(VERSION 3.14)
project(OpenGL_Learning)

set(CMAKE_CXX_STANDARD 11)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")

# ------------------ CREATE EXECUTABLE ------------------ #
add_executable(${PROJECT_NAME} src/main.cpp src/Shader.cpp src/Shader.h)

# --------------------- IMPORT GLAD --------------------- #
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

# --------------------- IMPORT GLFW --------------------- #
set(GLFW_DIR "${LIB_DIR}/glfw")
add_subdirectory("${GLFW_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")

# -------------------- CHECK PLATFORM -------------------- #
if (APPLE)
    message(STATUS "Platform is Apple")
    add_compile_definitions(PLATFORM_APPLE)
endif ()

if (WIN32)
    message(STATUS "Platform is Windows")
    add_compile_definitions(PLATFORM_WINDOWS)
endif ()