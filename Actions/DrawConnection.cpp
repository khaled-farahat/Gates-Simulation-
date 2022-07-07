#include "DrawConnection.h"
#include "..\ApplicationManager.h"

DrawConnection::DrawConnection(ApplicationManager *pApp ):Action(pApp)
{
	
}

void DrawConnection:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg(" Draw Connection: Click on the  source "); 

	//Wait for User First Input
	pIn->GetPointClicked(Cx1, Cy1);
	//Clear Status Bar
	pOut->ClearStatusBar();

	pOut->PrintMsg(" Click on the destination "); 
	//Wait for User Second Input
	pIn->GetPointClicked(Cx2, Cy2);
	//Clear Status Bar
	pOut->ClearStatusBar();
}

void DrawConnection:: Execute()
{
	ReadActionParameters();
	GraphicsInfo GInfo;
	OutputPin *pSrcPin;
	InputPin *pDstPin;
	Component* Source;
	Component* Destination;

	//Check which component is clicked
	Component* Cmp=pManager->iNSIDEaREA(Cx1,Cy1); 
	if (Cmp!= NULL) // make sure that the user clicks on a component
	{
		pSrcPin=new OutputPin (AND2_FANOUT); 
		//The Status of the InputPin of the connection is the status of the OutPin of the Source
		pSrcPin->setStatus((STATUS)Cmp->GetOutPinStatus());
		//The x coordinate of the first point of the connenction is the x coordinate of the Outpin of the Source
		GInfo.y1=Cmp->GetGraphicsInfoOutPenY(); 
		//The y coordinate of the first point of the connenction is the y coordinate of the Outpin of the Source
		GInfo.x1=Cmp->GetGraphicsInfoOutPenX();
		Source = Cmp; //makes the Source Pointer points to the Component
	}
    //Check which component is clicked
	Cmp=pManager->iNSIDEaREA(Cx2,Cy2);
		if (Cmp!= NULL)// make sure that the user clicks on a component
	    {
			pDstPin = new InputPin();
			Cmp->setInputPinStatus(1,pDstPin->getStatus()); 
			//The x coordinate of the Second point of the connenction is the x coordinate of the Inpin of the Destination
			GInfo.x2=Cmp->GetGraphicsInfoInPenX();
			//The x coordinate of the Second point of the connenction is the x coordinate of the Inpin of the Destination
			GInfo.y2=Cmp->GetGraphicsInfoInPenY();
			Destination = Cmp; //makes the Destination Pointer points to the Component
			
		}
	
	Connection *pA=new Connection(GInfo,pSrcPin,pDstPin );  
	//The status of the InPin of the Destination is the Status of the OutPin of the connection 

	pManager->AddComponent(pA);
	pA->SetSrcCmpnt(Source);
	pA->SetDstCmpnt(Destination);
}

void DrawConnection:: Undo()
{

}

void DrawConnection:: Redo()
{

}

DrawConnection::~DrawConnection(void)
{

}
