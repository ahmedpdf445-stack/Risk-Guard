cmake_minimum_required(VERSION 3.20)
project(RiskGuard VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")
include_directories(include)
add_library(riskguard_lib
  src/math/black_scholes.cpp
  src/math/volatility.cpp
  src/math/risk.cpp
  src/math/monte_carlo.cpp
  src/math/kelly.cpp
  src/agents/time_guard.cpp
  src/agents/theta_killer.cpp
  src/agents/risk_guard.cpp
  src/core/orchestrator.cpp
)
add_executable(riskguard src/main.cpp)
target_link_libraries(riskguard riskguard_lib)
add_executable(test_all tests/test_all.cpp)
target_link_libraries(test_all riskguard_lib)
