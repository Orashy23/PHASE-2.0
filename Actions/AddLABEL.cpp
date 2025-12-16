#include"AddLABEL.h"
#include "..\Components\LABEL.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddLABEL::AddLABEL(ApplicationManager* pApp) : Action(pApp) {}


 void AddLABEL::Execute() {
     Output* pOut = pManager->GetOutput();
     Input* pIn = pManager->GetInput();
     int x, y;
     pOut->PrintMsg("Click anywhere ta add a label ");
     pIn->GetPointClicked(x, y);
	 string label = pIn->GetSrting(pOut);
     if (label != "") {
         Component* comp = pManager->GetComponentAt(x, y);
         if (comp) {
             //comp->SetLabel(label);
             pOut->PrintMsg("Label added: " + label);
             //pOut->PrintMsg(label, x, (y+30));
			 GraphicsInfo GInfo;
			 GInfo.x1 = x;
			 GInfo.y1 = y + 30;

             LABEL* pA = new LABEL(GInfo, label);
             pManager->AddComponent(pA);

         }
         else {
             pOut->PrintMsg("No component at the clicked position.");
         }
     }
     else {
         pOut->PrintMsg("Labeling cancelled.");
	 }
}