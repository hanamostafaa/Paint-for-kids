#ifndef STARTREC_H
#define STARTREC_H
#include"Action.h"

class StartRecAction :public Action
{
private:
	Action* Arr[20];
	ActionType ActType;
public:
	StartRecAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
};
#endif

