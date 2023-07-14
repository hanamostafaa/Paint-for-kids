#ifndef BYCOLORACTION_H
#define BYCOLORACTION_H
#include"Action.h"
class ByColor :public Action
{
	int RightAns; //number of right answers
	int WrongAns;  //number of wrong answers
	int tobepicked;  //number of figures the kid should pick
	Point P;
	bool sound;
public:
	ByColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);

};
#endif 

