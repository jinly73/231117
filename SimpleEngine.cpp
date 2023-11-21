#include "SimpleEngine.h"
#include "World.h"
#include <conio.h> //_getch(); 선언문
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include "Monster.h"
#include "Floor.h"

SimpleEngine* SimpleEngine::Instance = nullptr;
int SimpleEngine::KeyCode = 0;

SimpleEngine::SimpleEngine()
{
	Init();
}

SimpleEngine::~SimpleEngine()
{
	Term();
}

void SimpleEngine::Init()
{
	IsRunning = true;
	World = new UWorld();
}

void SimpleEngine::Run()
{
	while (IsRunning)
	{
		Input();
		Tick();
		//Clear Screen
		system("cls");
		Render();
	}
}


void SimpleEngine::Stop()
{
	IsRunning = false;
}

void SimpleEngine::Term()
{
	IsRunning = false;
	delete World;
}


void SimpleEngine::LoadLevel(std::string Filename)
{
	//Save
	//Menory -> Disk : Serialize, Text(JSON, csv), binary(umap)

	//Load
	//Disk -> Memory : deserialize
	std::string Map[10] = {

		"**********",
		"*P       *",
		"*        *",
		"*        *",
		"*        *",
		"*     M  *",
		"*        *",
		"*        *",
		"*       G*",
		"**********",

	};

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < Map[Y].length(); ++X)
		{
			if (Map[Y][X] == '*')
			{
				//Wall
				GetWorld()->SpawnActor(new AWall(X, Y));

			}
			else if (Map[Y][X] == 'P')
			{
				//Player
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Map[Y][X] == 'M')
			{
				//Monster
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Map[Y][X] == 'G')
			{
				//Goal
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}
			else if (Map[Y][X] == ' ')
			{

			}
			//Floor
			GetWorld()->SpawnActor(new AFloor(X, Y));
		}
	}

	GetWorld()->SortRenderOrder();
}



void SimpleEngine::Input()
{
	KeyCode = _getch(); // 키를 입력하면 그 키의 ASCII코드 값을 줌
	
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

void SimpleEngine::Tick()
{
	GetWorld()->Tick();
}
