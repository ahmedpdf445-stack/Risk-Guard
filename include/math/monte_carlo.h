#pragma once
#include <vector>
namespace RiskGuard {
struct MCResult { double prob_profit=0, prob_ruin=0, expected_pnl=0, p5=0, p95=0; };
class MonteCarlo {
public:
  static MCResult simulate(double S, double K, double T, double r, double sigma, double option_price, bool is_call, int sims=10000);
};
}
