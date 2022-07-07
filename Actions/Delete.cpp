#include "Delete.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"

Delete::Delete(ApplicationManager *pApp):Action(pApp)
{
	
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("2-Delete: Click to dalaete the gate "); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
Delete::~Delete(void)
{

}
void Delete:: Execute()
{ 
	
	ReadActionParameters();
	int j ;
	//Check which component is clicked
	Component* Cmp=pManager->iNSIDEaREA(Cx,Cy);
	if (Cmp!= NULL) // make sure that the user clicks on a component
		pManager->DeleteComponent(Cmp); //Sending the Component to App manager delete function to be deleted
	
		
    Connection** Conn= pManager->Connected(Cmp, j);
	 if (Conn!= NULL) // make sure that there are connections connected to the component
		 for (int i = 0 ; i < j ; i ++) // deleting all connections
		pManager->DeleteComponent(Conn[i]); //Sending the Connection to App manager delete function to be deleted
}

 void Delete :: Undo()
 {}

	
 void Delete :: Redo()
 {}
