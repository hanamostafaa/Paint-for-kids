#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

bool Input::ButtonState(int& x, int& y) const //return if mouse is clicked
{
	buttonstate b=pWind->GetButtonState(LEFT_BUTTON,x,y);
	if (b == BUTTON_UP)
		return false;
	else
		return true;
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQR: return DRAW_SQR;
			case ITM_HEXA:return DRAW_HEXA;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRI:return DRAW_TRIANGLE;

			case ITM_EXIT: return EXIT;
			case ITM_PLAY: return TO_PLAY;

			case ITM_CLEAR: return CLEAR;
			case ITM_DELETE: return DELET;
			case ITM_FILL:return FILL;
			case ITM_SELECT: return SELECT;

			case ITM_GREEN: return COLOR_GREEN;
			case ITM_ORANGE: return COLOR_ORANGE;
			case ITM_YELLOW: return COLOR_YELLOW;
			case ITM_BLACK: return COLOR_BLACK;
			case ITM_BLUE: return COLOR_BLUE;

			case ITM_LOAD:return LOAD;
			case ITM_RED: return COLOR_RED;
			case ITM_UNDO:return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SAVE: return TO_SAVE;
			case ITM_MOVE: return MOVE;
			case ITM_DRAG: return DRAG;
			case ITM_REC: return STARTREC;
			case ITM_STOP: return STOPREC;
			case ITM_PLAYREC: return PLAYREC;
			case ITM_DRAWCOLOR: return DRAWCOLOR;
			case ITM_SOUND: return SOUND;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_DRAW: return TO_DRAW;
			case ITM_MODE1: return MODE1;
			case ITM_MODE2: return MODE2;
			case ITM_MODE3: return MODE3;



			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
