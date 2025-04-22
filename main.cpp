#include "Engine.h"

int main()
{
	UEngine* Engine = new UEngine();

	Engine->Initialize();

	Engine->Run();

	return 0;
}