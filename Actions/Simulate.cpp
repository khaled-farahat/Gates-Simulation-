#include "Simulate.h"
#include "..\ApplicationManager.h"


Simulate::Simulate(ApplicationManager *pApp ):Action(pApp)
{
	
}


Simulate::~Simulate(void)
{
}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

void  Simulate::ReadActionParameters()
{
	
}

void  Simulate:: Execute()
{
	int l = 0 ;
    Led **L= pManager->numberofLeds(l);
	for(int i = 0 ; i< l ; i++ )
	{
		while(L[i]->getAllstatus())
			pManager->OperateAll();
	}
	Output*Pout = pManager->GetOutput();
	Pout->PrintMsg(to_string(L[0]->GetInputPinStatus(0)));
/*int l = 0 ;
    Led **L= pManager->numberofLeds(l);
	
		while(pManager->getAllstatus(L,l))
		{
			pManager->OperateAll();
			
		}
  
	pManager->Draw(L,l);
	Output*Pout = pManager->GetOutput();
	Pout->PrintMsg(to_string(L[0]->GetInputPinStatus(0)));*/
}