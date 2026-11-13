#pragma once
namespace RiskGuard {
struct Greeks { double delta=0, gamma=0, theta_per_day=0, theta_per_minute=0, vega=0, rho=0, price=0; };
struct OptionParams { double S=0, K=0, T=0, r=0.05, sigma=0.15; bool is_call=true; };
class BlackScholes {
public:
  static Greeks calculate(const OptionParams& p);
  static double norm_cdf(double x);
  static double norm_pdf(double x);
};
}
