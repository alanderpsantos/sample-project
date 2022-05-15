find_package(GTest REQUIRED)

add_executable(mocktest test0.h.cpp test1.h.cpp)

target_include_directories(
    mocktest
PRIVATE
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
    ../lib
)

target_link_libraries(
    mocktest
PRIVATE 
    SampleLibrary gtest gtest_main gmock gmock_main
)

add_test(uni-mocktest mocktest)