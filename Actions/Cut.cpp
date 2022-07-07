#include "Cut.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"

Cut::Cut(ApplicationManager *pApp ):Action(pApp)
{
	
}

Cut::~Cut(void)
{
}

void Cut:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Cut: Click to Cut the gate"); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Cut:: Execute()
{
	int j ;
	ReadActionParameters();
	//Check which component is clicked
	Component* Cmp=pManager->iNSIDEaREA(Cx,Cy);
	if (Cmp!= NULL)// make sure that the user clicks on a component
	{
		pManager->SetClipBoard(Cmp);  //Setting the Clipboard with the component
		pManager->DeleteComponent(Cmp); //Sending the Component to App manager delete function to be deleted
	}
			
	
	   Connection** Conn= pManager->Connected(Cmp, j); 
	 if (Conn!= NULL) // make sure that there are connections connected to the component
		 for (int i = 0 ; i < j ; i ++)// deleting all connections
		pManager->DeleteComponent(Conn[i]); //Sending the Connection to App manager delete function to be deleted*/
}

void Cut::Undo()
{}

void Cut::Redo()
{}