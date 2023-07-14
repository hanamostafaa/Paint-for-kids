#include "ByColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

ByColor::ByColor(ApplicationManager* pApp) :Action(pApp)
{}

void ByColor::ReadActionParameters()
{
	RightAns = 0;   //initializing all parameters
	WrongAns = 0;
	tobepicked = 0;
	sound = pManager->getsound();

}
void ByColor::Execute(bool mode)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->CanPlay())  //checking that there are colored figures
	{
		CFigure* rand = pManager->getrandcolorfig();    //choosing a random figure
		tobepicked = pManager->getcolorno(rand);    //getting number of figures with the same color as the random figure
		string s;

		//getting random figure color
		if (rand->getfillcolor() == YELLOW)
			s = "Pick all Yellow figures";
		else if (rand->getfillcolor() == BLACK)
			s = "Pick all Black figures";
		else if (rand->getfillcolor() == BLUE)
			s = "Pick all Blue figures";
		else if (rand->getfillcolor() == ORANGE)
			s = "Pick all Orange figures";
		else if (rand->getfillcolor() == RED)
			s = "Pick all Red figures";
		else
			s = "Pick all Green figures";
		pOut->PrintMessage(s);

		while (RightAns != tobepicked)    //kid keep picking till all right figures are picked
		{
			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight)
			{
				CFigure* picked = pManager->GetFigure(P.x, P.y);
				if (picked != NULL)
				{
					picked->SetHidden(true);  //hiding the figure
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
					if (picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())  //checking if it match the chosen figure
					{
						if (sound)
							PlaySound(TEXT("sounds\\goodjob.wav"), NULL, SND_ASYNC);
						RightAns++;
						pOut->PrintMessage(" YAY! your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
					}
					else
					{
						WrongAns++;
						pOut->PrintMessage("OPS your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
					}
				}
			}
			else if (P.x < UI.MenuItemWidth * 2 && P.x>UI.MenuItemWidth * 1)  //restarting the game
			{
				pManager->unhideall();
				pManager->UpdateInterface();
				RightAns = 0;
				WrongAns = 0;
				pOut->PrintMessage(s);
			}
			else if (P.x < UI.MenuItemWidth * 4 && P.x>UI.MenuItemWidth * 3)  //going back to draw mode
			{
				ActionType pAct = TO_DRAW;
				RightAns = -1;
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

