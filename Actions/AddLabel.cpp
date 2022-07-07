#include "AddLabel.h"
#include "..\ApplicationManager.h"

AddLabel::AddLabel(ApplicationManager*pApp  )  :Action(pApp)
{

}

void AddLabel:: ReadActionParameters()
{
     Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Choose component to Label it "); 


pIn->GetPointClicked(Cx, Cy);


	//Clear Status Bar
	pOut->ClearStatusBar();

	Component* Cmp=pManager->iNSIDEaREA(Cx,Cy);

	 if (Cmp!= NULL)
			{
				//if component choosed set its label
				Cmp->setlabel(pOut, pIn,"Enter Label : ", "");

				pOut->ClearStatusBar();
		 }
	

}
void AddLabel:: Execute()
{
	ReadActionParameters();
}


 void AddLabel:: Undo()
 {
 }
 void AddLabel:: Redo()
 {
 }
  AddLabel ::~ AddLabel(void)
  {}
