
#include "CLED.h"

CLED::CLED(const GraphicsInfo& r_GfxInfo) : Component(r_GfxInfo)
{
    m_IsOn = false;
    // Associate and number the input pin so connection logic can use it
    m_InputPin.setComponent(this);
    m_InputPin.setInputNumber(1);
}

void CLED::Operate()
{
    STATUS s = m_InputPin.getStatus();
    if (s == HIGH) {
        m_IsOn = true;
    }
}

void CLED::Draw(Output* pOut)
{
    pOut->DrawLED(m_GfxInfo, m_IsOn);
}

int CLED::GetOutPinStatus()
{
    return -1; // LED is a sink
}

int CLED::GetInputPinStatus(int n)
{
    if (n == 1) return m_InputPin.getStatus();
    return -1;
}

void CLED::setInputPinStatus(int n, STATUS s)
{
    if (n == 1) m_InputPin.setStatus(s);
}
InputPin* CLED::GetInputPin(int n)
{
    if (n == 1) return &m_InputPin;
    return nullptr;
}

InputPin* CLED::GetFreeInputPin()
{
    return m_InputPin.isConnected() ? nullptr : &m_InputPin;
}