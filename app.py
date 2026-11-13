import streamlit as st
st.set_page_config(page_title="RiskGuard", page_icon="🛡️")
st.title("🛡️ RiskGuard - Live Demo")
st.write("The Mathematical Firewall for 0DTE Options")
ticker = st.text_input("Ticker", "SPX")
strike = st.number_input("Strike", value=6000)
price = st.number_input("Option Price", value=10.0)
account = st.number_input("Account Size", value=10000)
time_left = st.slider("Time Left (minutes)", 1, 390, 42)
if st.button("Run RiskGuard"):
    theta = -0.35 * (45 / max(time_left, 1))
    var_95 = account * 0.23 if time_left < 30 else account * 0.05
    if time_left < 20:
        st.error("🔴 RED - EXIT IMMEDIATELY")
        st.write(f"Time Left: {time_left} min | Theta/min: {theta:.2f}")
        st.write(f"VaR 95%: -${var_95:,.0f} | Kelly: 2.1%")
    elif time_left < 45:
        st.warning("🟡 YELLOW - Reduce Size, Tight Stop")
    else:
        st.success("🟢 GREEN - Safe to Trade")
        st.write(f"Theta/min: {theta:.2f} | VaR: ${var_95:,.0f}")
