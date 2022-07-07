#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	N=0;
}


void XOR2::Operate()
{
	//caclulate the output status as the XORing of the two input pins
	if(m_InputPins[0].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned )
		m_OutputPin.setStatus(NotAssigned);
	else
	{
	int count=0 ;
	for(int i=0 ; i< 2; i++)
	{
		if (m_InputPins[i].getStatus()==HIGH)
			count +=1;
	}
	if (count %2==0)
		m_OutputPin.setStatus(LOW);
	else 
		m_OutputPin.setStatus(HIGH);
	}
	
}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[N].setStatus(s);
	IncrementN();
}


//Calculates the Y coordinate of the InPens of Component
int XOR2:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+N*(UI.AND2_Height/3);
	return Y;
}
//Creats a copy of the XOR Gate
Component* XOR2:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	XOR2* newgate = new XOR2(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}