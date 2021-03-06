#pragma once
#include "action.h"
#include "..\Components\Led.h"
class AddLed : public Action
{
	private:
	//Parameters for rectangular area to be occupied by led
	int Cx, Cy;	//Center point of the led
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:
	AddLed(ApplicationManager *pApp);
	~AddLed(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

