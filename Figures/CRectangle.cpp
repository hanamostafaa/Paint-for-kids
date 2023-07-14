#include "CRectangle.h"
#include<fstream>
CRectangle::CRectangle() : CFigure(GfxInfo())
{

}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	length = abs(P1.y - P2.y);
	width = abs(P1.x - P2.x);
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::Belong(int x1, int y1)
{
	if (Corner1.x > Corner2.x)
	{
		if (x1>Corner1.x || x1<Corner2.x)
			return false;
	}
	else {
		if (x1 < Corner1.x || x1 > Corner2.x)
			return false;
	}
	if (Corner1.y > Corner2.y)
	{
		if (y1 > Corner1.y || y1 < Corner2.y)
			return false;
	}
	else {
		if (y1 < Corner1.y || y1 > Corner2.y)
			return false;
	}
	return true;
}

void CRectangle::PrintInfo(Output* pOut)
{
	double len = abs(Corner1.x - Corner2.x);
	double width = abs(Corner1.y - Corner2.y);

	pOut->PrintMessage("rectangle_ID:"+to_string(ID)+" corner1:"+to_string(Corner1.x)+" "+to_string(Corner1.y) + " corner2:" + to_string(Corner2.x) + " " + to_string(Corner2.y) + "length" + to_string(len) + " " + to_string(width));
}

void CRectangle::Set_ID(int id)
{
	ID = id;
}
 Point CRectangle::GetCenter() {
	 Point center;
	 center.x = (Corner1.x + Corner2.x) / 2.0;
	 center.y = (Corner1.y + Corner2.y) / 2.0;
	 
	 return center;
}
void CRectangle:: shift(Point P)
{
	if (Corner1.x > Corner2.x) 
	{
		Corner1.x = P.x + (width / 2);
		Corner2.x = P.x - (width / 2);
	}
	else if (Corner1.x < Corner2.x)
	{
		Corner2.x = P.x + (width / 2);
		Corner1.x = P.x - (width / 2);
    }
	if (Corner1.y > Corner2.y)
	{
		Corner1.y = P.y + (length / 2);
		Corner2.y = P.y - (length / 2);
	}
	else if (Corner1.y < Corner2.y)
	{
		Corner2.y = P.y + (length / 2);
		Corner1.y = P.y - (length / 2);
	}

}
void CRectangle::Save(ofstream& fout) {
	int fillColor = FigGfxInfo.isFilled ? GetColorIndex(FigGfxInfo.FillClr) : -1;
	fout << rectangle << setw(8) << ID << setw(8) << Corner1.x << setw(8) << Corner1.y << setw(8) << Corner2.x << setw(8) << Corner2.y
		<< setw(8) << GetColorIndex(FigGfxInfo.DrawClr) << setw(8) << fillColor << endl;
}

void CRectangle::Load(ifstream& fin) {
	int  draw, fill;
	fin >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> draw >> fill;
	FigGfxInfo.DrawClr = getColorByIndex(draw);
	if (fill != -1) {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByIndex(fill);
	}
	else {
		FigGfxInfo.isFilled = false;
	}
}
