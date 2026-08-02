#executable 1: manual test (chỉ build, không đăng ký vào ctest)
add_executable(test_entropy_manual test_entropy_manual.cpp)
add_executable(test_specialchar_manual test_spcialchar_manual.cpp)
target_link_libraries(test_entropy_manual PRIVATE url_analysis_lib)
target_link_libraries(test_specialchar_manual PRIVATE url_analysis_lib)

#executable 2: test với gtest
add_executable(test_entropy_gtest test_entropy_gtest.cpp)
add_executable(test_specialchar_gtest test_specialchar_gtest.cpp)
target_link_libraries(test_entropy_gtest PRIVATE url_analysis_lib GTest::gtest_main)
target_link_libraries(test_specialchar_gtest PRIVATE url_analysis_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_entropy_gtest)
gtest_discover_tests(test_specialchar_gtest)