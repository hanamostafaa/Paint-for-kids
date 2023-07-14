#ifndef CLEARALLACTION_H
#define CLEARALLACTION_H
#include"Action.h"
class ClearAll :public Action
{
	bool sound;
public:
	ClearAll(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);

};
#endif 

