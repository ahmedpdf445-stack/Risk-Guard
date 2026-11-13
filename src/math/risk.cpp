#include "math/risk.h"
#include <algorithm>
#include <cmath>
namespace RiskGuard {
RiskMetrics Risk::calculate(const std::vector<double>& pnl, double portfolio){
  RiskMetrics m; if(pnl.empty()) return m;
  auto s=pnl; std::sort(s.begin(), s.end());
  int i95=(int)(s.size()*0.05); int i99=(int)(s.size()*0.01);
  if(i95<0) i95=0; if(i99<0) i99=0;
  m.var95=-s[i95]; m.var99=-s[i99];
  double sum=0; int cnt=0; for(int i=0;i<=i95;i++){ sum+=s[i]; cnt++; }
  m.es95=cnt>0?-sum/cnt: m.var95;
  double peak=0, dd=0, cur=0; for(double x:pnl){ cur+=x; if(cur>peak) peak=cur; double d=peak-cur; if(d>dd) dd=d; }
  m.max_drawdown=dd; (void)portfolio; return m;
}
double Risk::parametric_var(double portfolio, double mu, double sigma, double z){ return portfolio*(mu - z*sigma); }
}
