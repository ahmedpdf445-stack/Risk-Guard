#include "agents/risk_guard.h"
namespace RiskGuard {
Decision RiskGuardAgent::decide(double prob_ruin, double var_ratio, double theta){
  Decision d;
  d.risk_score = prob_ruin*0.6 + var_ratio*0.3 + (theta< -1 ? 0.2 : 0);
  if(prob_ruin>0.6 || var_ratio>0.20){ d.level="RED"; d.reason="Prob Ruin >60% or VaR >20% - EXIT NOW"; }
  else if(prob_ruin>0.35 || var_ratio>0.10){ d.level="YELLOW"; d.reason="High Risk - Prepare Exit"; }
  else { d.level="GREEN"; d.reason="Risk Acceptable - Continue"; }
  return d;
}
}
