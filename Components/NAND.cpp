#include "NAND.h"


NAND::NAND(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	N=0;
}


void NAND ::Operate()
{
	    if(m_InputPins[0].getStatus()==NotAssigned || m_InputPins[1].getStatus()==NotAssigned )
		m_OutputPin.setStatus(NotAssigned);
		else if(m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==HIGH  )
			m_OutputPin.setStatus(LOW);
		else
			m_OutputPin.setStatus(HIGH);


}


// Function Draw
// Draws 2-input NAND gate
void NAND::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo,false);
}

//returns status of outputpin
int NAND::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[N].setStatus(s);
	IncrementN();
}


//Calculates the Y coordinate of the InPens of Component
int NAND:: GetGraphicsInfoInPenY()
{
	int Y = m_GfxInfo.y1+N*(UI.AND2_Height/3);
	return Y;
}
 //Creats a copy of the NAND Gate
Component* NAND:: GetCopy(const GraphicsInfo &rr_GfxInfo)
{
	NAND* newgate = new NAND(rr_GfxInfo,AND2_FANOUT);
	return newgate;
}