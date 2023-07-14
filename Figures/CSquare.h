#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	int ID;
public:
	CSquare();
	CSquare(Point,GfxInfo FigureGfxInfo);
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

