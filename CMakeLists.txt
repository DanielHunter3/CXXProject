cmake_minimum_required(VERSION 3.10)

project(MyProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/src/header)
include_directories(${PROJECT_SOURCE_DIR}/utils/header)

# Используем GLOB_RECURSE для поиска всех .cpp файлов
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE UTILS "utils/*.cpp")

add_executable(MyExecutable "src/main.cpp" ${SOURCES} ${UTILS})

# Подключаем необходимые библиотеки (если есть)
#target_link_libraries(MyExecutable kernel32 user32 gdi32)
