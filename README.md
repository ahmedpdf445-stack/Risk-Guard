# 🛡️ RiskGuard — Multi-Agent Risk Engine for 0DTE Options

> **Not a backtester. Not a signal bot. A Risk Operating System that tells you when NOT to trade.**

[![Live Demo](https://img.shields.io/badge/Live_Demo-Streamlit-FF4B4B?style=for-the-badge)](https://risk-guard.streamlit.app)
[![Tests](https://img.shields.io/badge/Tests-42_Passing-brightgreen?style=for-the-badge)](https://github.com/ahmedpdf445-stack/Risk-Guard/actions)
[![Python](https://img.shields.io/badge/Python-3.11-blue?style=for-the-badge)]()
[![License](https://img.shields.io/badge/License-MIT-black?style=for-the-badge)]()

**Live Dashboard:** 👉 https://risk-guard.streamlit.app
**Try it:** Type `SPX` → Get a full Risk Report in < 2 seconds.

---

## 🔥 The Problem We Solve

95% of 0DTE traders don't lose because of bad strategy. They lose because of:
1. **Time Decay Miscalculation:** Thinking they have 45 mins left, when they have 15.
2. **No Hard Stop:** No system that says `RED - EXIT NOW` with authority.
3. **Emotional Holding:** Holding a winning trade until Theta kills it.

RiskGuard fixes all three with 4 autonomous agents.

## 🤖 The Multi-Agent Architecture

| Agent | Job | Kill Condition |
| :--- | :--- | :--- |
| **TimeGuard** | Calculates TRUE time-to-expiry, Theta decay per minute | If Time Left < 20 min → Forces YELLOW |
| **VolGuard** | Monitors IV Crush, VIX Spike, Gamma Exposure | If IV drops > 15% in 5 min → RED |
| **RiskGuard Core** | VaR, Kelly Criterion, Max Loss | If VaR > 2% Account → RED |
| **ExecGuard** | Final Decision: GREEN / YELLOW / RED | **RED = EXIT IMMEDIATELY, NO DISCUSSION** |


