#include "NOR2.h"



NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	N=0;
}


void NOR2::Operate()
{
	
	if(m_InputPins[0].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned )
		m_OutputPin.setStatus(NotAssigned);
	else if (m_InputPins[0].getStatus() == HIGH || m_InputPins[1].getStatus()==HIGH)
			m_OutputPin.setStatus (LOW);
	else
		m_OutputPin.setStatus(HIGH);	
}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[N].setStatus(s);
	IncrementN();
}


//Calculates the Y coordinate of the InPens of Component
int NOR2:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+N*(UI.AND2_Height/3);
	return Y;
}
//Creats a copy of the NOR2 Gate
Component* NOR2:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	NOR2* newgate = new NOR2(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}