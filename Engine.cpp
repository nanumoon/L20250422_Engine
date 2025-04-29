#include "Engine.h"
#include "Input.h"
#include "World.h"
#include "Renderer.h"


UEngine* UEngine::Instance = nullptr;

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

void UEngine::Initialize(std::string filename)
{
	SDL_Init(SDL_INIT_VIDEO);

	Window = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);

	InputDevice = new UInput();
	World = new UWorld();
	World->Load(filename);
	URenderer::GetInstance();
}

void UEngine::Run()
{
	while (IsRunning)
	{
		SDL_PollEvent(&Event);
		switch (Event.type)
		{
		case SDL_EVENT_QUIT:
			IsRunning = false;
			break;
		}
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

	SDL_DestroyWindow(Window);
	SDL_Quit();
}

void UEngine::Input()
{
	InputDevice->Tick();
	//Engine has a InputDevice
	//키보드, 마우스, 조이스틱, 터치, 자이로 센스...
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}

