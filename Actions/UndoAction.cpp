#include "UndoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include "..\DefS.h"
UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp) {}
void UndoAction::ReadActionParameters() 
{
	pManager->GetOutput()->PrintMessage("Undo Last Action");
}
void UndoAction::Execute(bool mode ) 
{
	ReadActionParameters();
	Action* U = pManager->GetUaction();
	if (U != NULL)
		U->Undo();
}