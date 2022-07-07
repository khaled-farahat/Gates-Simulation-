#include "BUFFER.h"



BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	
}


void BUFFER::Operate()
{
	if(m_InputPins[0].getStatus()==NotAssigned )
		m_OutputPin.setStatus(NotAssigned);
	else if (m_InputPins->getStatus() == LOW)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin = HIGH;
	

}


// Function Draw
// Draws BUFFER gate
void BUFFER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Drawbuffer2(m_GfxInfo);
}

//returns status of outputpin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
	
}


//Calculates the Y coordinate of the InPens of Component
int BUFFER:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+(UI.AND2_Height/2);
	return Y;
}
//Creats a copy of the BUFFER
Component* BUFFER:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	BUFFER* newgate = new BUFFER(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}