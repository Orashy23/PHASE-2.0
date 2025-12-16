#pragma once
#ifndef LABEL_H
#define LABEL_H
#include "Component.h"
#include "..\ApplicationManager.h"
class LABEL : public Component
{
	string m_Label;
public:
    LABEL(const GraphicsInfo& r_GfxInfo, string label);
    virtual ~LABEL() {}
    virtual void Draw(Output* pOut);
    virtual void Operate() override; // <-- Add this line to implement pure virtual
    virtual int GetOutPinStatus() override { return -1; }
    virtual int GetInputPinStatus(int n) override { return -1; }
    virtual void setInputPinStatus(int n, STATUS s) override {}
};
#endif


