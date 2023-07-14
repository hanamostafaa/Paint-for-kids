#ifndef CHANGEFILLCOLOR_H
#define CHANGEFILLCOLOR_H
#include"Action.h"
#include"../Figures/CFigure.h"

class ChangeFillColor :public Action
{
private:
	ActionType ActType;
	CFigure* FIG;
	color lastColor;
	bool isFilled;
public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);


	virtual void Undo();
	virtual void Redo();
};
#endif

