#pragma once
namespace RiskGuard {
class Kelly {
public:
  static double fraction(double p_win, double win_loss_ratio);
  static double position_size(double account, double p_win, double win_loss_ratio, double fractional=0.5);
};
}
