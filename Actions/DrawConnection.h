#pragma once
#include "action.h"
#include "..\Components\Connection.h"

class DrawConnection :
	public Action
{
private:
	int Cx1, Cy1;  //The First point Clicked(On the Source)
	int Cx2, Cy2; //The Second point Clicked(On the Destinatuin)
	
public:
	DrawConnection(ApplicationManager *pApp);
	~DrawConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	

	virtual void Undo();
	virtual void Redo();
};

