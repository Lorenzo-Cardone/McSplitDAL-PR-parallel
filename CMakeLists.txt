# McSplit_DAL

cmake_minimum_required(VERSION 3.16.0)
project(mcs_dal_circuit VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_executable(mcs_dal_circuit mcsplitDAL+PR-iter.cpp graph.cpp mcs.cpp reward.cpp heuristics/SortHeuristic.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(mcs_dal_circuit Threads::Threads)
target_link_libraries(mcs_dal_circuit OpenMP::OpenMP_CXX)