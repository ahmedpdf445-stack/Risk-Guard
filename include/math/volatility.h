#pragma once
#include <vector>
namespace RiskGuard {
class Volatility {
public:
  static double historical_vol(const std::vector<double>& returns);
  static double garch_forecast(const std::vector<double>& returns);
};
}
