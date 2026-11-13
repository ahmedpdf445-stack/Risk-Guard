#pragma once
#include "math/black_scholes.h"
namespace RiskGuard {
class ThetaKiller {
public:
  static Greeks analyze(const OptionParams& p);
};
}
