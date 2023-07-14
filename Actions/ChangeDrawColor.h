#ifndef CHANGEDRAWCOLOR_H
#define CHANGEDRAWCOLOR_H
#include"Action.h"
#include"../Figures/CFigure.h"
class ChangeDrawColor :public Action
{
private:

	ActionType ActType;
	CFigure* FIG;
	color lastColor;

public:
	ChangeDrawColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);

	virtual void Undo();
	virtual void Redo();
};
#endif


