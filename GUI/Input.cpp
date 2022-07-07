//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut , string text, string label)
{
	const int escape=27, enter=13, backspace=8; 
	char c;
	string s =label;
	pWind->FlushKeyQueue();
	do
	{
		pOut->PrintMsg(text +""+s);
		pWind->WaitKeyPress(c);
		switch (c)
		{ 
		case escape:
			s.clear(); //return empty string
			pOut->ClearStatusBar();
			break;
		case enter:
			pOut->ClearStatusBar();
			break; //end of input and reflect string
		case backspace:
			if (!s.empty())
			{
				s.pop_back(); //erase 1 step
			}
			break;
		default:
			s.push_back(c); //keep the char
			break;
		}
	}
	while (c!=escape && c!=enter); //while not escape nor enter reflect the char on the screen
	

	
	
	return s;
	  
	

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
		{ 
			 
			case ITM_NOT: return ADD_INV;
			case ITM_BUFFER: return ADD_Buff;	
            case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR: return ADD_OR_GATE_2 ;
			case ITM_NAND: return ADD_NAND_GATE_2 ;
		    case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3 ;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
            case ITM_EXIT: return EXIT;
 			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	if ( y >= UI.ToolBarHeight && y < 160)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
           
			case ITM_Switch: return ADD_Switch;
			case ITM_LED: return ADD_LED;	
            case ITM_Connect: return ADD_CONNECTION;
			case ITM_Label: return ADD_Label;
			case ITM_Edit: return EDIT_Label ;
		    case ITM_Save: return SAVE;
			case ITM_Load: return LOAD;
			case ITM_Copy: return cpy;
			case ITM_Cut: return cutt;
			case ITM_Paste: return pst;
            case ITM_DEL: return DEL;
			case ITM_Switch_to_SimulationMode: return SIM_MODE;			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if ( y >= 160 && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
		   { 
			 
			case ITM_SIM: return SImulate;
             case ITM_Switchon: return SwitchOn;
             case ITM_Switchoff: return SwitchOff;
            case ITM_Switchback: return DSN_MODE;    //This should be changed after creating the compelete simulation bar 
            default: return DSN_TOOL;
			}
		}
	}

}

Input::~Input()
{
}
