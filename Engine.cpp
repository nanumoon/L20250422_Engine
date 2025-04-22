#include "Engine.h"
#include "Input.h"
#include "World.h"

UEngine::UEngine()/* : World(nullptr)*/ //엔진 만들면서 월드 초기화
{
	//엔진 만들고 나서 월드 초기화
	World = nullptr;
	InputDevice = nullptr;
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initialize()
{
	InputDevice = new UInput();
	World = new UWorld();
}

void UEngine::Run()
{
	while (true)
	{
		//1Frame
		Input();
		Tick();
		Render();
	}
}

void UEngine::Terminate()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}

	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}
}

void UEngine::Input()
{
	InputDevice->Tick();
	//Engine has a InputDevice
	//키보드, 마우스, 터치, 자이로 센스...
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}

