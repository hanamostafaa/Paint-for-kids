#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	sound = pManager->getsound();
	//Read center and store in point P1
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		//validate if the point is in draw area
		if (P1.y < (UI.ToolBarHeight) || P1.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");
		
	} while (P1.y <(UI.ToolBarHeight) || P1.y>UI.height - UI.StatusBarHeight);

	pOut->PrintMessage("New Circle: Click at point on circle");

	//Read 2nd corner and store in point P2
	do
	{
		pIn->GetPointClicked(P2.x, P2.y);
		//validate P2
		if (P2.y < (UI.ToolBarHeight) || P2.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P2.y < (UI.ToolBarHeight)||P2.y>UI.height-UI.StatusBarHeight);

	CircGfxInfo.isFilled = pManager->getfillstatus();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute(bool mode)
{
	if(!mode) //if recording mode is false(the default value)
	//This action needs to read some parameters first
	ReadActionParameters();
	//Create a circle with the parameters read from the user
	 C = new CCircle(P1, P2, CircGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
	if (sound)
		PlaySound(TEXT("sounds\\circle.wav"), NULL, SND_ASYNC);
	pManager->AddMe(this);

}

void AddCircAction::Undo() {
	pManager->DeleteFigure(C);
}
void AddCircAction::Redo() {
	pManager->AddFigure(C);
	pManager->AddMe(this,1);
}