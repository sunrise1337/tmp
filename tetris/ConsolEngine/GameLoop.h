#pragma once
#include "BaseApp.h"
#include "Field.h"
#include "Figure.h"
#include <conio.h>

class GameLoop : public BaseApp
{
private:
	Field *field;
	Figure *currentFigure;
	Figure *nextFigure;
	bool gameOver;

	void DrawField();
	void UpdateField(); // sync field and figure
	void ClearScreen();

	void DrawFigure();
	void DrawNextFigure();

public:
	GameLoop();
	~GameLoop();

	virtual void UpdateF(float deltaTime);
	virtual void KeyPressed(int btnCode);
	Figure *RandomFigure();
};

