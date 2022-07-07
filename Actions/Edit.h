#ifndef _EDIT_H
#define _EDIT_H
 #include "action.h"
#include "..\Components\Component.h"


class Edit :	public Action
{
private:
	int Cx1 ,Cy1;
	int Cx2 , Cy2;
	string c;
	string choose2;
public:
	Edit(ApplicationManager*pApp );
	virtual ~ Edit(void);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


		






};
#endif