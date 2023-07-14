#ifndef SOUNDACTION_H
#define SOUNDACTION_H
#include"Action.h"
class Sound :public Action
{
public:
	Sound(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode = 0);

};
#endif 

