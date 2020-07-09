#include "renderer.h"
#include <Windows.h>
#include <stdio.h>

Renderer::Renderer(float width, float height) :width_((float)width), height_((float)height)
{
	backBuffer = new char[height_*(width_ + 1) + 1];
}

Renderer::~Renderer()
{
	delete[] backBuffer;
}

void Renderer::Draw()
{
	ClearBuffer();
	system("cls");

	printf("%s", backBuffer);
}

void Renderer::ClearBuffer()
{
	//Bufferをスペースでクリア
	for (int i = 0; i < height_ * (width_ + 1); i++)
	{
		backBuffer[i] = '*';
	}

	//行の終わりに改行入れる
	for (int i = 0; i < height_; i++)
	{
		int w = width_;
		int h = i;
		backBuffer[(h*(width_ + 1)) + (w)] = '\n';
	}

	//全ての終わりにNULL文字
	backBuffer[height_ * (width_ + 1)] = '\0';
}

void Renderer::Write(int x, int y, int len, const char * str)
{
	for (int i = 0; i < len; i++)
	{
		int w = x + i;
		if (w >= width_)return;//break;

		int h = y;
		backBuffer[(h*(width_ + 1)) + (w)] = str[i];
	}
}
