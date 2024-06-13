cmake_minimum_required(VERSION 3.28)
project(secwe_client_c)

set(CMAKE_CXX_STANDARD 17)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
include_directories(/opt/homebrew/Cellar/nlohmann-json/3.11.3/include)


add_executable(secwe_client_c main.cpp
        secwe_client.cpp
        secwe_client.h
        prediction_info.cpp
        prediction_info.h)

target_link_libraries(secwe_client_c ${CURL_LIBRARIES})