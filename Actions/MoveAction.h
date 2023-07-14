#ifndef MOVEACTION_H
#define MOVEACTION_H
#include"Action.h"
#include "../Figures/CFigure.h"
class MoveAction :public Action
{
private:
	Point P1;
	Point lastP;
	CFigure* MFIG;
	Point lastPoint;
public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
	~MoveAction();

	virtual void Undo();
	virtual void Redo();

};
#endif 
