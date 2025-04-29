#include <fstream>
#include <iostream>
#include <algorithm>

#include "World.h"
#include "Actor.h"

#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Floor.h"
#include "Goal.h"
#include "Renderer.h"

UWorld::UWorld()
{
	/*SpawnActor(new APlayer());
	SpawnActor(new AWall());
	
	AWall* NewWall = new AWall();
	NewWall->Location.X = 1;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);

	NewWall = new AWall();
	NewWall->Location.X = 2;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);*/
}

UWorld::~UWorld()
{
	//system("cls");
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::Tick()
{
	//��� ���� ƽ�ض�
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	URenderer::GetInstance()->Clear();
	//��� ���� : �ݺ��� ������
	//��� ���� �����ض�
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
	URenderer::GetInstance()->Present();
}

void UWorld::Load(std::string filename)
{
	std::ifstream MapFile(filename);

	int X = 0;
	int Y = 0;

	while (!MapFile.eof())
	{
		char Buffer[200] = { 0, };
		MapFile.getline(Buffer, 100);
		for (X = 0; X < strlen(Buffer); ++X)
		{
			if (Buffer[X] == '*')
			{
				SpawnActor(new AWall(FVector2D(X, Y)));
			}
			else if (Buffer[X] == ' ')
			{
				//SpawnActor(new AFloor(FVector2D(X, Y)));
			}
			else if (Buffer[X] == 'M')
			{
				SpawnActor(new AMonster(FVector2D(X, Y)));
			}
			else if (Buffer[X] == 'G')
			{
				SpawnActor(new AGoal(FVector2D(X, Y)));
			}
			else if (Buffer[X] == 'P')
			{
				SpawnActor(new APlayer(FVector2D(X, Y)));
			}

			SpawnActor(new AFloor(FVector2D(X, Y)));

		}


		Y++;

	}


	MapFile.close();

	//std::sort(Actors.begin(), Actors.end(), AActor::Compare);

	//Ŭ���� Ȱ��
	//std::sort(Actors.begin(), Actors.end(), ActorCompareByRenderOrder{});

	//�����Լ�
	std::sort(Actors.begin(), Actors.end(), [](const AActor* A, AActor* B) {return (A->RenderOrder) > (B->RenderOrder); });
	// 
	//sort

	//����
	//map ���� �о �����
	//text
	//���پ� �о ��ü �����ϰ� ����
	//while(�����б�), ifstream,
	//{
	//	��ĭ ���� Ȯ��
	//	���� ����
	//}
}



void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::DestroyActor(AActor* DestroyedActor)
{
	Actors.erase(find(Actors.begin(), Actors.end(), DestroyedActor));
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}
