#pragma once
#include "BaseApp.h"
#include <vector>
class Figure
{
public:
	enum FigureType { I, O, T, L, Z }; // tetromino types. Wikipedia

	struct CRD{
		float X;
		float Y;
	};
private:
	void GenerateFigure(const wchar_t t[4][4]); // memory alloc, push back figure to vector

	FigureType type;
	vector<wchar_t**> figures; // vector of figures, used for rotation
	wchar_t **currentFigure;
	uint currentFigureIndex;
	CRD pos;
	bool active; // true if figure is moving
	int speed;

public:
	Figure(FigureType type);
	Figure(const Figure &obj);
	~Figure();
	
	void InitVector();
	void Rotate();
	void MoveLeft();
	void MoveRight();
	void Move(float deltaTime);
	void FastFall();

	wchar_t **GetActualFigure() { return currentFigure; }
	CRD GetPos(){ return pos; }
	void SetPos(CRD c) { c = pos; }
	void SetActive(bool a){ active = a; }
	bool IsActive(){ return active; }
	FigureType GetType(){ return type; }
	uint GetCurrentFindex(){ return currentFigureIndex; }
};

