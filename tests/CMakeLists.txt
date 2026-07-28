#executable 1: manual test
add_executable(test_entropy_manual test_entropy_manual.cpp)
target_link_libraries(test_entropy_manual PRIVATE url_analysis_lib)
add_test(NAME TestEntropyManual COMMAND test_entropy_manual)

#executable 2: test với gtest
add_executable(test_entropy_gtest test_entropy_gtest.cpp)
target_link_libraries(test_entropy_gtest PRIVATE url_analysis_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_entropy_gtest)