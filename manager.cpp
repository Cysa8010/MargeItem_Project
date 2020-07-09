#include "manager.h"
#include "window.h"
#include "renderer.h"
#include "systemtimer.h"
#include <stdio.h>
#include <conio.h>

#include <Windows.h>
#pragma comment (lib, "winmm.lib")

Manager::Manager()
{
	Window::Init();
	renderer = new Renderer(Window::GetWidth(), Window::GetHeight());
}

Manager::~Manager()
{
	delete renderer;
}

int Manager::Update()
{
	SystemTimer* sysTimer = new SystemTimer;

	char buf;
	while (1)
	{
		if (_kbhit()) {
			buf = _getch();
			// inputManagerに渡す

			// テスト用コード
			break;
		}
		else
		{
			sysTimer->Update();
			if (sysTimer->GetFrameOver())
			{
				// 更新処理

				// 描画処理
				renderer->Draw();
			}
		}
	}

	delete sysTimer;
	//getchar();
	return 0;
}
