#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"


//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int N; //Parameter needed to determine the number of the inputPin Automatically
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	Component();
	//Destructor must be virtual
	virtual ~Component();

	virtual bool InsideArea(int x1, int y1); //Checks if the point is inside the component Area
	int GetGraphicsInfoOutPenY();  //Calculates the Y coordinate of the OutPen of the Component
	int GetGraphicsInfoOutPenX();  //Calculates the X coordinate of the OutPen of the Component
	int GetGraphicsInfoInPenX();  //Calculates the X coordinate of the InPen of the Component
	virtual int GetGraphicsInfoInPenY(); //Calculates the Y coordinate of the InPens of the different Components
	virtual Component* GetCopy(const GraphicsInfo &r_GfxInfo ); //Creats a copy of the component
	
	 virtual string getlabel();  //Gets The Label
	  void setlabel (Output*pOut, Input*pIn ,string t ,string s); // Sets The Label
     virtual void drawCompLabel(Output*);//Draw the label
	 void IncrementN();  //FUNCTION used to determine the number of input pin Automatically
	  void decrementN();//Decrease N in case of delete
};

#endif
