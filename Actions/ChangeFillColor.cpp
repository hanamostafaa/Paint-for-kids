#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a filling color");
	 ActType = pManager->GetUserAction();
	pOut->ClearStatusBar();
}
void ChangeFillColor::Execute(bool mode)
{
	if(!mode)
	ReadActionParameters();
	
	Output* pOut = pManager->GetOutput();

	 FIG = pManager->GetSelectedFig();  //getting selected figure
	 
	if (FIG != NULL) //if there is a selected figure
	{
		isFilled = FIG->isFilled();
		if (isFilled) {
			lastColor = FIG->getfillcolor();
		}
		pOut->ClearStatusBar();

		if (pManager->ChngColor(ActType, UI.FillColor))
		{
			FIG->ChngFillClr(UI.FillColor);   //changing fill color
			FIG->SetFill(true);   //setting fill status with true
			FIG->SetSelected(0);   //unselecting the figure
			pManager->SetSelectedFig(NULL);
		}
	}
	pManager->AddMe(this);


}



void ChangeFillColor::Undo() {
	if (FIG == NULL) {
		return;
	}
	if (isFilled) {
		color temp = FIG->getfillcolor();
		FIG->ChngFillClr(lastColor);
		FIG->SetFill(true);
		lastColor = temp;
	}
	else {
		lastColor = FIG->getfillcolor();
		FIG->SetFill(false);
		pManager->UpdateInterface();
	}
}

void ChangeFillColor::Redo()
{
	if (FIG == NULL) {
		return;
	}
		color temp = FIG->getfillcolor();
		FIG->ChngFillClr(lastColor);
		FIG->SetFill(true);
		lastColor = temp;
		pManager->AddMe(this, 1);
	
}