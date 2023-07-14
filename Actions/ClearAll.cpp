#include "ClearAll.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include<windows.h>

ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAll::Execute(bool mode)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->clear();
	if (!pManager->getplayon())
	{
		pManager->ClearRec();
		pManager->ClearUndoActions();
	}
	pOut->reset();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	

}

void ClearAll::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();

}
