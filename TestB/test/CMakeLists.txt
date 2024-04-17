include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571 #release 1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(q1_test q1_test.cpp)
target_link_libraries(q1_test  
  PRIVATE
  q1
  gtest_main
  gmock_main)

add_executable(q2_1_test q2_1_test.cpp)
target_link_libraries(q2_1_test  
  PRIVATE
  q2_1
  gtest_main
  gmock_main)

add_executable(q2_2_test q2_2_test.cpp)
target_link_libraries(q2_2_test  
  PRIVATE
  q2_2
  gtest_main
  gmock_main)

include(GoogleTest)
gtest_discover_tests(q1_test)
gtest_discover_tests(q2_1_test)
gtest_discover_tests(q2_2_test)
