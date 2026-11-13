<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:000000,50:00ffcc,100:000000&height=200&section=header&text=RiskGuard&fontSize=70&fontAlignY=40&animation=twinkling&fontColor=ffffff&desc=Multi-Agent%20Mathematical%20Risk%20Engine%20for%200DTE&descAlignY=60&descSize=20" width="100%" />
</div>

<div align="center">
  <p><b>Not a backtester. Not a signal bot. A Risk Operating System that tells you when NOT to trade.</b></p>

  <!-- Badges -->
  <a href="https://risk-guard.streamlit.app"><img src="https://img.shields.io/badge/Live_Demo-Streamlit-FF4B4B?style=for-the-badge&logo=streamlit&logoColor=white" alt="Live Demo" /></a>
  <a href="https://github.com/ahmedpdf445-stack/Risk-Guard/actions"><img src="https://img.shields.io/badge/Tests-42_Passing-brightgreen?style=for-the-badge&logo=pytest&logoColor=white" alt="Tests" /></a>
  <img src="https://img.shields.io/badge/Python-3.11-blue?style=for-the-badge&logo=python&logoColor=white" />
  <img src="https://img.shields.io/badge/License-MIT-black?style=for-the-badge" />
</div>

<br>

> **"95% of 0DTE traders don't lose because of bad strategy. They lose because of bad math and human emotion. RiskGuard is the mathematical firewall."**

---

## 🎯 The Problem (Why 0DTE Traders Get Wiped Out)

0DTE (Zero Days to Expiration) options are the most dangerous financial instruments. Millions of traders lose their capital daily due to 3 mathematical flaws:

1. **The Time-Decay Miscalculation:** Traders think they have 45 minutes left, but due to exchange settlement rules (SPXW vs NDXP), they actually have 15 minutes. Theta decays 10x faster in the final hour.
2. **The Gamma Explosion:** As the option approaches expiry, Gamma becomes extreme. A tiny price move causes massive Delta shifts, wiping out the account.
3. **No Hard-Stop Risk Management:** Traders use 50% of their account on a single trade without calculating VaR (Value at Risk) or Kelly Criterion.

**RiskGuard solves these with mathematics, not emotions.**

---

## 🏗️ The Architecture (Multi-Agent System)

RiskGuard is not a monolithic script. It is a **Multi-Agent Orchestration System** where 4 specialized agents run concurrently, communicating via asynchronous message passing to calculate risk in **< 50ms**.

```mermaid
graph TD
    A[Market Data Feed] -->|Real-time Tick| B(TimeGuard: Settlement Logic)
    A -->|Real-time Tick| C(VolGuard: GARCH & IV Surface)
    A -->|Real-time Tick| D(RiskGuard Core: VaR & Kelly)
    
    B -->|Time Left & Theta| E{Orchestrator}
    C -->|Volatility Regime| E
    D -->|Risk Exposure| E
    
    E -->|Decision Matrix| F[ExecGuard]
    F -->|GREEN / YELLOW / RED| G[User Interface]
    
    style A fill:#0d1117,stroke:#00ffcc,stroke-width:2px,color:#fff
    style E fill:#00ffcc,stroke:#fff,stroke-width:2px,color:#000
    style F fill:#0d1117,stroke:#00ffcc,stroke-width:2px,color:#fff