#ifndef TOPLAYACTION_H
#define TOPLAYACTION_H
#include"Action.h"
class ToPlay :public Action
{
public:
	ToPlay(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);

};
#endif 


