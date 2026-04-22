cmake_minimum_required(VERSION 3.10)
project(CommandGodWorkspace)

set(CMAKE_CXX_STANDARD 17)

# Include directories for your vendor libraries
include_directories(vendor/imgui vendor/nlohmann vendor/stb)

# Add your source files
file(GLOB SOURCES "src/*.cpp" "vendor/imgui/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Link OpenGL and GLFW (Windowing library needed for ImGui)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)
