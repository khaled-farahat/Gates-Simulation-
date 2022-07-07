#include "NOR3.h"
NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	N=0;
}


void NOR3::Operate()
{
	if(m_InputPins[0].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned )
		m_OutputPin.setStatus(NotAssigned);
	else if (m_InputPins[0].getStatus() == HIGH || m_InputPins[1].getStatus()==HIGH || m_InputPins[1].getStatus()==HIGH)
			m_OutputPin.setStatus (LOW);
	else
		m_OutputPin.setStatus(HIGH);	
	
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Draw3nor2(m_GfxInfo);
}
//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[N].setStatus(s);
	IncrementN();
}


//Calculates the Y coordinate of the InPens of Component
int NOR3:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+N*(UI.AND2_Height/3);
	return Y;
}
//Creats a copy of the NOR3 Gate
Component* NOR3:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	NOR3* newgate = new NOR3(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}