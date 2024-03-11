cmake_minimum_required(VERSION 3.24)
project(container CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(container
        src/backend/backend_map_Node.h
        src/backend/backend_multiset_Tree.h
        src/backend/backend_set_Node.h
        src/backend/backend_set_Tree.h
        src/backend/node.h
        src/containers/list.h
        src/containers/array.h
        src/containers/map.h
        src/containers/queue.h
        src/containers/multiset.h
        src/containers/set.h
        src/containers/stack.h
        src/containers/vector.h
        main.cc
        src/containers.h
        src/backend/backend_map_Tree.h
        src/backend/raw_memory_dynamic.h
        )

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(GTest COMPONENTS Gtest)
add_executable(test_container_array
        src/tests/test_array.cc
        src/tests/test_class.h
        )
add_executable(test_container_list
        src/tests/test_list.cc
        src/tests/test_class.h
        )
add_executable(test_container_queue
        src/tests/test_queue.cc
        src/tests/test_class.h
        )
add_executable(test_container_stack
        src/tests/test_stack.cc
        src/tests/test_class.h
        )
add_executable(test_container_vector
        src/tests/test_vector.cc
        src/tests/test_class.h
        )
add_executable(test_container_map
        src/tests/test_map.cc
        )
add_executable(test_container_set
        src/tests/test_set.cc
        )
add_executable(test_container_multiset
        src/tests/test_multiset.cc
        )

target_link_libraries(test_container_array GTest::GTest)
target_link_libraries(test_container_list GTest::GTest)
target_link_libraries(test_container_map GTest::GTest)
target_link_libraries(test_container_multiset GTest::GTest)
target_link_libraries(test_container_queue GTest::GTest)
target_link_libraries(test_container_set GTest::GTest)
target_link_libraries(test_container_stack GTest::GTest)
target_link_libraries(test_container_vector GTest::GTest)

enable_testing()

gtest_discover_tests(test_container_array)
gtest_discover_tests(test_container_list)
gtest_discover_tests(test_container_map)
gtest_discover_tests(test_container_multiset)
gtest_discover_tests(test_container_queue)
gtest_discover_tests(test_container_set)
gtest_discover_tests(test_container_stack)
gtest_discover_tests(test_container_vector)
