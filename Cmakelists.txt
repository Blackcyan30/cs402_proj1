cmake_minimum_required(VERSION 3.20)
project(cs401_proj1 LANGUAGES CXX)

# ---- Language / global opts ---------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# No optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# ---- Project libraries / includes --------------------------------------------
# Include directories
include_directories(include)
include_directories(tests)

# ---- Your core library / executables -----------------------------------------
set(SOURCES
    src/talha_khan_proj1.cpp
)

add_executable(sorting_algorithms ${SOURCES})
set_property(TARGET sorting_algorithms PROPERTY OUTPUT_NAME sorting_algorithms.out)
set_property(TARGET sorting_algorithms PROPERTY CXX_STANDARD 20)

# ---- Tests --------------------------------------------------------------------
include(CTest)
include(FetchContent)
if(BUILD_TESTING)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
  enable_testing()
  include(GoogleTest)
  add_subdirectory(tests)
endif()
