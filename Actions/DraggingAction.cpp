#include "DraggingAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

DraggingAction::DraggingAction(ApplicationManager* pApp) :Action(pApp)
{}

void DraggingAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move selected figure by dragging");
	CFigure* MFIG = pManager->GetSelectedFig();
	while(!(pIn->ButtonState(P1.x, P1.y)))
	{
		if (pManager->GetFigure(P1.x, P1.y) == MFIG)
		while (pIn->ButtonState(P1.x, P1.y))
		{
			
			{
	     		MFIG->shift(P1);
				pManager->UpdateInterface();
			}
			Sleep(20);
				
			
		}
	}

	pOut->ClearStatusBar();

}
void DraggingAction::Execute(bool mode)
{
	Output* pOut = pManager->GetOutput();
	if (!mode&&pManager->GetSelectedFig()!=NULL)
	{
		ReadActionParameters();
	}
	else if (pManager->GetSelectedFig() == NULL)
		pOut->PrintMessage("error,select a figure first");
	else if (mode)
		pManager->GetSelectedFig()->shift(P1);
}


