#include "Paste.h"
#include "..\ApplicationManager.h"

Paste::Paste(ApplicationManager *pApp ):Action(pApp)
{
	
}



void Paste:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("2-Paste: Click to Paste the gate"); 

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

Paste::~Paste(void)
{
}

void Paste:: Execute()
{
	ReadActionParameters();
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the component
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;

	if (pManager->GetClipBoard()!=NULL)
	{
	 Component*pss= pManager->GetClipBoard()->GetCopy(GInfo);
	 pManager->AddComponent(pss);
	}
}

void Paste::Undo()
{}

void Paste::Redo()
{}