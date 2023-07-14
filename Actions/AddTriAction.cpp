#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	sound = pManager->getsound();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		if (P1.y <UI.ToolBarHeight|| P1.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P1.y<UI.ToolBarHeight|| P1.y>UI.height - UI.StatusBarHeight);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	do
	{
		pIn->GetPointClicked(P2.x, P2.y);
		if (P2.y< UI.ToolBarHeight|| P2.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P2.y < UI.ToolBarHeight||P2.y>UI.height - UI.StatusBarHeight);


	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	do
	{
		pIn->GetPointClicked(P3.x, P3.y);
		if (P3.y <UI.ToolBarHeight|| P3.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P3.y < UI.ToolBarHeight|| P3.y>UI.height - UI.StatusBarHeight);


	TriGfxInfo.isFilled = pManager->getfillstatus();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute(bool mode)
{
	if(!mode)
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	figTriangle= new CTriangle(P1, P2,P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(figTriangle);
	if (sound)
		PlaySound(TEXT("sounds\\triangle.wav"), NULL, SND_ASYNC);
	pManager->AddMe(this);
}





void AddTriAction::Undo() {
	pManager->DeleteFigure(figTriangle);
}

void AddTriAction::Redo() {
	pManager->AddFigure(figTriangle);
	pManager->AddMe(this, 1);
}