#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	N=0;
}


void XOR3::Operate()
{
	if(m_InputPins[0].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned || m_InputPins[2].getStatus()==NotAssigned  )
		m_OutputPin.setStatus(NotAssigned );
	else
	{
	int count=0 ;
	for (int i=0 ; i<3;i++)
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
// Draws 3-input XOR gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Draw3xor2(m_GfxInfo);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[N].setStatus(s);
	IncrementN();
}

//Calculates the Y coordinate of the InPens of Component
int XOR3:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+N*(UI.AND2_Height/4);
	return Y;
}

//Creats a copy of the XOR3 Gate
Component* XOR3:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	XOR3* newgate = new XOR3(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}