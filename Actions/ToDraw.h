#ifndef TODRAWACTION_H
#define TODRAWACTION_H
#include"Action.h"
class ToDraw :public Action
{
public:
	ToDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);

};
#endif 


