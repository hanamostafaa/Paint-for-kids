#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	sound = pManager->getsound();

	pOut->PrintMessage("New Square: Click at center");

	//Read center and store in point P1
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		if (P1.y-50<UI.ToolBarHeight|| P1.y + 50> UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P1.y-50 < UI.ToolBarHeight|| P1.y+50>UI.height-UI.StatusBarHeight);


	SqrGfxInfo.isFilled = pManager->getfillstatus();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute(bool mode)
{
	if(!mode)
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	figSquare = new CSquare(P1, SqrGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(figSquare);
	if (sound)
		PlaySound(TEXT("sounds\\square.wav"), NULL, SND_ASYNC);
	pManager->AddMe(this);
}




void AddSqrAction::Undo() {
	pManager->DeleteFigure(figSquare);
}

void AddSqrAction::Redo() {
	pManager->AddFigure(figSquare);
	pManager->AddMe(this, 1);
}