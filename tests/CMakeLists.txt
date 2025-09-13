add_executable(unit_tests
  unit_tests.cpp
  testing.cpp
)

target_link_libraries(unit_tests PRIVATE
  gtest_main
)

set_property(TARGET unit_tests PROPERTY OUTPUT_NAME unit_tests.out)
set_property(TARGET unit_tests PROPERTY CXX_STANDARD 20)

gtest_discover_tests(unit_tests
  EXTRA_ARGS --gtest_color=yes
  DISCOVERY_TIMEOUT 10
)