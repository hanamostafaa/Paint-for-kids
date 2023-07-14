#ifndef CCIRC_H
#define CCIRC_H



#include "CFigure.h"
class CCircle:public CFigure
{
private:
	Point center;
	Point p2;
	double rsquare;
	int ID;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void PrintInfo(Output* pOut);
	virtual void Set_ID(int id);
	virtual void shift(Point P);
	virtual Point GetCenter();

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};
#endif

