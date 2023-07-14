#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions/AddCircAction.h"
#include"Actions/AddSqrAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/AddTriAction.h"
#include"Actions/SelectOneAction.h"
#include"Actions/DeleteAction.h"
#include"Actions/MoveAction.h"
#include"Actions/DraggingAction.h"
#include"Actions/StartRecAction.h"
#include"Actions/PlayRecAction.h"
#include"Actions/ClearAll.h"
#include"Actions/ChangeDrawColor.h"
#include"Actions/ChangeFillColor.h"
#include"Actions/ToDraw.h"
#include"Actions/ToPlay.h"
#include"Actions/ByType.h"
#include"Actions/ByColor.h"
#include"Actions/ByTypeAndColor.h"
#include"Actions/LoadAction.h"
#include"Actions/SaveAction.h"
#include"Actions/Sound.h"
#include<fstream>
#include"Actions/UndoAction.h"
#include"Actions/RedoAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	Uindex = -1;
	Rindex = -1;
	i = 0;

	RECMODE = false;
	playon = false;

	SelectedFig = NULL;
	Count = 0; //to set the fig id
	FigCount = 0; //actual figure count
	pLast = NULL; //intializing pointer to the last action
		
	//Create an array of figure pointers and set them to NULL		
	for(int j=0; j<MaxFigCount; j++)
		FigList[j] = NULL;	

	for (int j = 0; j < 20; j++)
		stored[j] = NULL;

	soundon = true;
	for (int j = 0; j < 5; j++)
		LastArr[j] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	bool clearAction = true;
	bool flag = 0;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		//Add New Rectangle
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			flag = 1;
			break;
		//Add New Circle
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			flag = 1;
			break;

		//Add New Hexagon
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			flag = 1;
            break;

		//Add new square
		case DRAW_SQR:
			pAct = new AddSqrAction(this);
			flag = 1;
        	break;

		//Add new triangle
		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			flag = 1;
			break;

		//Select a figure
		case SELECT:
			pAct = new SelectOneAction(this);
			flag = 1;
			break;

       //Delete a figure
	   case DELET:
		    pAct = new DeleteAction(this,soundon);
			flag = 1;
		    break;

	   //Move selected figure
	   case MOVE:
			pAct = new MoveAction(this);
			flag = 1;

			break;

	  //move selected figure by dragging
	   case DRAG:
		   pAct = new DraggingAction(this);
		   break;

	   //Start Recording
	   case STARTREC:
		   i = 0;
			pAct = new StartRecAction(this);
			break;

	   //Play recording
	   case PLAYREC:
			pAct = new PlayRecAction(this);
			playon = true;
			break;

	  //clear all action
	   case CLEAR:
		   pAct = new ClearAll(this);
		   flag = 1;
		   break;
	   case DRAWCOLOR:
		   pAct = new ChangeDrawColor(this);
		   flag = 1;
		   break;
	   case FILL:
		   pAct = new ChangeFillColor(this);
		   flag = 1;
		   break;
	   case TO_DRAW:
		   pAct = new ToDraw(this);
		   break;
	   case TO_PLAY:
		   pAct = new ToPlay(this);
		   break;
	   case MODE1:
		   pAct = new ByType(this);
		   break;
	   case MODE2:
		   pAct = new ByColor(this);
		   break;
	   case MODE3:
		   pAct = new ByTypeAndColor(this);
		   break;
	   case TO_SAVE:
		   pAct = new SaveAction(this);
		   break;
	   case LOAD:
		   pAct = new LoadAction(this);
		   break;
	   case SOUND:
		   pAct = new Sound(this);
		   break;
	   case UNDO:
		   pAct = new UndoAction(this);
		   clearAction = false;
		   flag = 1;
		   break;
	   case REDO:
		   pAct = new RedoAction(this);
		   clearAction = false;
		   flag = 1;
		   break;
	   case STOPREC:
		   pOut->PrintMessage("recording stopped");
		   RECMODE = 0;
		   if (i < 20);
		   {
			   for (int j = i; j < 20; j++)
				   stored[i] = NULL;
		   }
		   i = 0;
		   break;
	   



       case EXIT:
		   for (int i = 0; i < 5; i++)
			   if(LastArr[i]!=NULL)
			   {
				   for (int j = 0; j < 20; j++)
				   {
					   if (stored[j] == LastArr[i])
						   stored[j] = NULL;
				   }

				   delete LastArr[i];
				   LastArr[i] = NULL;
			   }
		   for (int i = 0; i < 20; i++)
			   if (stored[i] != NULL)
			   {
				   delete stored[i];
				   stored[i] = NULL;
			   }
		
		   pOut->PrintMessage("Exiting...Goodbye");
		   if (soundon)
			   PlaySound(TEXT("sounds\\goodbye.wav"), NULL, SND_ASYNC);
		   Sleep(2000);
			///create ExitAction here
			
			break;
		
	   case STATUS:	//a click on the status bar ==> no action
			return;
	}
	if (RECMODE&&i<20&&flag)
	{
		stored[i] = pAct;
		i++;
	}
	pLast = pAct; //store last action in pLast
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		
		//if(!RECMODE)
		//delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
bool ApplicationManager::ChngColor(ActionType ActType, color& c)
{
	switch (ActType)
	{
	case COLOR_GREEN:
		c = GREEN;
		return true;
	case COLOR_BLACK:
		c = BLACK;
		return true;
	case COLOR_BLUE:
		c = BLUE;
		return true;
	case COLOR_ORANGE:
		c = ORANGE;
		return true;
	case COLOR_RED:
		c = RED;
		return true;
	case COLOR_YELLOW:
		c = YELLOW;
		return true;
	}
	return false;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		Count++;
		FigList[FigCount++] = pFig;
		FigList[FigCount - 1]->Set_ID(Count);
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	bool flag=0;
	for (int i = 0; i < FigCount; i++)
	{
		flag=FigList[i]->Belong(x, y);
		if (flag)
			return FigList[i];
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	return NULL;
}
int ApplicationManager::getfigcount() const
{
	return FigCount;
}

Action** ApplicationManager::GetRecs() //return recordings to be played
{
	return stored;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if(!FigList[i]->IsHidden())
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
Action* ApplicationManager::GetLastAction() const
{
	return pLast; //return pointer to the last action's object
}


////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

//////////////////////////////
//make selectedfig points to given figure
void ApplicationManager::SetSelectedFig(CFigure* F)
{
	SelectedFig = F;
}

//return a pointer to the selected figure
CFigure* ApplicationManager::GetSelectedFig() const 
{
	return SelectedFig;
}

//////////////////////////////
void ApplicationManager::del() //remove deleted figure from figlist
{
	if (SelectedFig != NULL)
	{
		for (int i = 0; i < FigCount; i++)
		{
			if ((FigList[i]) == SelectedFig)
			{
				delete SelectedFig;
				SelectedFig = NULL;
				pOut->ClearStatusBar();
				FigList[i] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
				FigCount--;
				break;
			}
		}
	}
}
void ApplicationManager::clear()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
	}
	FigCount = 0;
	pLast = NULL;
}

void ApplicationManager::ClearRec()
{
	for (int i = 0; i < 20; i++)
		if (stored[i] != NULL)
		{
			for (int j = 0; j < 5; j++)
			{
				if (LastArr[j] == stored[i])
					LastArr[j] = NULL;
			}
			delete stored[i];
			stored[i] = NULL;
		}
}

//checking if any figure is filled 
bool ApplicationManager::getfillstatus()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isFilled())
			return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}

//unhiding all figures
void ApplicationManager::unhideall()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsHidden())
			FigList[i]->SetHidden(0);
	}
}

//getting a random figure
CFigure* ApplicationManager::getrandfig()
{
	int n = rand() % FigCount;  //choosing a random valid number 
	return FigList[n];
}

//getting a random filled figure
CFigure* ApplicationManager::getrandcolorfig()
{
	int n = rand() % FigCount;  //choosing a random valid number 
	while (!FigList[n]->isFilled())  //looping till a filled figure is found
		n = rand() % FigCount;

	return FigList[n];
}

//getting number of figures with the same color
int ApplicationManager::getcolorno(CFigure* fig)
{
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getfillcolor() == fig->getfillcolor())
			n++;
	}
	return n;
}

//getting number of figures with the same type 
int ApplicationManager::gettypeno(CFigure* fig)
{
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->gettype() == fig->gettype())
			n++;
	}
	return n;
}

//getting number of figures with the same type and color
int ApplicationManager::gettypeandcolorno(CFigure* fig)
{
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->gettype() == fig->gettype() && FigList[i]->getfillcolor() == fig->getfillcolor())
			n++;
	}
	return n;
}

//checking if there are filled figures to play with
bool ApplicationManager::CanPlay()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isFilled())
			return true;
	}
	return false;
}


void ApplicationManager::setsound(bool b)
{
	soundon = b;
}
bool ApplicationManager::getsound()
{
	return soundon;
}
void ApplicationManager::SaveAll(ofstream& fout) {
	fout << GetColorIndex((pOut->getCrntDrawColor())) << setw(8) << GetColorIndex((pOut->getCrntFillColor())) << endl;
	fout << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(fout);
	}
}
void ApplicationManager::LoadAll(ifstream& fin) {
	clear();
	FigCount = 0;
	int drawIndex, fillIndex;

}

int ApplicationManager::GetColorIndex(color& c) {
	if (c == RED) {
		return 1;
	}
	else if (c == GREEN) {
		return 2;
	}
	else if (c == BLUE) {
		return 3;
	}
	else if (c == YELLOW) {
		return 4;
	}
	else if (c == ORANGE) {
		return 5;
	}
	else if (c == BLACK) {
		return 6;
	}
	else {
		return -1;
	}
}


color ApplicationManager::getColorByIndex(int index) {
	if (index == 1) {
		return RED;
	}
	else if (index == 2) {
		return GREEN;
	}
	else if (index == 3) {
		return BLUE;
	}
	else if (index == 4) {
		return YELLOW;
	}
	else if (index == 5) {
		return ORANGE;
	}
	else if (index == 6) {
		return BLACK;
	}
	else {
		return WHITE;
	}
}
void ApplicationManager::DeleteFigure(CFigure* figure) {
	GetOutput()->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if ((FigList[i]) == figure)
		{
			FigList[i] = NULL;
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			break;
		}
	}
	UpdateInterface();
}

void ApplicationManager:: ClearUndoActions() {
	for (int i = 0; i < 5; i++) 
		if(LastArr[i]!=NULL)
		{
			delete LastArr[i];
			LastArr[i] = NULL;
		}
	Uindex = -1;
}

void ApplicationManager:: setRECMODE(bool b) { RECMODE = b; } //turn on recording mode
void ApplicationManager:: AddMe(Action* LAST, bool isredo )
{
    Uindex++;
	if (Uindex == 5)
	{
		for (int j = 0; j < 4; j++)
			LastArr[j] = LastArr[j + 1];
		Uindex = 4;
	}
	if (!isredo) 
	{
		LastArr[Uindex] = LAST;
		Rindex = -1;
	}
	else if(isredo)
	{
		LastArr[Rindex - 1] = LAST;
		Uindex = Rindex - 1;
	}
	
}
Action* ApplicationManager:: GetUaction() {

	if (Uindex >= 0 && LastArr[Uindex] != NULL)
	{
		Rindex = Uindex;
		return LastArr[Uindex--];
	}
	return NULL;
}
Action* ApplicationManager:: GetRaction()
{
	if (Rindex < 5 && Rindex >= Uindex && Rindex >= 0)
	{
		return LastArr[Rindex++];
	}
	return NULL;
}

void ApplicationManager::setplayon(bool b)
{
	playon = b;
}
bool ApplicationManager::getplayon()
{
	return playon;
}