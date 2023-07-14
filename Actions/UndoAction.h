#ifndef UNDOACTION_H
#define UNDOACTION_H

#include"Action.h"
#include "../ApplicationManager.h"
class UndoAction : public Action {
public:
	UndoAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool mode = 0);
	
};
#endif

