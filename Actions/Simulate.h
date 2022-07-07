#pragma once
#include "action.h"

//A Class that Switch To SIMULATION MODE

class Simulate :
	public Action
{

public:
	Simulate(ApplicationManager *pApp  );
	~Simulate(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

