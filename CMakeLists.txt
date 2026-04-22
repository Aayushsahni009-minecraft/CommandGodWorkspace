cmake_minimum_required(VERSION 3.10)
project(CommandGodWorkspace)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2 (Crucial for windows on Android/Linux)
find_package(SDL2 REQUIRED)

include(FetchContent)
FetchContent_Declare(
  json
  URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(cg_workspace src/main.cpp)
target_link_libraries(cg_workspace PRIVATE nlohmann_json::nlohmann_json SDL2::SDL2)