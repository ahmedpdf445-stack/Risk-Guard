#include "core/orchestrator.h"
#include "agents/time_guard.h"
#include "agents/theta_killer.h"
#include "agents/risk_guard.h"
#include "math/volatility.h"
#include "math/risk.h"
#include "math/monte_carlo.h"
#include "math/kelly.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <future>
namespace RiskGuard {
void Orchestrator::run_demo(){
  std::cout << "\n=== RiskGuard - Full System Demo ===\n";
  auto start=std::chrono::high_resolution_clock::now();
  // 3 Agents in parallel
  auto f_time=std::async(std::launch::async, []{ return TimeGuard::analyze("SPXW", 42); });
  auto f_greeks=std::async(std::launch::async, []{
    OptionParams p; p.S=6000; p.K=6000; p.T=42.0/(252*390*60)*60; p.r=0.05; p.sigma=0.15; p.is_call=true;
    return ThetaKiller::analyze(p);
  });
  auto f_mc=std::async(std::launch::async, []{
    return MonteCarlo::simulate(6000,6000,42.0/(252*390*60)*60,0.05,0.15,10.0,true,10000);
  });
  auto t=f_time.get(); auto g=f_greeks.get(); auto mc=f_mc.get();
  std::vector<double> rets={0.01,-0.02,0.005,-0.01,0.015,-0.005,0.02,-0.015};
  double garch_vol=Volatility::garch_forecast(rets);
  std::vector<double> pnls; for(int i=0;i<252;i++) pnls.push_back((i%10-5)*100.0);
  auto risk=Risk::calculate(pnls, 10000);
  double kelly_size=Kelly::position_size(10000, mc.prob_profit, 2.0, 0.5);
  auto dec=RiskGuardAgent::decide(mc.prob_ruin, risk.var95/10000.0, g.theta_per_minute);
  std::cout << "Symbol: " << t.symbol << " | Settlement: " << t.settlement_str << " | Minutes Left: " << t.minutes_left << " | Status: " << t.status << "\n";
  std::cout << "Price: " << g.price << " | Delta: " << g.delta << " | Gamma: " << g.gamma << " | Theta/min: " << g.theta_per_minute << "\n";
  std::cout << "GARCH Vol: " << garch_vol*100 << "% | VaR95: " << risk.var95 << " | ES95: " << risk.es95 << "\n";
  std::cout << "Monte Carlo 10k: Prob Profit=" << mc.prob_profit*100 << "% | Prob Ruin=" << mc.prob_ruin*100 << "% | Exp PnL=" << mc.expected_pnl << "\n";
  std::cout << "Kelly Size: $" << kelly_size << " (from $10000)\n";
  std::cout << ">>> DECISION: " << dec.level << " - " << dec.reason << "\n";
  auto end=std::chrono::high_resolution_clock::now();
  auto us=std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
  std::cout << "Total Latency: " << us << " microseconds\n";
}
}
