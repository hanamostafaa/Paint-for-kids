#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp) {}

void SaveAction::ReadActionParameters() {
	Output* oPut = pManager->GetOutput();
	Input* iPut = pManager->GetInput();
	oPut->PrintMessage("Write save file name:");
	filename = iPut->GetSrting(oPut);
	filename.append(".txt");
	oPut->PrintMessage("Figures have been saved in " + filename);
}

void SaveAction::Execute(bool mode) {
	ReadActionParameters();
	ofstream fout(filename);
	pManager->SaveAll(fout);
	fout.close();
}
