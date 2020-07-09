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
	//Buffer���X�y�[�X�ŃN���A
	for (int i = 0; i < height_ * (width_ + 1); i++)
	{
		backBuffer[i] = '*';
	}

	//�s�̏I���ɉ��s�����
	for (int i = 0; i < height_; i++)
	{
		int w = width_;
		int h = i;
		backBuffer[(h*(width_ + 1)) + (w)] = '\n';
	}

	//�S�Ă̏I����NULL����
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
