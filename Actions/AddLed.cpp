#include "AddLed.h"
#include "..\ApplicationManager.h"


AddLed::AddLed(ApplicationManager *pApp):Action(pApp)
{
}


AddLed::~AddLed(void)
{
}

void AddLed::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Led: Click to add "); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddLed::Execute()
{
	//Get Center point of led
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the led
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;

	Led *pA=new Led (GInfo); // 
	pManager->AddComponent(pA);
}
void AddLed::Undo()
{}

void AddLed::Redo()
{}
