#include "ByTypeAndColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CSquare.h" 
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"


ByTypeAndColor::ByTypeAndColor(ApplicationManager* pApp) :Action(pApp)
{}
void ByTypeAndColor::Execute(bool mode)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->CanPlay()) //checking that there are colored figures
	{
		string s;
		CFigure* rand = pManager->getrandcolorfig();    //choosing random figure
		tobepicked = pManager->gettypeandcolorno(rand);   //number of figures matching the random

		//getting the color of the random figure
		if (rand->getfillcolor() == YELLOW)
			s = "Pick all Yellow";
		else if (rand->getfillcolor() == BLACK)
			s = "Pick all Black";
		else if (rand->getfillcolor() == BLUE)
			s = "Pick all Blue";
		else if (rand->getfillcolor() == ORANGE)
			s = "Pick all Orange";
		else if (rand->getfillcolor() == RED)
			s = "Pick all Red";
		else
			s = "Pick all Green";

		//getting the type of the random figure
		switch (rand->gettype())
		{
		case rectangle:
			s += " rectangles";
			break;
		case square:
			s += " squares";
			break;
		case circle:
			s += " circles";
			break;
		case triangle:
			s += " triangles";
			break;
		case hexagon:
			s += " hexagons";
			break;
		}
		pOut->PrintMessage(s);

		while (RightAns != tobepicked)   //kid keep picking till all right figures are picked
		{
			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight)
			{
				CFigure* picked = pManager->GetFigure(P.x, P.y);
				if (picked != NULL)
				{
					picked->SetHidden(true);   //hiding the picked figure
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
					if (dynamic_cast<CRectangle*>(picked) && rand->gettype() == rectangle && picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						print(true);
					}
					else if (dynamic_cast<CCircle*>(picked) && rand->gettype() == circle && picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						print(true);
					}
					else if (dynamic_cast<CHexagon*>(picked) && rand->gettype() == hexagon && picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						print(true);
					}
					else if (dynamic_cast<CTriangle*>(picked) && rand->gettype() == triangle && picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						print(true);
					}
					else if (dynamic_cast<CSquare*>(picked) && rand->gettype() == square && picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						print(true);
					}
					else
					{
						print(false);
					}
				}
			}
			else if (P.x < UI.MenuItemWidth * 3 && P.x> UI.MenuItemWidth * 2)  //restarting the game
			{
				pManager->unhideall();
				pManager->UpdateInterface();
				RightAns = 0;
				WrongAns = 0;
				pOut->PrintMessage(s);
			}
			else if (P.x < UI.MenuItemWidth * 4 && P.x>UI.MenuItemWidth * 3)  //ending the game and the play mode
			{
				ActionType pAct = TO_DRAW;
				RightAns = -1; //trying to break the condition
				pManager->ExecuteAction(pAct);
				break;
			}
			else
			{
				break;
			}
		}
		if (RightAns != -1)
		{
			pOut->PrintMessage("Game Over your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
			pManager->unhideall();
			pManager->UpdateInterface();
		}
	}
	else
		pOut->PrintMessage("Color first to play");

}

void ByTypeAndColor::ReadActionParameters()
{
	RightAns = 0;   //initializing all parameters
	WrongAns = 0;
	tobepicked = 0;
	sound = pManager->getsound();

}

void ByTypeAndColor::print(bool b)
{
	Output* pOut = pManager->GetOutput();

	if (b)  //printing answers
	{
		RightAns++;
		if (sound)
			PlaySound(TEXT("sounds\\goodjob.wav"), NULL, SND_ASYNC);
		pOut->PrintMessage(" YAY! your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));

	}
	else
	{
		WrongAns++;
		pOut->PrintMessage("OPS your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
	}

}
