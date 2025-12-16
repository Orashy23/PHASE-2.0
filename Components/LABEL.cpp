#include "LABEL.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

LABEL::LABEL(const GraphicsInfo& r_GfxInfo, string label) : Component(r_GfxInfo)
{
	SetLabel(label);
	m_GfxInfo = r_GfxInfo;
	m_Label = label;
}
void LABEL::Draw(Output* pOut) {
	// Draw label at absolute coordinates using new Output helper
	pOut->DrawLabel(m_GfxInfo, m_Label);
}
void LABEL::Operate()
{
	// LABEL does not perform any logic operation
}