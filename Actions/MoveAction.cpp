#include "MoveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move selected figure: Click at any Point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();

}
void MoveAction::Execute(bool mode)
{
	Output* pOut=pManager->GetOutput();
	if(!mode)
	ReadActionParameters();

	MFIG=pManager->GetSelectedFig();
	if (MFIG != NULL) {
		lastPoint = MFIG->GetCenter();
		MFIG->shift(P1);
		MFIG->PrintInfo(pOut);
		MFIG->SetSelected(false);
		pManager->SetSelectedFig(NULL);
		pManager->AddMe(this);
	}
	else if (MFIG == NULL)
		pOut->PrintMessage("select a figure first");
}


void MoveAction::Undo()
{
	if (MFIG != NULL) {
		MFIG->shift(lastPoint);
	}
}

void MoveAction::Redo()
{
	if (MFIG != NULL) {
		MFIG->shift(P1);
	}
	pManager->AddMe(this, 1);
}

