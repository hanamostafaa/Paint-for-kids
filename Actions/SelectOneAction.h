#ifndef SELECTONE_H
#define SELECTONE_H
#include"Action.h"

class SelectOneAction :public Action
{
private:
	Point P1;
public:
	SelectOneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
};
#endif

