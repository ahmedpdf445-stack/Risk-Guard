#include "math/volatility.h"
#include <cmath>
#include <numeric>
namespace RiskGuard {
double Volatility::historical_vol(const std::vector<double>& r){
  if(r.size()<2) return 0.15;
  double m=std::accumulate(r.begin(),r.end(),0.0)/r.size();
  double v=0; for(double x:r) v+=(x-m)*(x-m);
  v/=(r.size()-1); return std::sqrt(v*252.0);
}
double Volatility::garch_forecast(const std::vector<double>& r){
  // GARCH(1,1): sigma^2 = omega + alpha*e^2 + beta*sigma^2
  if(r.size()<2) return 0.15;
  double omega=0.000001, alpha=0.08, beta=0.90;
  double var=0.0004;
  for(size_t i=1;i<r.size();i++){ double e=r[i-1]; var=omega+alpha*e*e+beta*var; }
  double vol=std::sqrt(var*252.0);
  if(vol<0.05) vol=0.05; if(vol>1.0) vol=1.0; return vol;
}
}
