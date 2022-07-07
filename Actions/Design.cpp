#include "Design.h"
#include "..\ApplicationManager.h"

Design::Design(ApplicationManager *pApp):Action(pApp)
{
}


Design::~Design(void)
{
}
void Design::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	
	//Print Action Message
	pOut->PrintMsg("You are going back to Design Mode "); 

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Design::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDesignToolBar();
	pOut->CreateDesignToolBar();
	pOut->CreateDesignToolBar2();
	
}

void Design::Undo()
{}

void Design::Redo()
{}
