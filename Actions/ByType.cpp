#include "ByType.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"


ByType::ByType(ApplicationManager* pApp) :Action(pApp)
{}
void ByType::Execute(bool mode)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	CFigure* rand = pManager->getrandfig();   //getting a random figure
	tobepicked = pManager->gettypeno(rand);   //number of figures matching the random figure
	string s;

	//getting type of the random figure
	switch (rand->gettype())
	{
	case rectangle:
		s = "Pick all rectangles";
		break;
	case square:
		s = "Pick all squares";
		break;
	case circle:
		s = "Pick all circles";
		break;
	case triangle:
		s = "Pick all triangles";
		break;
	case hexagon:
		s = "Pick all hexagons";
		break;
	}

	pOut->PrintMessage(s);

	while (RightAns != tobepicked)  //kid keep picking till all right figures are picked
	{
		pIn->GetPointClicked(P.x, P.y);
		if (P.y > UI.ToolBarHeight)
		{
			CFigure* picked = pManager->GetFigure(P.x, P.y);
			if (picked != NULL)
			{
				picked->SetHidden(true);   //hiding the figure
				pOut->ClearDrawArea();
				pManager->UpdateInterface();
				if (dynamic_cast<CRectangle*>(picked) && rand->gettype() == rectangle)
				{
					print(true);
				}
				else if (dynamic_cast<CCircle*>(picked) && rand->gettype() == circle)
				{
					print(true);
				}
				else if (dynamic_cast<CHexagon*>(picked) && rand->gettype() == hexagon)
				{
					print(true);
				}
				else if (dynamic_cast<CTriangle*>(picked) && rand->gettype() == triangle)
				{
					print(true);
				}
				else if (dynamic_cast<CSquare*>(picked) && rand->gettype() == square)
				{
					print(true);
				}
				else
				{
					print(false);
				}
			}
		}
		else if (P.x < UI.MenuItemWidth * 1 && P.x>0)  //restarting the game
		{
			pManager->unhideall();
			pManager->UpdateInterface();
			RightAns = 0;
			WrongAns = 0;
			pOut->PrintMessage(s);
		}
		else if (P.x < UI.MenuItemWidth * 4 && P.x>UI.MenuItemWidth * 3)  //ending and going to draw mode
		{
			ActionType pAct = TO_DRAW;
			RightAns = -1;
			pManager->ExecuteAction(pAct);
			break;
		}
		else
		{
			break;  //ending the game
		}
	}
	if (RightAns != -1)
	{
		pOut->PrintMessage("Game Over your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
		if(WrongAns>RightAns)
			if (sound)
				PlaySound(TEXT("sounds\\sadgame.wav"), NULL, SND_ASYNC);
		pManager->unhideall();
		pManager->UpdateInterface();
	}

}

void ByType::ReadActionParameters()
{
	RightAns = 0;    //initializing all parameters
	WrongAns = 0;
	tobepicked = 0;
	sound = pManager->getsound();
}

void ByType::print(bool b)
{
	Output* pOut = pManager->GetOutput();

	if (b)   //printing answers
	{
		if (sound)
			PlaySound(TEXT("sounds\\excellent.wav"), NULL, SND_ASYNC);
		RightAns++;
		pOut->PrintMessage(" YAY! your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));

	}
	else
	{
		WrongAns++;
		pOut->PrintMessage("OPS your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
	}

}
