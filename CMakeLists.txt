cmake_minimum_required(VERSION 3.19)
project(MapView)

set(CMAKE_CXX_STANDARD 20)

find_package(CURL CONFIG)

include(FetchContent)
set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 49c14a7445e3870ad2307f626076a05b0c915d6b
)
FetchContent_MakeAvailable(threepp)

add_subdirectory(src)

add_executable(map_view main.cpp)
target_link_libraries(map_view PRIVATE geolib)
