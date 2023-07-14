#include"RedoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {

}
void RedoAction::ReadActionParameters() {
	pManager->GetOutput()->PrintMessage("Redo Last Action");
}

void RedoAction::Execute(bool mode ) {
	ReadActionParameters();
	Action* R = pManager->GetRaction();
	if (R != NULL)
		R->Redo();

}