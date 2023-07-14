#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	sound = pManager->getsound();

	pOut->PrintMessage("New Hexagon: Click at center");

	//Read center and store in point P1
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		if (P1.y - 25 * sqrt(3) < UI.ToolBarHeight || (P1.y + 25 * sqrt(3) > UI.height - UI.StatusBarHeight))
			pOut->PrintMessage("invalid point click again");

	} while (P1.y-25*sqrt(3) < UI.ToolBarHeight|| (P1.y+25 * sqrt(3) > UI.height-UI.StatusBarHeight));//check if point is out of boundaries

	HexaGfxInfo.isFilled = pManager->getfillstatus();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute(bool mode)
{
	if(!mode)
	//This action needs to read some parameters first
	ReadActionParameters();
	//if (mode)
		//pManager->setlastaction(this);

	//Create a Hexagon with the parameters read from the user
	figHexagon= new CHexagon(P1, HexaGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(figHexagon);
	if (sound)
		PlaySound(TEXT("sounds\\hexagon.wav"), NULL, SND_ASYNC);
	pManager->AddMe(this);
}


void AddHexaAction::Undo() {
	pManager->DeleteFigure(figHexagon);
}

void AddHexaAction::Redo() {
	pManager->AddFigure(figHexagon);
	pManager->AddMe(this, 1);
}