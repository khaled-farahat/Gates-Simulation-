#include "Simulation.h"
#include "..\ApplicationManager.h"

Simulation::Simulation(ApplicationManager *pApp):Action(pApp)
{
}


Simulation::~Simulation(void)
{
}
void Simulation ::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	
	//Print Action Message
	pOut->PrintMsg("You are going to Simulation Mode "); 
	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Simulation::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->CreateSimulationToolBar();
	
	
}

void Simulation::Undo()
{}

void Simulation ::Redo()
{}