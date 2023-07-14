#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	sound = pManager->getsound();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		if (P1.y<UI.ToolBarHeight|| P1.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P1.y<UI.ToolBarHeight|| P1.y>UI.height - UI.StatusBarHeight);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	do
	{
		pIn->GetPointClicked(P2.x, P2.y);
		if (P2.y <UI.ToolBarHeight||P2.y>UI.height - UI.StatusBarHeight)
			pOut->PrintMessage("invalid point click again");

	} while (P2.y < UI.ToolBarHeight||P2.y>UI.height-UI.StatusBarHeight);

	RectGfxInfo.isFilled = pManager->getfillstatus();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute(bool mode) 
{
	if(!mode)
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	figRectangle =new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(figRectangle);
	if (sound)
		PlaySound(TEXT("sounds\\rectangle.wav"), NULL, SND_ASYNC);
	pManager->AddMe(this);
}



void AddRectAction::Undo() {
	pManager->DeleteFigure(figRectangle);
}

void AddRectAction::Redo() {
	pManager->AddFigure(figRectangle);
	pManager->AddMe(this, 1);
}