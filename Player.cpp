#include "Player.h"
#include <iostream>
#include "World.h"
#include "SimpleEngine.h"
#include "Actor.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 500;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	//SetX(NewX);
	//SetY(NewY);
	X = NewX;
	Y = NewY;
	//Shape = 'P';
	SortOrder = NewSortOrder;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	//AActor::Tick();
	__super::Tick(); // __super 부모 클래스 부름 (비쥬얼스튜디오에서만 가능)
	int KeyCode = SimpleEngine::KeyCode;

	if (KeyCode == 'A' || KeyCode == 'a')
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
}

bool APlayer::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (Actor->bCollide == true &&
			Actor->GetX() == NewX &&
			Actor->GetY() == NewY)
		{
			return true;
		}
	}
	return false;
}


