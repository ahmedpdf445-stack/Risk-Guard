#pragma once
#include <vector>
namespace RiskGuard {
struct RiskMetrics { double var95=0, var99=0, es95=0, max_drawdown=0; };
class Risk {
public:
  static RiskMetrics calculate(const std::vector<double>& pnl, double portfolio);
  static double parametric_var(double portfolio, double mu, double sigma, double z);
};
}
