#pragma once
#include "Action.h"


class AddLABEL : public Action
{ 
public:
    AddLABEL(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};