#include"Action.h"
#include"../ApplicationManager.h"

class RedoAction : public Action {
public:
	RedoAction(ApplicationManager* pApp);
	void ReadActionParameters();
    void Execute(bool mode = 0);
};
#pragma once
