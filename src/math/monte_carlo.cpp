#include "math/monte_carlo.h"
#include "math/black_scholes.h"
#include <random>
#include <algorithm>
#include <cmath>
namespace RiskGuard {
MCResult MonteCarlo::simulate(double S, double K, double T, double r, double sigma, double price, bool is_call, int sims){
  MCResult res; std::mt19937 rng(42); std::normal_distribution<double> nd(0,1);
  std::vector<double> pnls; pnls.reserve(sims);
  double drift=(r-0.5*sigma*sigma)*T; double vol=sigma*std::sqrt(T);
  int profit=0, ruin=0; double sum=0;
  for(int i=0;i<sims;i++){
    double ST=S*std::exp(drift+vol*nd(rng));
    double payoff=is_call?std::max(0.0,ST-K):std::max(0.0,K-ST);
    double pnl=payoff-price; pnls.push_back(pnl); sum+=pnl;
    if(pnl>0) profit++; if(pnl<=-price*0.95) ruin++;
  }
  std::sort(pnls.begin(), pnls.end());
  res.prob_profit=(double)profit/sims; res.prob_ruin=(double)ruin/sims; res.expected_pnl=sum/sims;
  res.p5=pnls[(int)(sims*0.05)]; res.p95=pnls[(int)(sims*0.95)];
  return res;
}
}
