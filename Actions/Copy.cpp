#include "Copy.h"
#include "..\ApplicationManager.h"

Copy::Copy(ApplicationManager *pApp):Action(pApp)
{
	
}

void Copy:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("2-Copy Click to Copy the gate"); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

Copy::~Copy(void)
{
}

void Copy:: Execute()
{
	ReadActionParameters();
	//Check which component is clicked
	Component* Cmp=pManager->iNSIDEaREA(Cx,Cy);
	if (Cmp!= NULL) // make sure that the user clicks on a component
		pManager->SetClipBoard(Cmp); //Setting the Clipboard with the component
	   
}

void Copy::Undo()
{}

void Copy::Redo()
{}