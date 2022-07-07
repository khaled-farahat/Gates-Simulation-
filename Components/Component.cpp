#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

Component::Component()
{}

bool Component:: InsideArea(int x,int y)
{
	if (x>=m_GfxInfo.x1&&x<=m_GfxInfo.x2 && y>=m_GfxInfo.y1&& y<=m_GfxInfo.y2)
		return true;
	else
		return false;
}
Component::~Component()
{}

int Component:: GetGraphicsInfoOutPenY()
{
	return ((m_GfxInfo.y2+m_GfxInfo.y1)/2);
}

int Component:: GetGraphicsInfoOutPenX()
{
	return m_GfxInfo.x2 ;
}

int Component:: GetGraphicsInfoInPenX()
{
	return m_GfxInfo.x1 ;
}

int Component:: GetGraphicsInfoInPenY()
{
	return ((m_GfxInfo.y1+ m_GfxInfo.y2)/2);
}
Component* Component:: GetCopy(const GraphicsInfo &r_GfxInfo)
{
	Component*P;
	return P;
}

 void Component ::setlabel (Output*pOut, Input*pIn ,string t ,string s)
{
		m_Label=pIn->GetSrting(pOut ,t,  s);
}

string Component::getlabel()
{
  return m_Label; 
}
void Component::drawCompLabel(Output*pOut)
{
	pOut->DrawLabel((m_GfxInfo.x1+m_GfxInfo.x2)/2 , m_GfxInfo.y1 , m_Label);
}

void Component:: IncrementN()
{
	N++;
}
void Component::decrementN()
{
		if (N>0)
			N--;
}