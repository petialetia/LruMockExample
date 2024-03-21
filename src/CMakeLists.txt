find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(LruExample LruExample.cpp)
target_link_libraries(LruExample ${Boost_LIBRARIES})
