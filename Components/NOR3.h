#include "Gate.h"
#pragma once
class NOR3 :public Gate
{
public:
	NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOR gate
	virtual void Draw(Output* pOut);	//Draws 3-input NOR gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status
	 
	int GetGraphicsInfoInPenY();//Calculates the Y coordinate of the InPens of Component
	Component* GetCopy(const GraphicsInfo &r_GfxInfo);//Creats a copy of the NOR3 Gate
};

