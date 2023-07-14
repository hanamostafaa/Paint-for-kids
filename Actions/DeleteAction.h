#ifndef DELETEACTION_H
#define DELETEACTION_H
#include"Action.h"
#include"../Figures/CFigure.h"
class DeleteAction :public Action
{
	bool sound;
	CFigure* Fig;
public:
	DeleteAction(ApplicationManager* pApp,bool b);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
	~DeleteAction();

	virtual void Undo();
	virtual void Redo();

};
#endif 


