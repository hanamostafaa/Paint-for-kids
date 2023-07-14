#include "PlayRecAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include"ClearAll.h"

PlayRecAction::PlayRecAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayRecAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Play Recording");
	Sleep(1000);
	pOut->ClearStatusBar();

}
void PlayRecAction::Execute(bool mode)
{
	pManager->ExecuteAction(CLEAR);
	ReadActionParameters();

	//get recorded actions from application manager
	recorded=pManager->GetRecs();
	int i = 0; 
	while(i<20&&recorded[i]!=NULL) //execute recoded actions
	{
		recorded[i]->Execute(1);
		i++;
		pManager->UpdateInterface();
		Sleep(1000);
	}
	pManager->setplayon(false);
}
 PlayRecAction::~PlayRecAction() {
	 for (int i = 0; i < 20; i++)
		 if (recorded[i] != NULL)
		 {
			delete recorded[i];
			 recorded[i] = NULL;
		 }
}
