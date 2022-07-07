#pragma once
#include "Gate.h"
class NAND :
	public Gate
{
public:
	NAND(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NAND gate
	virtual void Draw(Output* pOut);	//Draws 2-input NAND gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	 
	int GetGraphicsInfoInPenY();//Calculates the Y coordinate of the InPens of Component
	Component* GetCopy(const GraphicsInfo &r_GfxInfo); //Creats a copy of the NAND Gate
};

