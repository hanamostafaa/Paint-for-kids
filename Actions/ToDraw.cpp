#include "ToDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
ToDraw::ToDraw(ApplicationManager* pApp) :Action(pApp)
{}
void ToDraw::Execute(bool mode)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->unhideall();
	pManager->UpdateInterface();
	pOut->CreateDrawToolBar();

}
void ToDraw::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Back ro Draw Mode");

}
