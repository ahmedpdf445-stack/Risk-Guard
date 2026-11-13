#include "agents/theta_killer.h"
namespace RiskGuard {
Greeks ThetaKiller::analyze(const OptionParams& p){ return BlackScholes::calculate(p); }
}
