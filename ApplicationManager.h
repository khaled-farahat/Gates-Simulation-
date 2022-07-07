#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components\Connection.h"
#include "Components\Led.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* ClipBoard; //Pointer to the component cut or copied



public:	
	ApplicationManager(); //constructor
	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	//Delete a component from the list of components
	void DeleteComponent(Component* pComp);
	//Sets the component we Copy or Cut 
	void SetClipBoard(Component* c);
	//Gets The component we copy or cut to paste
	Component* GetClipBoard();
	//destructor
	~ApplicationManager();
	//Returns the component that the point is inside its Area
	Component* iNSIDEaREA(int x , int y);
	//Retuen the array of connections connected to a component
	Connection** Connected(Component* Pcomp , int &j);

	void OperateAll();
	Led**  numberofLeds(int &n);
};

#endif