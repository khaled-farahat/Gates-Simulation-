#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddBUFFER.h "
#include "Actions\AddNOTgate.h "
#include "Actions\AddORgate2.h "
#include "Actions\AddNANDgate.h "
#include "Actions\AddNORgate2.h "
#include "Actions\AddXORgate2.h "
#include "Actions\AddXNORgate.h "
#include "Actions\AddANDgate3.h "
#include "Actions\AddNorgate3.h "
#include "Actions\AddXORgate3.h "
#include "Actions\AddSwitch.h "
#include "Actions\AddLed.h "
#include "Actions\AddLabel.h"
#include "Actions\Delete.h "
#include "Actions\Edit.h "
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "Actions\DrawConnection.h"
#include "Actions\Simulate.h"
#include "Actions\Simulation.h"
#include "Actions\ZeroSwitch.h"
#include "Actions\OnSwitch.h"
#include "Actions\Design.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	//Intialaize the clipboard to NULL
	ClipBoard = NULL ; 
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteComponent(Component* pComp)
{
	for(int i=0; i<CompCount; i++)
		if (CompList[i]== pComp)
		{
			
			if(Connection*c=dynamic_cast<Connection*>(CompList[i]))
			{
			Component*com=c->GetDstCmpnt();
			com->decrementN();
		    }
		delete CompList[i];
		CompList[i]=CompList[CompCount-1];
		CompList[CompCount-1]=NULL;
		CompCount--;
		}
}


ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_Buff :
			pAct= new AddBUFFER (this);
			break;
		case ADD_INV :
			pAct= new AddNOTgate (this);
			break;
 	    case ADD_OR_GATE_2 :
			pAct= new AddORgate2 (this);
			break;
        case ADD_NAND_GATE_2 :
			pAct= new AddNANDgate (this);
			break;
	    case ADD_NOR_GATE_2 :
			pAct= new AddNORgate2 (this);
			break;
	    case ADD_XOR_GATE_2 :
			pAct= new AddXORgate2 (this);
			break;	
        case ADD_XNOR_GATE_2 :
			pAct= new AddXNORgate (this);
			break;	
        case ADD_AND_GATE_3 :
			pAct= new AddANDgate3 (this);
			break;
        case ADD_NOR_GATE_3 :
			pAct= new AddNorgate3 (this);
			break;
        case ADD_XOR_GATE_3 :
 			pAct= new AddXORgate3 (this);
			break;
        case ADD_Switch :
			pAct= new AddSwitch (this);
			break;
        case ADD_LED :
			pAct= new AddLed (this);
			break;
        case ADD_Label :
			pAct= new AddLabel (this);
			break;  	
        case EDIT_Label :
			pAct= new Edit (this );
			break; 
        case DEL :
			pAct= new Delete (this );
			break;
        case cpy :
			pAct= new Copy (this );
			break;
        case cutt :
			pAct= new Cut (this );
			break;
        case pst :
			pAct= new Paste (this );
			break;
		case ADD_CONNECTION:
			pAct= new DrawConnection (this);
			break;
	    
		case SwitchOff:
			pAct= new ZeroSwitch (this);
			break;
        case SwitchOn:
			pAct= new OnSwitch (this);
			break;
	   case SIM_MODE :
			pAct= new Simulation (this);
			break;
		case  DSN_MODE :
			pAct= new Design (this);
			break;
		case  SImulate :
			pAct= new Simulate (this);
			break;
			
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	//1- Clear Draeing Area
	OutputInterface->ClearDrawingArea();
	//2- Draw all the components in the CompList
		for(int i=0; i<CompCount; i++)
		{
			CompList[i]->Draw(OutputInterface);
			CompList[i]->drawCompLabel(OutputInterface);
		}

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}

void ApplicationManager:: SetClipBoard(Component* c)
{
	ClipBoard = c;
}

Component* ApplicationManager:: GetClipBoard()
{
	return ClipBoard;
}

Component* ApplicationManager:: iNSIDEaREA(int x , int y)
{
	for(int i=0; i<CompCount; i++)
	{
		if (CompList[i]->InsideArea(x, y))
			return CompList[i];
	}
	return NULL;
}

Connection** ApplicationManager:: Connected(Component* Pcomp , int &j)
{
	 j = 0 ;
	 for (int i = 0 ; i< CompCount ; i++ )
	 {
		 //Check whether the component is Connection
		 Connection* ConnPtr = dynamic_cast<Connection*>(CompList[i]);
		 if (ConnPtr !=NULL)
		 { //check whether the component passed is connected to the connection 
			 if (ConnPtr-> GetSrcCmpnt()== Pcomp || ConnPtr-> GetDstCmpnt()== Pcomp ) 
			 {
				 j++; //Calculate the number of connections connected to the Component
			 }
		 }
	 }
	 Connection** C=new Connection* [j];
	 for (int i = 0 ; i < j ; i++)
		 C[i]=NULL;
	 j=0;
	  for (int i = 0 ; i< CompCount ; i++ )
	 {
		 //Check whether the component is Connection
		 Connection* ConnPtr = dynamic_cast<Connection*>(CompList[i]);
		 if (ConnPtr !=NULL)
		 { //check whether the component passed is connected to the connection 
			 if (ConnPtr-> GetSrcCmpnt()== Pcomp || ConnPtr-> GetDstCmpnt()== Pcomp ) 
			 {
				 //filling the array of connections
				 C[j]=ConnPtr;
				 j++; //Calculate the number of connections connected to the Component
			 }
		 }
	 }

	 if (C!=NULL)
		 return C;
return NULL;
}



void ApplicationManager:: OperateAll()
{

	for(int i=0; i<CompCount; i++)
	{  
		CompList[i]->Operate();
		Connection* Conn = dynamic_cast<Connection*>(CompList[i]);

		if (Conn =NULL)
		{
			Component* C=CompList[i];
			for (int i = 0 ; i< CompCount ; i++ )
			{
				Connection* ConnPt = dynamic_cast<Connection*>(CompList[i]);
				if (ConnPt !=NULL)
				{		
					if (ConnPt->GetSrcCmpnt()==C)
						 ConnPt->setInputPinStatus(1,(STATUS)C->GetOutPinStatus());
					
				 break;
				}
			}
		}
		 
			
	      
		if (Conn !=NULL)
		{
			for (int i = 0 ; i< CompCount ; i++ )
			{
				if(Conn->GetDstCmpnt()== CompList[i])
				{
					 CompList[i]->setInputPinStatus(1,(STATUS)Conn->GetOutPinStatus());
				 break;
				}
			}
		}
		  
	}

}

  
Led** ApplicationManager:: numberofLeds(int &n)
{
	n=0;
	for (int i = 0 ; i< CompCount ; i++ )
	{
		Led* g = dynamic_cast <Led*>(CompList[i]);
		if (g!=NULL)
		{
			n++;
		}
	}

	Led**L= new Led*[n];
	for (int i = 0 ; i < n ; i++)
	{
		 L[i]=NULL;
	}	 			 		
	 if (L!=NULL)
		  return L;
	 return NULL;
}	
	
	
/*bool ApplicationManager:: getAllstatus(Led**L,int n)
{
	int t=0;
	for (int i=0;i<n;i++)
	{
        if (L[i]->GetInputPinStatus(0)==NotAssigned)
             t++;
	}
	 if (t>0)
		 return true;
}
 void ApplicationManager:: Draw(Led**L,int n)
 {
	Output*p;
	 for (int i=0 ;i<n;i++)
	 {
        GraphicsInfo m = L[i]->GetAllGraphicsInfo();
		 if (L[i]->GetInputPinStatus(0)==HIGH)
            p->Drawled(m,true);
		 else
           p->Drawled2(m);
	 }
 }*/

