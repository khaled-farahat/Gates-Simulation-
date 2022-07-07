#include "Led.h"


Led::Led(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

int Led :: GetOutPinStatus()
{
	return -1 ; 
}


Led::~Led()
{
}

void Led::setInputPinStatus(int n, STATUS s) 
{
	m_InputPins.setStatus(s);
}

int Led ::GetInputPinStatus(int n)	
{
	return m_InputPins.getStatus();
}
//Draws Led
void Led::Draw(Output* pOut)
{
	//Call output class and pass Led drawing info to it.
	if (IsOne())
	    pOut->Drawled(m_GfxInfo);
	else
		pOut->Drawled2(m_GfxInfo);

}
void Led::Operate()
{
	
}
//Calculates the Y coordinate of the InPens of Component
int Led:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+(UI.AND2_Height/2);
	return Y;
}

//Creats a copy of the LED
Component* Led:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	Led* newLed = new Led(rr_GfxInfo);
	return newLed;
}
bool Led:: IsOne()
{
	if(GetInputPinStatus(1)==HIGH)
		return true;
	else
		return false;
}

bool Led:: getAllstatus()
{

if(m_InputPins.getStatus()==NotAssigned)
		return true;
else
	return false;
}