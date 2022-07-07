#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void CreateDesignToolBar2() const;  //Tool bar of the design mode
	void ClearDesignToolBar2()const;    //Clears the second toolbar 
	void ClearDesignToolBar()const;     //Clears the second toolbar 
	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	
	// Draws 2-input AND gate
	

	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 2-input OR gate
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 2-input NOR gate
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 2-input XOR gate
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 2-input NOR gate
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws BUFFER gate
	void Drawbuffer2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws INVERTER gate
	void Drawnot2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 3-input AND gate
	void Draw3and2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 3-input NOR gate
	void Draw3nor2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws 3-input XOR gate
	void Draw3xor2(GraphicsInfo r_GfxInfo, bool selected = false) const;


	// Draws SWITCH
	void Drawswitch2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws LED
	void Drawled2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	//Draw Open Led
	void Drawled(GraphicsInfo r_GfxInfo, bool selected = false) const;
   // Draws 2-input NAND gate
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false ) const;

	

	
	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar
	// Draw label of gates 
	void DrawLabel(int , int ,string label);


	~Output();
};
