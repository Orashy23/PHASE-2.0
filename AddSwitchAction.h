#pragma once
#ifndef ADD_SWITCH_ACTION_H
#define ADD_SWITCH_ACTION_H
#include "Actions/Action.h"
#include "Defs.h"
#include "Actions/Select.h"
class AddSwitchAction : public Action
{
private:
    GraphicsInfo GfxInfo;
    int Cx, Cy;	//Center point of the gate
    int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
    AddSwitchAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif