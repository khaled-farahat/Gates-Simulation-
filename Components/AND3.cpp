#include "AND3.h"

AND3::AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	N=0;
}


void AND3::Operate()
{      if(m_InputPins[0].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned || m_InputPins[2].getStatus()==NotAssigned  )
		m_OutputPin.setStatus(NotAssigned );
     else if(m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==HIGH && m_InputPins[2].getStatus()==HIGH  )
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Draw3and2(m_GfxInfo);
}
//returns status of outputpin
int AND3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[N].setStatus(s);
	IncrementN();
}

//Calculates the Y coordinate of the InPens of Component
int AND3:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+N*(UI.AND2_Height/4);
	return Y;
}
//Creats a copy of the AND3
Component* AND3:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	AND3* newAnd = new AND3(rr_GfxInfo,AND2_FANOUT);
	return newAnd;
}
 