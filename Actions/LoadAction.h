#ifndef LOADACTION_H
#define LOADACTION_H


#include"Action.h"
#include<fstream>
#include"../ApplicationManager.h"
class LoadAction : public Action {
private:
	string filename = "Figures.txt";
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	virtual void Execute(bool mode=0);
};
#endif

