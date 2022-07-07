#ifndef _XOR3_H
#define _XOR3_H



#include "Gate.h"

class XOR3:public Gate
{
public:
	XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(Output* pOut);	//Draws 3-input XOR gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	
	int GetGraphicsInfoInPenY();//Calculates the Y coordinate of the InPens of Component
	Component* GetCopy(const GraphicsInfo &rr_GfxInfo);//Creats a copy of the XOR3 Gate
};
#endif