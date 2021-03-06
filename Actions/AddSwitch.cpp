#include "AddSwitch.h"

#include "..\ApplicationManager.h"

AddSwitch::AddSwitch(ApplicationManager *pApp):Action(pApp)
{

}


AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::Undo()
{}

void AddSwitch::Redo()
{}

void AddSwitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the Switch gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;

	Switch *pA=new Switch(GInfo, AND2_FANOUT); // 
	pManager->AddComponent(pA);
}

void AddSwitch ::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Switch: Click to add "); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}
