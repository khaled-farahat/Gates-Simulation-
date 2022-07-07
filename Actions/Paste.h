#pragma once
#include "action.h"
#include "..\Components\AND2.h"

class Paste :
	public Action
{
private:
	int Cx, Cy; //The point Clicked to be the new center of the component

public:
	Paste(ApplicationManager *pApp );
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

	~Paste(void);
};

