#include "Field.h"


Field::Field(int W, int H) : WIDTH(W), HEIGHT(H)
{
	field = new wchar_t*[HEIGHT];

	for (uint i = 0; i < HEIGHT; i++)
	{
		field[i] = new wchar_t[WIDTH];

		for (uint j = 0; j < WIDTH; j++)
		{
			field[i][j] = L'.';
		}
	}

	for (uint i = 0; i < HEIGHT; i++)
	{
		field[i][0] = L'#';
		field[i][WIDTH-1] = L'#';
	}

	for (uint i = 0; i < WIDTH; i++)
	{
		field[HEIGHT-1][i] = L'#';
		field[0][i] = L'#';
	}

	InitMiniField();
}

void Field::InitMiniField()
{
	miniField = new wchar_t*[6];

	for (uint i = 0; i < 6; i++)
	{
		miniField[i] = new wchar_t[7];

		for (uint j = 0; j < 7; j++)
		{
			miniField[i][j] = L'.';
		}
	}

	for (uint i = 0; i < 6; i++)
	{
		miniField[i][0] = L'#';
		miniField[i][7 - 1] = L'#';
	}

	for (uint i = 0; i < 7; i++)
	{
		miniField[6 - 1][i] = L'#';
		miniField[0][i] = L'.';
	}

	miniField[0][0] = L'#';
	miniField[0][7-1] = L'#';
}

void Field::ClearLines()
{
	vector<int> lineIndexes;
	vector<int>::iterator it;

	for (uint i = WIDTH - 2; i >= 1; i--)
	{
		bool full = true;

		for (uint j = HEIGHT - 2; j >= 1; j--)
		{
			if (field[j][i] != L'*')
				full = false;
			else
				lineIndexes.push_back(i);
		}

		if (full)
		{
			for (uint i = WIDTH - 2; i >= 1; i--)
			{
				for (uint j = HEIGHT - 2; j >= 1; j--)
				{
					for (it = lineIndexes.begin(); it != lineIndexes.end(); it++)
					{
						field[j][i] = field[j][i - 1];
						field[j][1] = L'.';
					}
				}
			}
		}
	}
}

bool Field::CanRotate(Figure &f)
{
	if (f.GetType() == Figure::FigureType::O)
		return true;



	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (f.GetActualFigure()[i][j] == L'*')
			{
				if (((field[(int)f.GetPos().X + i - 1][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i - 1][(int)f.GetPos().Y + j] == L'*') ||
					(field[(int)f.GetPos().X + i - 2][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i - 2][(int)f.GetPos().Y + j] == L'*') ||
					(field[(int)f.GetPos().X + i - 3][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i - 3][(int)f.GetPos().Y + j] == L'*')) && f.GetType() == Figure::FigureType::I && f.GetCurrentFindex() == 1)
				{
					f.MoveRight();
					CanRotate(f);
				}


				if (field[(int)f.GetPos().X + i - 1][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i - 1][(int)f.GetPos().Y + j] == L'*')
				{
					f.MoveRight();
					CanRotate(f);
				}

				if (field[(int)f.GetPos().X + i + 1][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i + 1][(int)f.GetPos().Y + j] == L'*')
				{
					f.MoveLeft();
					CanRotate(f);
				}
			}
		}
	}
	return true;
}

bool Field::CanMoveLeft(Figure &f)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (f.GetActualFigure()[i][j] == L'*')
			{
				if (field[(int)f.GetPos().X + i - 1][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i - 1][(int)f.GetPos().Y + j] == L'*')
					return false;
			}
		}
	}
	return true;
}

bool Field::CanMoveRight(Figure &f)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (f.GetActualFigure()[i][j] == L'*')
			{
				if (field[(int)f.GetPos().X + i + 1][(int)f.GetPos().Y + j] == L'#' ||
					field[(int)f.GetPos().X + i + 1][(int)f.GetPos().Y + j] == L'*')
					return false;
			}
		}
	}
	return true;
}

void Field::ClearField()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			field[i][j] = L'.';
		}
	}

	for (uint i = 0; i < HEIGHT; i++)
	{
		field[i][0] = L'#';
		field[i][WIDTH - 1] = L'#';
	}

	for (uint i = 0; i < WIDTH; i++)
	{
		field[HEIGHT - 1][i] = L'#';
		field[0][i] = L'#';
	}
}

bool Field::CollisionCheck(Figure &f, bool &gameover)
{
	ClearLines();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (f.GetActualFigure()[i][j] == L'*')
			{
				if (field[(int)f.GetPos().X + i][(int)f.GetPos().Y + j + 1] == L'#' ||
					field[(int)f.GetPos().X + i][(int)f.GetPos().Y + j + 1] == L'*')
				{
					if ((int)f.GetPos().Y + j <= 1)						
						gameover = true;

					f.SetActive(false);
					return false;
				}

			}
		}
	}
	return true;
}

Field::~Field()
{
	for (uint i = 0; i < HEIGHT; i++)
	{
		delete[] field[i];
	}

	delete[] field;
}
