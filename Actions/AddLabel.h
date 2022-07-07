#ifndef _ADD_LABEL_H
#define _ADD_LABEL_H
 #include "action.h"
#include "..\Components\Component.h"


class AddLabel :	public Action
{
private:
	int Cx ,Cy;
	
public:
	AddLabel(ApplicationManager*pApp);
	virtual ~ AddLabel(void);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


		






};
#endif