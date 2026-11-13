#pragma once
#include <string>
namespace RiskGuard {
struct Decision { std::string level; std::string reason; double risk_score=0; };
class RiskGuardAgent {
public:
  static Decision decide(double prob_ruin, double var_ratio, double theta_per_min);
};
}
