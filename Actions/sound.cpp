#include "Sound.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
Sound::Sound(ApplicationManager* pApp) :Action(pApp)
{}
void Sound::Execute(bool mode)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getsound()) 
	{
		pOut->PrintMessage("sound off");
		pManager->setsound(false);
	}
	else
	{
		pOut->PrintMessage("sound on");
		pManager->setsound(true);
	}
}
void Sound::ReadActionParameters()
{

}