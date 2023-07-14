#include "ToPlay.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
ToPlay::ToPlay(ApplicationManager* pApp) :Action(pApp)
{}
void ToPlay::Execute(bool mode)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if (pManager->getfigcount() > 0)
	{
		pOut->CreatePlayToolBar();
	}
	else
		pOut->PrintMessage("Draw before playing");


}
void ToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Playing Time!!");

}

