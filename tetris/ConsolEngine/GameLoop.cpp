#include "GameLoop.h"


GameLoop::GameLoop()
{
	field = new Field(21, 17);
	currentFigure = RandomFigure();
	nextFigure = RandomFigure();
	gameOver = false;
}

void GameLoop::UpdateF(float deltaTime)
{
	DrawField();
	if (field->CollisionCheck(*currentFigure, gameOver) && currentFigure->IsActive())
		currentFigure->Move(deltaTime);

	if (!currentFigure->IsActive())
	{
		UpdateField();
		delete currentFigure;
		currentFigure = nextFigure;
		nextFigure = RandomFigure();

	}
	
	if (gameOver)
	{
		field->ClearField();
		gameOver = false;	
	}	
}

void GameLoop::KeyPressed(int btnCode)
{
	if (btnCode == VK_SPACE)
	{
		if (field->CanRotate(*currentFigure))
			currentFigure->Rotate();
	}
	

	if (btnCode == 224)
	{
		int btn = _getch();

		if (btn == 75) // leftarrow
			if (field->CanMoveLeft(*currentFigure))
				currentFigure->MoveLeft();
		
		if (btn == 77) // rightarrow
		if (field->CanMoveRight(*currentFigure))
			currentFigure->MoveRight();

		if (btn == 80) // downarrow
			currentFigure->FastFall();
	}
}

void GameLoop::DrawField()
{
	ClearScreen();
	for (uint i = 0; i < field->GetHeight(); i++)
	{
		for (uint j = 0; j < field->GetWidth(); j++)
		{
			SetChar(i, j, field->GetField()[i][j]);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			SetChar(i + field->GetHeight(), j, field->GetMiniField()[i][j]);
		}
	}
	
	UpdateField();
	DrawFigure();	
	DrawNextFigure();
}

void GameLoop::ClearScreen()
{
	for (uint i = 0; i < field->GetHeight(); i++)
	{
		for (uint j = 0; j < field->GetWidth(); j++)
		{
			SetChar(i, j, L' ');
		}
	}
}

void GameLoop::DrawNextFigure()
{
	field->InitMiniField();

	for (uint i = 0; i < 4; i++)
	{
		for (uint j = 0; j < 4; j++)
		{
			if (nextFigure->GetActualFigure()[i][j] == L'*')
				SetChar(field->GetHeight() + i, j + 2, nextFigure->GetActualFigure()[i][j]);
		}
	}
}

void GameLoop::DrawFigure()
{
	
	for (uint i = 0; i < 4; i++)
	{
		for (uint j = 0; j < 4; j++)
		{
			if (currentFigure->GetActualFigure()[i][j] == L'*')
				SetChar(currentFigure->GetPos().X + i, currentFigure->GetPos().Y + j, currentFigure->GetActualFigure()[i][j]);
		}
	}
}

void GameLoop::UpdateField()
{
	for (uint i = 0; i < field->GetHeight(); i++)
	{
		for (uint j = 0; j < field->GetWidth(); j++)
		{
			field->GetField()[i][j] = GetChar(i, j);
		}
	}
}

Figure* GameLoop::RandomFigure()
{
	srand(GetTickCount());
	return new Figure((Figure::FigureType)(rand()%5));
}

GameLoop::~GameLoop()
{
	delete field;
}
