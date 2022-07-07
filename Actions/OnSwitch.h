#pragma once
#include "action.h"
#include "..\Components\Switch.h"

//A Class that makes the Switch Status Is HIGH

class OnSwitch : public Action
{
	private:
	int Cx, Cy; //The point Clicked 
public:
	OnSwitch(ApplicationManager *pApp);
	~OnSwitch(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

