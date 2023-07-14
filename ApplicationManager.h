#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"
#include <fstream>
#include <iomanip>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int Count;
	Action* stored[20];

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Action* pLast;

	bool soundon;


	//Action* PlayActions[MaxActionCount];
	//int PlayActionCount;
	int Rindex;
	//Action* UndoActions[MaxActionCount];
	//int UndoActionCount;
	int Uindex;
	Action* LastArr[5];
	bool RECMODE;
	int i;

	bool playon;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void setplayon(bool b);
	bool getplayon();

	//setter and getter for selected figure
	void SetSelectedFig(CFigure* F);
	CFigure* GetSelectedFig() const;
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	bool getfillstatus();   //getter for filled or not filled

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	Action* GetLastAction() const; 
	Action** GetRecs() ;

	void ClearRec();
	int getfigcount() const;  //gets number of figures

	bool ChngColor(ActionType ActType, color& c);
	void del();  //deletes a figure from FigList
	void clear();   //clearing the FigList

	void setsound(bool b);
	bool getsound();


	//unhiding all figures
	void unhideall();

	//getting a random figure
	CFigure* getrandfig();
	CFigure* getrandcolorfig();

	//getting number of figures with the same qualities
	int gettypeno(CFigure* fig);
	int getcolorno(CFigure* fig);
	int gettypeandcolorno(CFigure* fig);

	//checking if the kid can pick by color
	bool CanPlay();
	void SaveAll(ofstream& fout);
	void ApplicationManager::LoadAll(ifstream& fin);

	int ApplicationManager::GetColorIndex(color& c);


	color ApplicationManager::getColorByIndex(int index);

	void ApplicationManager::DeleteFigure(CFigure* figure);
	void ClearUndoActions();
	
	void setRECMODE(bool b);
	void AddMe(Action* LAST, bool isredo = 0);
	Action* GetUaction(); //get action to be undone
	Action* GetRaction();
};

#endif