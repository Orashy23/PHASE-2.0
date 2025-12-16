#include "CSwitch.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"

CSwitch::CSwitch(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Component(r_GfxInfo), m_OutputPin(r_FanOut)
{
    m_GfxInfo = r_GfxInfo;
    m_SwitchStatus = LOW; // default, change as needed
    m_OutputPin.setStatus(m_SwitchStatus);
    
}

void CSwitch::Operate()
{
    if (IsSelected()) {
        if (m_SwitchStatus == HIGH) {
            m_SwitchStatus = LOW;
        }
        else {
            m_SwitchStatus = HIGH;
        }
        m_OutputPin.setStatus(m_SwitchStatus);
    }
    else {
        m_OutputPin.setStatus(m_SwitchStatus);
    }
   
}

void CSwitch::Draw(Output* pOut)
{
   

    bool z=false;
    if (m_OutputPin.getStatus() == LOW) {
		z = false;
    }
	else if (m_OutputPin.getStatus() == HIGH)
	{
		z = true;
	}

        pOut->DrawSWITCHS(m_GfxInfo, z);
 
   
}

int CSwitch::GetOutPinStatus()
{
    return m_OutputPin.getStatus();
}

int CSwitch::GetInputPinStatus(int n)
{
    return -1; // No input pins
}

void CSwitch::setInputPinStatus(int n, STATUS s)
{
    return; // Not used
}
