#ifndef CSWITCH_H
#define CSWITCH_H

#include "Components/Component.h"
#include "Components/Pin.h"
#include "Components/OutputPin.h"
#include "ApplicationManager.h"

class CSwitch : public Component
{
private:
    OutputPin m_OutputPin;
    STATUS m_SwitchStatus;
public:
    CSwitch(const GraphicsInfo& r_GfxInfo, int r_FanOut = 10);
    virtual ~CSwitch() {}

    virtual void Operate();
    virtual void Draw(Output* pOut);
    virtual int GetOutPinStatus();
    virtual int GetInputPinStatus(int n);
    virtual void setInputPinStatus(int n, STATUS s);

    // Expose the output pin so other code (AddConnection etc.) can get it
	virtual OutputPin* GetOutputPin() override { return &m_OutputPin; }

    void SetSwitchStatus(STATUS s) { m_SwitchStatus = s; }
};

#endif