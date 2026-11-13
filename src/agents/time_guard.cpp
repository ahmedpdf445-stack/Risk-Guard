#include "agents/time_guard.h"
namespace RiskGuard {
TimeInfo TimeGuard::analyze(const std::string& sym, int mins){
  TimeInfo t; t.symbol=sym; t.minutes_left=mins;
  t.T_years = mins / (252.0*390.0*60.0) * 60.0; // تحويل دقايق لسنين
  if(sym=="NDXP"||sym=="NQX") t.settlement_str="16:00 ET (New York)";
  else t.settlement_str="16:00 ET (Chicago -> 15:00 CT)";
  if(mins<15) t.status="RED";
  else if(mins<60) t.status="YELLOW";
  else t.status="GREEN";
  return t;
}
}
