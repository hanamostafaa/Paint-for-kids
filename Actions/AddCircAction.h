#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point P1,P2; //Center and point on circle
	GfxInfo CircGfxInfo;
	bool sound;
	CFigure* C;
	
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute(bool mode=0);
	virtual void Undo();
	virtual void Redo();


};

#endif

