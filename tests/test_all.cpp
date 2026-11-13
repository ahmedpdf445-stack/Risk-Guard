#include <iostream>
#include <cassert>
#include <cmath>
#include "math/black_scholes.h"
#include "math/volatility.h"
#include "math/risk.h"
#include "math/monte_carlo.h"
#include "math/kelly.h"
#include "agents/time_guard.h"
#include "agents/risk_guard.h"
int main(){
  using namespace RiskGuard;
  std::cout << "Running All Tests...\n";
  // 1. Black-Scholes
  OptionParams p{6000,6000,1.0/(252*390),0.05,0.15,true};
  auto g=BlackScholes::calculate(p); assert(g.delta>0.4 && g.delta<0.6); assert(g.gamma>0); assert(g.theta_per_minute<0); std::cout << "[PASS] Black-Scholes Greeks\n";
  // 2. Volatility
  std::vector<double> r={0.01,-0.02,0.005,0.01,-0.01,0.02}; double v=Volatility::garch_forecast(r); assert(v>0.03 && v<1.0); std::cout << "[PASS] GARCH Volatility\n";
  // 3. Risk
  std::vector<double> pnl; for(int i=0;i<100;i++) pnl.push_back(i-50); auto rm=Risk::calculate(pnl,10000); assert(rm.var95>0); std::cout << "[PASS] VaR / ES\n";
  // 4. Monte Carlo
  auto mc=MonteCarlo::simulate(6000,6000,0.001,0.05,0.15,10,true,1000); assert(mc.prob_ruin>=0 && mc.prob_ruin<=1); std::cout << "[PASS] Monte Carlo 1000 sims\n";
  // 5. Kelly
  assert(Kelly::fraction(0.6,2.0)>0); std::cout << "[PASS] Kelly\n";
  // 6. TimeGuard
  auto t=TimeGuard::analyze("SPXW",10); assert(t.status=="RED"); auto t2=TimeGuard::analyze("SPXW",120); assert(t2.status=="GREEN"); std::cout << "[PASS] TimeGuard\n";
  // 7. RiskGuard
  auto d=RiskGuardAgent::decide(0.8,0.3,-2); assert(d.level=="RED"); std::cout << "[PASS] RiskGuard Decision\n";
  std::cout << "ALL TESTS PASSED - 7/7\n"; return 0;
}
