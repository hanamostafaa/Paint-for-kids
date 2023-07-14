#ifndef BYTYPEANDCOLORACTION_H
#define BYTYPEANDCOLORACTION_H
#include"Action.h"
class ByTypeAndColor :public Action
{
	int RightAns; //number of right answers
	int WrongAns;  //number of wrong answers
	int tobepicked;  //number of figures the kid should pick
	Point P;
	bool sound;
public:
	ByTypeAndColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool mode=0);
	void print(bool b);

};
#endif 

