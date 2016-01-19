#pragma once
#include "BaseApp.h"
#include "Figure.h"

class Field
{
private:
	const unsigned int WIDTH;
	const unsigned int HEIGHT;
	wchar_t **field;
	wchar_t **miniField;

public:
	Field(int W, int H);
	~Field();

	void ClearField();
	void InitMiniField();
	void ClearLines(); // deletes full lines
	
	// methods for interaction figures and field
	bool CollisionCheck(Figure &f, bool &gameover);
	bool CanMoveLeft(Figure &f);
	bool CanMoveRight(Figure &f);
	bool CanRotate(Figure &f);

	//getters
	uint GetWidth(){ return WIDTH; }
	uint GetHeight(){ return HEIGHT; }
	wchar_t **GetField(){ return field; }
	wchar_t **GetMiniField(){ return miniField; }
};

