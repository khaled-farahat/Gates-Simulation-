#include "NOT.h"


NOT::NOT(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

}


void NOT ::Operate()
{
	if(m_InputPins[0].getStatus()==NotAssigned )
		m_OutputPin.setStatus(NotAssigned);
    else if ( m_InputPins[0].getStatus()== LOW)
        m_OutputPin.setStatus(HIGH);
	else 
		m_OutputPin.setStatus(LOW);
        
}


// Function Draw
// Draws NOT gate
void NOT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Drawnot2(m_GfxInfo);
}

//returns status of outputpin
int NOT::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOT::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
	
}



int NOT:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+(UI.AND2_Height/2);
	return Y;
}

Component* NOT:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	NOT* newgate = new NOT(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}