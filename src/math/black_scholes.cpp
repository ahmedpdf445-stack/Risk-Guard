#include "math/black_scholes.h"
#include <cmath>
namespace RiskGuard {
double BlackScholes::norm_cdf(double x){ return 0.5 * std::erfc(-x * 0.7071067811865475); }
double BlackScholes::norm_pdf(double x){ return 0.3989422804014327 * std::exp(-0.5*x*x); }
Greeks BlackScholes::calculate(const OptionParams& p){
  Greeks g; if(p.T<=0||p.sigma<=0) return g;
  double sqrtT=std::sqrt(p.T);
  double d1=(std::log(p.S/p.K)+(p.r+0.5*p.sigma*p.sigma)*p.T)/(p.sigma*sqrtT);
  double d2=d1-p.sigma*sqrtT;
  double Nd1=norm_cdf(d1), Nd2=norm_cdf(d2), Npd1=norm_pdf(d1);
  double disc=std::exp(-p.r*p.T);
  if(p.is_call){ g.price=p.S*Nd1-p.K*disc*Nd2; g.delta=Nd1; g.theta_per_day=(-p.S*Npd1*p.sigma/(2*sqrtT)-p.r*p.K*disc*Nd2); g.rho=p.K*p.T*disc*Nd2; }
  else { g.price=p.K*disc*norm_cdf(-d2)-p.S*norm_cdf(-d1); g.delta=Nd1-1.0; g.theta_per_day=(-p.S*Npd1*p.sigma/(2*sqrtT)+p.r*p.K*disc*norm_cdf(-d2)); g.rho=-p.K*p.T*disc*norm_cdf(-d2); }
  g.gamma=Npd1/(p.S*p.sigma*sqrtT); g.vega=p.S*sqrtT*Npd1; g.theta_per_minute=g.theta_per_day/390.0;
  return g;
}
}
