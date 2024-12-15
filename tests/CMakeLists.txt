enable_testing()

include(GoogleTest)

add_executable(teste tests.cpp ../src/project.cpp)

target_link_libraries(teste gtest gtest_main)

gtest_discover_tests(teste)