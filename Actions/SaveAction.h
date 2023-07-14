#ifndef SAVEACTION_H
#define SAVEACTION_H
#include"Action.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include <fstream>
class SaveAction :public Action {
private:
	string filename = "Figures.txt";
public:
	SaveAction(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();


	//Execute action (code depends on action type)
	virtual void Execute(bool mode=0);
};
#endif

