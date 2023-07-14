#include "CCircle.h"
#include<fstream>
using namespace std;
CCircle::CCircle() : CFigure(GfxInfo())
{

}
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	p2 = P2;
	rsquare = (center.x - p2.x) * (center.x - p2.x) + (center.y - p2.y) * (center.y - p2.y);
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawCircle(center, p2, FigGfxInfo, Selected);
}
bool CCircle::Belong(int x1, int y1)
{
	double d = (center.x - x1) * (center.x - x1) + (center.y - y1) * (center.y - y1);
	
	if (d > rsquare)
		return false;
	return true;
}
void CCircle::PrintInfo(Output* pOut) 
{
	pOut->PrintMessage("CIRCLE_ID: "+to_string(ID) + " Center:" + to_string(center.x) + " " + to_string(center.y) + " radius = " + to_string(sqrt(rsquare)));

}

void CCircle::Set_ID(int id)
{
	ID = id;
}

Point CCircle::GetCenter() {
	return center;
}
void CCircle::shift(Point P) //shift points of the circle
{

	center = P;
	p2.x = center.x;
	p2.y = center.y +sqrt(rsquare);

}
void CCircle::Save(ofstream& fout) {
	int fillColor = FigGfxInfo.isFilled ? GetColorIndex(FigGfxInfo.FillClr) : -1;
	fout << circle << setw(8) << ID << setw(8) << center.x << setw(8) << center.y << setw(8) << p2.x << setw(8) << p2.y
		<< setw(8) << GetColorIndex(FigGfxInfo.DrawClr) << setw(8) << fillColor << endl;
}

void CCircle::Load(ifstream& Infile) {
	int  draw, fill;
	double radius;
	Infile >> ID >> center.x >> center.y >> p2.x >> p2.y >> draw >> fill;
	FigGfxInfo.DrawClr = getColorByIndex(draw);
	if (fill != -1) {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByIndex(fill);
	}
	else {
		FigGfxInfo.isFilled = false;
	}
}


