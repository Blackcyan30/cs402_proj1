add_executable(unit_tests
  unit_tests.cpp
  testing.cpp
)

target_link_libraries(unit_tests PRIVATE
  gtest_main
  sorting_lib
)

set_property(TARGET unit_tests PROPERTY OUTPUT_NAME unit_tests.out)
set_property(TARGET unit_tests PROPERTY CXX_STANDARD 20)

# gtest_discover_tests(unit_tests
#   EXTRA_ARGS --gtest_color=yes --gtest_print_time=0
#   DISCOVERY_TIMEOUT 10
# )

add_test(NAME unit_tests COMMAND unit_tests --gtest_color=yes --gtest_print_time=1)