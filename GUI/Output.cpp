#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1310;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 46;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 5;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	UI.MenuItemWidth = 46;


	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Squar.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_DRAWCOLOR] = "images\\MenuItems\\Menu_Drawcolor.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\Menu_Sound.jpg";



	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_DRAG] = "images\\MenuItems\\Menu_Drag.jpg";

	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\Menu_Rec.jpg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\Menu_Stop.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_PlayRec.jpg";

	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";

	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_PlayMode.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	UI.MenuItemWidth = 100;

	string MenuItemImages2[PLAY_ITM_COUNT];


	MenuItemImages2[ITM_MODE1] = "images\\MenuItems\\Menu_Mode1.jpg";
	MenuItemImages2[ITM_MODE2] = "images\\MenuItems\\Menu_Mode2.jpg";
	MenuItemImages2[ITM_MODE3] = "images\\MenuItems\\Menu_Mode3.jpg";
	MenuItemImages2[ITM_DRAW] = "images\\MenuItems\\Menu_Draw.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->DrawImage("images\\MenuItems\\Menu_Empty.jpg", PLAY_ITM_COUNT * UI.MenuItemWidth, 0, UI.width, UI.ToolBarHeight);




	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawSQ(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x + 50, P1.y + 50, P1.x - 50, P1.y - 50, style);

}


void Output::DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	float R = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));

	pWind->DrawCircle(P1.x, P1.y, R, style);

}

void Output::DrawHexa(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,5 );
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int arrx[6], arry[6];
	arrx[0] = P1.x + 25;
	arry[0] = P1.y - 25 * sqrt(3);
	arrx[1] = P1.x + 50;
	arry[1] = P1.y;
	arrx[2] = arrx[0];
	arry[2] = P1.y + 25 * sqrt(3);
	arrx[5] = P1.x - 25;
	arry[5] = arry[0];
	arrx[4] = P1.x - 50;
	arry[4] = P1.y;
	arrx[3] = arrx[5];
	arry[3] = arry[2];




	pWind->DrawPolygon(arrx, arry, 6, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

void Output::reset()
{
	UI.DrawColor = BLUE;
	UI.FillColor = GREEN;
	UI.MsgColor = RED;
	UI.HighlightColor = MAGENTA;
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 5;
}
void Output::setCrntDrawColor(color draw) {
	UI.DrawColor = draw;
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::setCrntFillColor(color draw) {
	UI.FillColor = draw;
}

