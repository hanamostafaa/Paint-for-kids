#include "DeleteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
DeleteAction::DeleteAction(ApplicationManager* pApp,bool b) :Action(pApp),sound(b)
{}
void DeleteAction::Execute(bool mode)
{
	ReadActionParameters();
	Fig=pManager->GetSelectedFig();
	if (Fig != NULL) {

		pManager->DeleteFigure(Fig);
		pManager->SetSelectedFig(NULL);
		Fig->SetSelected(false);
		pManager->UpdateInterface();
		if (sound)
			PlaySound(TEXT("sounds\\delete.wav"), NULL, SND_ASYNC);
	}
	pManager->AddMe(this);
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->CreateStatusBar();
	
}

void DeleteAction::Undo() {
	if (Fig != NULL) {
		pManager->AddFigure(Fig);
	}
	
}
void DeleteAction::Redo() {
	if (Fig != NULL) {
		pManager->DeleteFigure(Fig);
	}
	pManager->AddMe(this, 1);
}