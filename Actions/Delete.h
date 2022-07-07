#pragma once
#include "Action.h"
#include "..\Components/Component.h"
class Delete : public Action
{
private:
	int Cx, Cy; //The point Clicked
	
public:
	Delete(void);
	~Delete(void);
	
		
public:
	Delete(ApplicationManager *pApp );
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};

