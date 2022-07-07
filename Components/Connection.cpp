#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection:: SetSrcCmpnt(Component*S)
{
	SrcCmpnt=S;
}
void Connection:: SetDstCmpnt(Component*D)
{
	DstCmpnt=D;
}

Component* Connection:: GetSrcCmpnt()
{
	return SrcCmpnt;
}
Component* Connection:: GetDstCmpnt()
{
	return DstCmpnt;
}

bool Connection:: InsideArea(int x, int y)
{     //it OVERRIDE because in the connection y1 is not always less than y2
	if (m_GfxInfo.y1 < m_GfxInfo.y2 && m_GfxInfo.x1 < m_GfxInfo.x2 )
	{
		if (x>=m_GfxInfo.x1&&x<=m_GfxInfo.x2 && y>=m_GfxInfo.y1&& y<=m_GfxInfo.y2)
		return true;
	else
		return false;
	}

	else if (m_GfxInfo.y1 > m_GfxInfo.y2 && m_GfxInfo.x1 < m_GfxInfo.x2 )
	{
		if (x>=m_GfxInfo.x1&&x<=m_GfxInfo.x2 && y<=m_GfxInfo.y1&& y>=m_GfxInfo.y2)
		return true;
	else
		return false;
	}

	else if (m_GfxInfo.y1 > m_GfxInfo.y2 && m_GfxInfo.x1 > m_GfxInfo.x2 )
	{
		if (x<=m_GfxInfo.x1&&x>=m_GfxInfo.x2 && y<=m_GfxInfo.y1&& y>=m_GfxInfo.y2)
		return true;
	else
		return false;
	}
	else 
	{
		if (x<=m_GfxInfo.x1&&x>=m_GfxInfo.x2 && y>=m_GfxInfo.y1&& y<=m_GfxInfo.y2)
		return true;
	else
		return false;
	}
}