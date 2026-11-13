#pragma once
#include <string>
namespace RiskGuard {
struct TimeInfo { std::string symbol; double T_years=0; int minutes_left=0; std::string status; std::string settlement_str; };
class TimeGuard {
public:
  static TimeInfo analyze(const std::string& symbol, int minutes_left);
};
}
