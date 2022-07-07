#include "Switch.h"

Switch::Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut):m_OutputPin(r_FanOut)

{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

Switch:: ~Switch()
{

}

int Switch ::GetInputPinStatus(int n)
{
	return -1;
}

int Switch ::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

//Draws Switch
void Switch ::Draw(Output* pOut)
{
	//Call output class and pass switch drawing info to it.
	pOut->Drawswitch2(m_GfxInfo); // 
}

void Switch ::Operate()
{
	
}

void Switch :: setInputPinStatus(int n, STATUS s) ////TAKE CARE IN SIMULATION MODE
{

}
//Calculates the Y coordinate of the InPens of Component
int Switch :: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+(UI.AND2_Height/2);
	return Y;
}
//Creats a copy of the Switch
Component* Switch:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	Switch* newSwitch = new Switch(rr_GfxInfo,AND2_FANOUT);
	return  newSwitch;
}
//Function that changes the status of the switch depending on the the user choise
void Switch::ChangeStatus(STATUS S)
{
	m_OutputPin.setStatus(S);
}