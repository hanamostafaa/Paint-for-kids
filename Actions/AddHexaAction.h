#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H

#include "Action.h"
#include "../Figures/CHexagon.h"

//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point P1; //Hexagon Center
	GfxInfo HexaGfxInfo;
	bool sound;
	CHexagon* figHexagon;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool mode=0);
	virtual void Undo();
	virtual void Redo();

};

#endif
