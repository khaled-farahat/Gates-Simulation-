#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateDesignToolBar2();
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 160, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar2) in the Design mode
void Output::CreateDesignToolBar2() const
{
	UI.AppMode = DESIGN;	//Design Mode
	string MenuItemImages[ITM_DSN_CNT2];
	 
	MenuItemImages[ITM_Switch] = "images\\Menu\\switch.jpg"; 
	MenuItemImages[ITM_LED] = "images\\Menu\\Led.jpg"; 
	MenuItemImages[ITM_Connect] = "images\\Menu\\Connection.jpg"; 

	MenuItemImages[ITM_Label]  = "images\\Menu\\Label.jpg";
	MenuItemImages[ITM_Edit]  = "images\\Menu\\Edit.jpg";
	MenuItemImages[ITM_Save]  = "images\\Menu\\Save.jpg";
	MenuItemImages[ITM_Load]  = "images\\Menu\\Load.jpg";
	MenuItemImages[ITM_Copy]  = "images\\Menu\\Copy.jpg";
	MenuItemImages[ITM_Cut]  = "images\\Menu\\Cut.jpg";
	MenuItemImages[ITM_Paste]  = "images\\Menu\\Paste.jpg";
	MenuItemImages[ITM_DEL]  = "images\\Menu\\Delete.jpg";
    MenuItemImages[ITM_Switch_to_SimulationMode]  = "images\\Menu\\Simulate.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT2; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,83,UI.ToolItemWidth,UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::ClearDesignToolBar()const
{
	//Overwrite using bachground color 
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width,UI.ToolBarHeight );
}
void Output::ClearDesignToolBar2()const
{
	//Overwrite using bachground color 
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 160, UI.width,UI.ToolBarHeight );
}
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode


	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_NOT] = "images\\Menu\\NOT.jpg"; 
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\BUFFER.jpg"; 
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";  
	MenuItemImages[ITM_OR]  = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NAND]  = "images\\Menu\\NAND.jpg";
	MenuItemImages[ITM_NOR2]  = "images\\Menu\\NOR.jpg";
	MenuItemImages[ITM_XOR2]  = "images\\Menu\\XOR.jpg";
	MenuItemImages[ITM_XNOR]  = "images\\Menu\\XNOR.jpg";
	MenuItemImages[ITM_AND3]  = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3]  = "images\\Menu\\Menu_NOR3.jpg";
    MenuItemImages[ITM_XOR3]  = "images\\Menu\\XOR3.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";


	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	ClearDesignToolBar();
	ClearDesignToolBar2();
	string MenuItemImages[ITM_SIM_CNT];  
	
	MenuItemImages[ITM_SIM] = "images\\Menu\\Simulate.jpg"; 
	MenuItemImages[ITM_Switchon] = "images\\Menu\\SwitchOn.jpg"; 
	MenuItemImages[ITM_Switchoff] = "images\\Menu\\SwitchOff.jpg"; 
	MenuItemImages[ITM_Switchback] = "images\\Menu\\Design.jpg";  
	



	//Draw menu item one image at a time
	for(int i=0; i<ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, 240, UI.ToolBarHeight);	

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\55.jpeg";
	else
		GateImage = "Images\\Gates\\66.jpeg";

	//Draw OR2 Gate at Gfx_Info (2st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Draw3and2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3andh.jpeg";
	else
		GateImage = "Images\\Gates\\3and.jpeg";

	//Draw AND3 Gate at Gfx_Info 
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Draw3nor2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3norh.jpeg";
	else
		GateImage = "Images\\Gates\\3nor.jpeg";

	//Draw NOR3 Gate at Gfx_Info 
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Draw3xor2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3xorh.jpeg";
	else
		GateImage = "Images\\Gates\\3xor.jpeg";

	//Draw XOR2 Gate at Gfx_Info 
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Drawswitch2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\swh.jpeg";
	else
		GateImage = "Images\\Gates\\sw.jpeg";

	//Draw SWITCH
	//Set the Image Width & Height by SWITCH Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Drawled2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\ledh.jpeg";
	else
		GateImage = "Images\\Gates\\led.jpeg";

	//Draw LED
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\11.jpeg";
	else
		GateImage = "Images\\Gates\\111.jpeg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\22.jpeg";
	else
		GateImage = "Images\\Gates\\333.jpeg";

	//Draw XNOR2 Gate at Gfx_Info 
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Drawbuffer2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\bh.jpeg";
	else
		GateImage = "Images\\Gates\\b.jpeg";

	//Draw BUFFER Gate at Gfx_Info 
	//Set the Image Width & Height by BUFFER Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::Drawnot2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\inh.jpeg";
	else
		GateImage = "Images\\Gates\\in.jpeg";

	//Draw NOT Gate at Gfx_Info
	//Set the Image Width & Height by NOT Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\77.jpeg";
	else
		GateImage = "Images\\Gates\\88.jpeg";

	//Draw NOR2 Gate at Gfx_Info 
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\33.jpeg";
	else
		GateImage = "Images\\Gates\\44.jpeg";

	//Draw NAND2 Gate at Gfx_Info 
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::Drawled(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\OpenLedS.jpeg";
	else
		GateImage = "Images\\Gates\\OpenLed.jpeg";

	//Draw LED
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{  //Draw Straight Line if the two points are vertical or hprizontal
	if (r_GfxInfo.x1== r_GfxInfo.x2 || r_GfxInfo.y1== r_GfxInfo.y2)
	{
		pWind->SetPen(BLACK,3);
		pWind->DrawLine(r_GfxInfo.x1 ,r_GfxInfo.y1 ,r_GfxInfo.x2,  r_GfxInfo.y2);
	}
	else
		//Draw broken line
	{
		pWind->SetPen(BLACK,3);
		//Draw Horizontal Line from the first point to the middle point between the two points
		pWind->DrawLine(r_GfxInfo.x1 ,r_GfxInfo.y1 ,((r_GfxInfo.x2+r_GfxInfo.x1)/2),  r_GfxInfo.y1);
		pWind->SetPen(BLACK,3);
		//Draw Vwertical Line from the middle point between the two points to the second point
	    pWind->DrawLine(((r_GfxInfo.x2+r_GfxInfo.x1)/2) ,r_GfxInfo.y1 ,((r_GfxInfo.x2+r_GfxInfo.x1)/2),  r_GfxInfo.y2);
		pWind->SetPen(BLACK,3);
		//Draw Horizontal Line from the middle point between the two points to the second point
	    pWind->DrawLine(((r_GfxInfo.x2+r_GfxInfo.x1)/2) ,r_GfxInfo.y2 ,r_GfxInfo.x2,  r_GfxInfo.y2);
	}
}

Output::~Output() ///
{
	delete pWind;
}
void Output::DrawLabel(int x1 , int y1 , string label)
{
		pWind->SetPen(BLACK, 1);
	pWind->DrawString(x1 , y1-20 , label);
}
/*void Output:: Clearcomp(GraphicsInfo m_GfxInfo) const
{
	int w=m_GfxInfo.x1-m_GfxInfo.x2;
	int h=m_GfxInfo.y1-m_GfxInfo.y2;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,160 ,w,h);
}*/