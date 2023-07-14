#include "SelectOneAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectOneAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a figure: Click at any figure");
	pIn->GetPointClicked(P1.x, P1.y); //get point from user
	pOut->ClearStatusBar();

}
void SelectOneAction::Execute(bool mode)
{
	Output* pOut = pManager->GetOutput();
	if(!mode)
	ReadActionParameters();
	CFigure* FIG=pManager->GetFigure(P1.x, P1.y);
	if (FIG != NULL&&(FIG->IsSelected() == 0)) //if figure is not previously selected,select it
	{
		if (pManager->GetSelectedFig() != NULL)
		{
			(pManager->GetSelectedFig())->SetSelected(0);
		}
		pManager->SetSelectedFig(FIG);

		FIG->SetSelected(1);
		FIG->PrintInfo(pOut);
	}
	else if (FIG != NULL && (FIG->IsSelected()==1)) //unselect figure if it was selected
	{
		FIG->SetSelected(0);
		pManager->SetSelectedFig(NULL);
		Output* pOut = pManager->GetOutput();
		pOut->ClearStatusBar();
		
	}
	//ignore if point doesn't belong to any figure
}

