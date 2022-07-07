#include "OnSwitch.h"
#include "..\ApplicationManager.h"

OnSwitch::OnSwitch(ApplicationManager *pApp):Action(pApp)
{
}


OnSwitch::~OnSwitch(void)
{
}

void OnSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Click on ONE switch to make its status HIGH"); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void OnSwitch::Execute()
{
	ReadActionParameters();
	//Check which component is clicked
	Component* Cmp=pManager->iNSIDEaREA(Cx,Cy);
	//Check whether the component clicked is Switch
	 Switch* SwtchPtr = dynamic_cast<Switch*>(Cmp);

	 if (SwtchPtr!=NULL)
	 {
		SwtchPtr->ChangeStatus(HIGH); //Make The Switch Status=HIGH
	 }
}

 void OnSwitch::Undo()
 {

 }
 void OnSwitch::Redo()
 {

 }