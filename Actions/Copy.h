#pragma once
#include "action.h"
#include "..\Components\AND2.h"

class Copy : public Action
{
private:
	int Cx, Cy; //The point Clicked
	
public:
	Copy(ApplicationManager *pApp  );
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	~Copy(void);
};

