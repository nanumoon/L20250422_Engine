#include "World.h"
#include "Actor.h"

#include "Player.h"
#include "Wall.h"

UWorld::UWorld()
{
	SpawnActor(new APlayer());
	SpawnActor(new AWall());
	
	AWall* NewWall = new AWall();
	NewWall->Location.X = 1;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);

	NewWall = new AWall();
	NewWall->Location.X = 2;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);
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
	//모든 액터 틱해라
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	//모든 액터 : 반복문 돌리기
	//모든 액터 랜더해라
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
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
