#pragma once
#include "action.h"
class Design :
	public Action
{
public:
	Design(ApplicationManager *pApp);
	virtual ~Design(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

