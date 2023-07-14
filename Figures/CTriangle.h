#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	int ID;
public:
	CTriangle();
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1,int y1);
	virtual void PrintInfo(Output* pOut);
	virtual void Set_ID(int id);
	virtual void shift(Point P);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual Point GetCenter();
};

#endif

