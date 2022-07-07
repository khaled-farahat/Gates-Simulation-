#pragma once
#include "action.h"
#include "..\Components\Switch.h"

//A Class that makes the Switch Status Is LOW

class ZeroSwitch :public Action
{
	int Cx, Cy; //The point Clicked
public:
	ZeroSwitch(ApplicationManager *pApp);
	~ZeroSwitch(void);
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};

