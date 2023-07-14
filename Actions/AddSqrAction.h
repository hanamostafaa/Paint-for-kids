#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"
#include "../Figures/CSquare.h"
//Add square Action class
class AddSqrAction : public Action
{
private:
	Point P1; //square center
	GfxInfo SqrGfxInfo;
	bool sound;
	CSquare* figSquare;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute(bool mode=0);

	virtual void Undo();
	virtual void Redo();
};

#endif

