#include "CFigure.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Hidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

bool CFigure::isFilled()
{
	return FigGfxInfo.isFilled;
}
void CFigure::SetFill(bool b)
{
	FigGfxInfo.isFilled = b;
}
void CFigure::SetHidden(bool b)
{
	Hidden = b;
}
bool CFigure::IsHidden()
{
	return Hidden;
}
color CFigure::getfillcolor()
{
	return FigGfxInfo.FillClr;
}
color CFigure::getdrawcolo() {
	return FigGfxInfo.DrawClr;
}
type CFigure::gettype()
{
	if (dynamic_cast<CTriangle*>(this))
		return triangle;
	if (dynamic_cast<CCircle*>(this))
		return circle;
	if (dynamic_cast<CSquare*>(this))
		return square;
	if (dynamic_cast<CHexagon*>(this))
		return hexagon;
	if (dynamic_cast<CRectangle*>(this))
		return rectangle;
}



