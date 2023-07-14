#include "StartRecAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\DefS.h"

StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp)
{}

void StartRecAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Recording started");
	Sleep(1000);
	pOut->ClearStatusBar();

}
void StartRecAction::Execute(bool mode)
{
	Output* pOut = pManager->GetOutput();
	if ((pManager->getfigcount()) == 0)
	{
		ReadActionParameters();
		pManager->setRECMODE(1); //start storing actions in app manager
			
	}
	else  //if the user clicked start rec NOT after clear all or beginning,print error message
	{
		Output* pOut=pManager->GetOutput();
		pOut->PrintMessage("error ,can't start recording.click anywhere to continue");
		Input* pIn = pManager->GetInput();
		Point P;
		pIn->GetPointClicked(P.x, P.y);
		pOut->ClearStatusBar();
		
	}
}



