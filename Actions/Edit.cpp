#include "Edit.h"
#include "..\ApplicationManager.h"

Edit::Edit(ApplicationManager*pApp )  :Action(pApp)
{

}

void Edit:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
     Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("choose component to edit it");
	
	//Wait for User Input
pIn->GetPointClicked(Cx1, Cy1);

//Clear Status Bar
pOut->ClearStatusBar();

 Component* Cmp=pManager->iNSIDEaREA(Cx1,Cy1);

 //check if choose component
 if (Cmp!= NULL)
 {
	 //if choosed component is connection 
	 if (Connection*con=dynamic_cast<Connection*>(Cmp))

	 {
		 //selection to choose edit label or connection itself
		 c= pIn->GetSrting(pOut,"type 1 to edit label or 2 to edit connection & press enter :","");
		 if (c=="1")
		 {
			 //if choose edit label
			 Cmp->setlabel(pOut , pIn , "Edit Label: ", Cmp->getlabel()) ;
		 }
		 
		 else 
		 {
			 //if choose 2 to edit connection
		    choose2= pIn->GetSrting(pOut,"type 1 to edit source or 2 to edit distination & press enter: ","");
			if (choose2=="1")
			{
				//if choose to edit source take source component
				pOut->PrintMsg("choose source componant");
				 

				pIn->GetPointClicked(Cx2, Cy2);
				pOut->ClearStatusBar();
			}
			else
			{
				//if choose to edit distination take distination component
				pOut->PrintMsg("choose distination componant");
				 
				pIn->GetPointClicked(Cx2, Cy2);
				pOut->ClearStatusBar();

			}
		 }
		     
		 
	 }
	 // if component is to it connection edit label
	 else
	 {
		 Cmp->setlabel(pOut , pIn , "Edit Label: ", Cmp->getlabel()) ;
	 }

 
 
 
 }
}
 void Edit :: Execute() 
{

		GraphicsInfo GInfo;
	OutputPin *pSrcPin;
	InputPin *pDstPin;
	Component* Source;
	Component* Destination;


		 ReadActionParameters();
     //if choose to edit source		 
	if (choose2=="1")
	{
	
		 Component* Cmp=pManager->iNSIDEaREA(Cx1,Cy1);
		 Connection*con=dynamic_cast<Connection*>(Cmp); 
		//take source from user
	    if (pManager->iNSIDEaREA(Cx2,Cy2))
		{
			Source =pManager->iNSIDEaREA(Cx2,Cy2);
		//create new outputpin
	 pSrcPin=new OutputPin (AND2_FANOUT);
		//The Status of the InputPin of the connection is the status of the OutPin of the Source
		pSrcPin->setStatus((STATUS)Source->GetOutPinStatus());
		//The x coordinate of the first point of the connenction is the x coordinate of the Outpin of the Source
		GInfo.y1=Source->GetGraphicsInfoOutPenY(); 
		//The y coordinate of the first point of the connenction is the y coordinate of the Outpin of the Source
		GInfo.x1=Source->GetGraphicsInfoOutPenX();

		//take destination from connection
	     Destination=con->GetDstCmpnt();
		 //take destination pin from connection
		 pDstPin = con->getDestPin();
		 //the x coordinate of unchanged destination
		GInfo.x2=Destination->GetGraphicsInfoInPenX();
		//the y coordinate of unchanged destination
		GInfo.y2=Destination->GetGraphicsInfoInPenY();
		//set status to destination
		Destination->setInputPinStatus(1,pDstPin->getStatus());
		//delete the previous connection
		pManager->DeleteComponent(Cmp);
		// create new one with new specifications
		Connection *pA=new Connection(GInfo,pSrcPin,pDstPin );
		//add connection in complist
	pManager->AddComponent(pA);
	//set source component
	pA->SetSrcCmpnt(Source);
	//set distination component
	pA->SetDstCmpnt(Destination);
			
		}
	}
	//if choose to edit destinayion 
	if (choose2=="2")
	{

			 Component* Cmp=pManager->iNSIDEaREA(Cx1,Cy1);
		 Connection*con=dynamic_cast<Connection*>(Cmp); 
		if (pManager->iNSIDEaREA(Cx2,Cy2))
		{
			//take destination component
	    Destination =pManager->iNSIDEaREA(Cx2,Cy2);
		//create new destination pin
	     pDstPin = new InputPin();
		 //The x coordinate of the second point of the connenction is the x coordinate of the Outpin of the new destination
		 GInfo.x2=Destination->GetGraphicsInfoInPenX();
		 //The y coordinate of the second point of the connenction is the y coordinate of the Outpin of the new destination
		GInfo.y2=Destination->GetGraphicsInfoInPenY();
		//The status of the InPin of the Destination is the Status of the OutPin of the connection
		Destination->setInputPinStatus(1,pDstPin->getStatus());

		//get source pin
		pSrcPin=con->getSourcePin();
		//set source component
		Source=con->GetSrcCmpnt();
		//set status
		pSrcPin->setStatus((STATUS)Source->GetOutPinStatus());
		//The x coordinate of the first point of the connenction is the x coordinate of the Outpin of the Source
		GInfo.y1=Source->GetGraphicsInfoOutPenY(); 
		//The y coordinate of the first point of the connenction is the y coordinate of the Outpin of the Source
		GInfo.x1=Source->GetGraphicsInfoOutPenX();
		//Delete the old connection
	    pManager->DeleteComponent(Cmp);
		//delete the previous connection
		Connection *pA=new Connection(GInfo,pSrcPin,pDstPin );  
	pManager->AddComponent(pA);
	pA->SetSrcCmpnt(Source);
	pA->SetDstCmpnt(Destination);
		}
	}
}


 void Edit:: Undo()
 {
 }
 void Edit:: Redo()
 {
 }
  Edit ::~Edit(void)
  {}

