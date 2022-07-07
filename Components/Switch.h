#pragma once
#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
class Switch :
	public Component
{
private :
	OutputPin m_OutputPin;
public:
	Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	
	virtual void Draw(Output* pOut);	//Draws switch

	virtual int GetOutPinStatus();	//returns status of outputpin 
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);
	~Switch();
	int GetGraphicsInfoInPenY();//Calculates the Y coordinate of the InPens of Component
	Component* GetCopy(const GraphicsInfo &r_GfxInfo); //Creats a copy of the Switch
	void ChangeStatus(STATUS s); //Function that changes the status of the switch depending on the the user choise
};

