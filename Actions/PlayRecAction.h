#ifndef PLAYREC_H
#define PLAYREC_H
#include"Action.h"

class PlayRecAction :public Action
{
private:
	Action** recorded;
public:
	PlayRecAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
	~PlayRecAction();
};
#endif


