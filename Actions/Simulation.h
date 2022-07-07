#pragma once
#include "action.h"
class Simulation :
	public Action
{
public:
	Simulation(ApplicationManager *pApp);
	virtual ~Simulation(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
