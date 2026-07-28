# Tìm tất cả file .cpp trong src_cpp/src/
file(GLOB_RECURSE CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Tạo static library
add_library(url_analysis_lib STATIC ${CPP_SOURCES})

# Chỉ cho CLion biết include path → để resolve #include
target_include_directories(url_analysis_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)