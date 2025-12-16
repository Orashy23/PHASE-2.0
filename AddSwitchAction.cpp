#include "AddSwitchAction.h"
#include "ApplicationManager.h"
#include "CSwitch.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

AddSwitchAction::AddSwitchAction(ApplicationManager* pApp) : Action(pApp) {}

void AddSwitchAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    
	do {
    pOut->PrintMsg("Switch: Click to add a new Switch.");
    pIn->GetPointClicked(Cx, Cy);
  
} while (Cy<(UI.ToolBarHeight + UI.SWITCH_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.SWITCH_Width / 2));
    pOut->ClearStatusBar();
}

void AddSwitchAction::Execute()
{

    ReadActionParameters();

    int Len = UI.SWITCH_Width;
    int Wdth = UI.SWITCH_Height;
    GraphicsInfo GInfo;

    GInfo.x1 = Cx - Len / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.y2 = Cy + Wdth / 2;
    CSwitch* pSw = new CSwitch(GInfo, SWITCH_FANOUT);
    pManager->AddComponent(pSw);
    
}