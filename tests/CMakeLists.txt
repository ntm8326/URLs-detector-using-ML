add_executable(test_entropy test_entropy.cpp)
target_link_libraries(test_entropy PRIVATE url_analysis_lib)

add_test(NAME TestEntropy COMMAND test_entropy)