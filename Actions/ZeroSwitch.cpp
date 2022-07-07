#include "ZeroSwitch.h"
#include "..\ApplicationManager.h"

ZeroSwitch::ZeroSwitch(ApplicationManager *pApp):Action(pApp)
{
}



ZeroSwitch::~ZeroSwitch(void)
{
}


void ZeroSwitch::Undo()
{

}

	
void ZeroSwitch::Redo()
{

}

void ZeroSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("2-Click on ONE switch to make its status LOW"); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}
void ZeroSwitch::Execute()
{
	ReadActionParameters();
	//Check which component is clicked
	Component* Cmp=pManager->iNSIDEaREA(Cx,Cy);
	//Check whether the component clicked is Switch
	 Switch* SwtchPtr = dynamic_cast<Switch*>(Cmp);
	 if (SwtchPtr!=NULL)
	 {
		SwtchPtr->ChangeStatus(LOW);//Make The Switch Status=HIGH
	 }
}