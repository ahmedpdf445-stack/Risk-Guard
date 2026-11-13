#include "math/kelly.h"
#include <algorithm>
namespace RiskGuard {
double Kelly::fraction(double p, double b){
  if(b<=0) return 0; double q=1-p; double f=(p*b-q)/b; return std::clamp(f,0.0,0.25);
}
double Kelly::position_size(double account, double p, double b, double frac){
  return account * fraction(p,b) * frac;
}
}
