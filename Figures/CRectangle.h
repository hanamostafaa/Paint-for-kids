#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int ID;
	double length, width;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void PrintInfo(Output* pOut);
	virtual void Set_ID(int id);
	virtual void shift(Point P);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual Point GetCenter();

};

#endif