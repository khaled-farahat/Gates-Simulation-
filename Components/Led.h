#pragma once
#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Led :
	public Component
{
private :
	InputPin m_InputPins;
public:
	Led(const GraphicsInfo &r_GfxInfo);
	
	virtual void Draw(Output* pOut);	//Draws LED
	virtual void Operate();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin 

	virtual void setInputPinStatus( int n ,STATUS s);
	~Led();
	int GetGraphicsInfoInPenY();  //Creats a copy of the LED
	Component* GetCopy(const GraphicsInfo &r_GfxInfo);//Calculates the Y coordinate of the InPens of Component
	bool IsOne();
	bool getAllstatus();
};

