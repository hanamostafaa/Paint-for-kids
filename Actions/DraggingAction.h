#ifndef DRAGACTION_H
#define DRAGACTION_H
#include"Action.h"
class DraggingAction :public Action
{
private:
	Point P1;
public:
	DraggingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode = 0);
	
	~DraggingAction();

};
#endif 

