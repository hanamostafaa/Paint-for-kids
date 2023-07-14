#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeDrawColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a drawing color");
	ActType = pManager->GetUserAction();
	pOut->ClearStatusBar();
}
void ChangeDrawColor::Execute(bool mode)
{
	if(!mode)
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();

	FIG = pManager->GetSelectedFig();

	if (FIG != NULL)
	{
		lastColor = FIG->getdrawcolo();
		if (pManager->ChngColor(ActType, UI.DrawColor))
		{
			FIG->ChngDrawClr(UI.DrawColor);
			FIG->SetSelected(0);
			pManager->SetSelectedFig(NULL);
		}
	}
	pManager->AddMe(this);

}




void ChangeDrawColor::Undo()
{
	if (FIG == NULL) {
		return;
	}
	color currentColor = FIG->getdrawcolo();
	FIG->ChngDrawClr(lastColor);
	lastColor = currentColor;
}

void ChangeDrawColor::Redo() {
	if (FIG == NULL) {
		return;
	}
	color currentColor = FIG->getdrawcolo();
	FIG->ChngDrawClr(lastColor);
	lastColor = currentColor;
	pManager->AddMe(this, 1);
}