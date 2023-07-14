#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	int ID;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
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

