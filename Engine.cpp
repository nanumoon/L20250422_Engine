#include "Engine.h"
#include "Input.h"
#include "World.h"

UEngine::UEngine()/* : World(nullptr)*/ //���� ����鼭 ���� �ʱ�ȭ
{
	//���� ����� ���� ���� �ʱ�ȭ
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
	//Ű����, ���콺, ��ġ, ���̷� ����...
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}

