#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <iomanip>
enum type { rectangle, circle, square, hexagon, triangle };

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool Hidden;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color


	///Decide the parameters that you should pass to each function	
	virtual bool Belong(int x1, int y1) = 0; //check if the passed point lies inside the figure


	virtual void PrintInfo(Output* pOut) = 0;//print all figure info on the status bar
	virtual void Set_ID(int id)=0;	//set id of figure

	virtual void shift(Point P)=0; //shift coordinates of figure
	bool isFilled();
	void SetFill(bool b);
	void SetHidden(bool b);
	bool IsHidden();
	type gettype();
	color getfillcolor();
	color getdrawcolo();
	virtual Point GetCenter() = 0;
	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	int GetColorIndex(color& c) {
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
	color getColorByIndex(int index) {
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
};

#endif