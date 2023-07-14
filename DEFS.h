#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,
	DRAW_SQR,
	DRAW_HEXA,
	DRAW_TRIANGLE,
	COLOR_BLACK,
	COLOR_RED,
	COLOR_ORANGE,
	COLOR_YELLOW,
	COLOR_BLUE,
	COLOR_GREEN,
	MOVE,
	DRAG,
	STARTREC,
	STOPREC,
	PLAYREC,
	SELECT,
	MODE1,
	MODE2,
	MODE3,
	SOUND,
	LOAD,
	TO_SAVE,
	CLEAR,
	DELET,
	DRAWCOLOR,
	FILL,
	UNDO,
	REDO,
	



	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif