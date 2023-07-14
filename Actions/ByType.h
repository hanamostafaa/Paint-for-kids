#ifndef BYTYPEACTION_H
#define BYTYPEACTION_H
#include"Action.h"
class ByType :public Action
{
	int RightAns; //number of right answers
	int WrongAns;  //number of wrong answers
	int tobepicked;  //number of figures the kid should pick
	Point P;
	bool sound;
public:
	ByType(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
	void print(bool b);

};
#endif 

