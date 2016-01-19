#include "Figure.h"

Figure::Figure(const Figure &obj)
{
	type = obj.type;
	InitVector();
	currentFigure = obj.currentFigure;
	currentFigureIndex = obj.currentFigureIndex;
	pos = obj.pos;
	active = obj.active;
	speed = obj.speed;
}

Figure::Figure(FigureType type) : type(type)
{
	switch (type)
	{
	case Figure::I:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'*', L'.', L'.',
						  L'.', L'*', L'.', L'.',
						  L'.', L'*', L'.', L'.',
						  L'.', L'*', L'.', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'*', L'*',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);

					  break;
	}
	case Figure::O:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'*', L'*', L'.',
					  };

					  GenerateFigure(t1);
			
					  break;
	}	
	case Figure::T:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'*', L'.',
						  L'.', L'*', L'.', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'*', L'.', L'.', L'.',
						  L'*', L'*', L'.', L'.',
						  L'*', L'.', L'.', L'.',
					  };

					  const wchar_t t3[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'*', L'.', L'.',
						  L'*', L'*', L'*', L'.',
					  };

					  const wchar_t t4[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'*', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'.', L'*', L'.',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);
					  GenerateFigure(t3);
					  GenerateFigure(t4);

					  break;
	}
	case Figure::L:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'*', L'.',
						  L'*', L'.', L'.', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'*', L'.', L'.', L'.',
						  L'*', L'.', L'.', L'.',
						  L'*', L'*', L'.', L'.',
					  };

					  const wchar_t t3[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'*', L'.',
						  L'*', L'*', L'*', L'.',
					  };

					  const wchar_t t4[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'.', L'*', L'.',
						  L'.', L'.', L'*', L'.',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);
					  GenerateFigure(t3);
					  GenerateFigure(t4);

					  break;
	}
	case Figure::Z:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'.', L'.',
						  L'.', L'*', L'*', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'*', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'*', L'.', L'.',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);

					  break;
	}
	}

	speed = 2;
	active = true;
	currentFigureIndex = 0;
	currentFigure = figures[currentFigureIndex];
	pos.X = 17 / 2 - 2;
	pos.Y = 1;
}

void Figure::InitVector()
{
	switch (type)
	{
	case Figure::I:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'*', L'.', L'.',
						  L'.', L'*', L'.', L'.',
						  L'.', L'*', L'.', L'.',
						  L'.', L'*', L'.', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'*', L'*',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);

					  break;
	}
	case Figure::O:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'*', L'*', L'.',
					  };

					  GenerateFigure(t1);

					  break;
	}
	case Figure::T:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'*', L'.',
						  L'.', L'*', L'.', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'*', L'.', L'.', L'.',
						  L'*', L'*', L'.', L'.',
						  L'*', L'.', L'.', L'.',
					  };

					  const wchar_t t3[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'*', L'.', L'.',
						  L'*', L'*', L'*', L'.',
					  };

					  const wchar_t t4[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'*', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'.', L'*', L'.',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);
					  GenerateFigure(t3);
					  GenerateFigure(t4);

					  break;
	}
	case Figure::L:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'*', L'.',
						  L'*', L'.', L'.', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'*', L'.', L'.', L'.',
						  L'*', L'.', L'.', L'.',
						  L'*', L'*', L'.', L'.',
					  };

					  const wchar_t t3[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'*', L'.',
						  L'*', L'*', L'*', L'.',
					  };

					  const wchar_t t4[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'.', L'*', L'.',
						  L'.', L'.', L'*', L'.',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);
					  GenerateFigure(t3);
					  GenerateFigure(t4);

					  break;
	}
	case Figure::Z:
	{
					  const wchar_t t1[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'.', L'.',
						  L'*', L'*', L'.', L'.',
						  L'.', L'*', L'*', L'.',
					  };

					  const wchar_t t2[4][4] = {
						  L'.', L'.', L'.', L'.',
						  L'.', L'.', L'*', L'.',
						  L'.', L'*', L'*', L'.',
						  L'.', L'*', L'.', L'.',
					  };

					  GenerateFigure(t1);
					  GenerateFigure(t2);

					  break;
	}
	}
}

void Figure::Move(float deltaTime)
{
	pos.Y += speed * deltaTime;
}

void Figure::FastFall()
{
	speed = 14;
}

void Figure::MoveLeft()
{
	pos.X -= 1;
}

void Figure::MoveRight()
{
	pos.X += 1;
}

void Figure::GenerateFigure(const wchar_t t[4][4])
{
	figures.push_back(new wchar_t*[4]);

	for (int i = 0; i < 4; i++)
	{
		figures[figures.size() - 1][i] = new wchar_t[4];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			figures[figures.size() - 1][i][j] = t[i][j];
		}
	}
}

void Figure::Rotate()
{
	if (currentFigureIndex < figures.size() - 1)
	{
		currentFigureIndex += 1;
		currentFigure = figures[currentFigureIndex];
	}
	else
	{
		currentFigureIndex = 0;
		currentFigure = figures[currentFigureIndex];
	}
}

Figure::~Figure()
{
	for (uint i = 0; i < figures.size(); i++)
	{
		for (uint j = 0; j < 4; j++)
		{
			delete[] figures[i][j];
		}

		delete[] figures[i];
	}


	figures.clear();
}
