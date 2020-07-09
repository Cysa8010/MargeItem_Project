#include "systemtimer.h"
#include <Windows.h>

SystemTimer::SystemTimer()
{
	//�t���[���J�E���g������
	timeBeginPeriod(1);
	lastTime_ = timeGetTime();
	framePerSecond_ = 0;
}

SystemTimer::~SystemTimer()
{
	// ����\��߂�
	timeEndPeriod(1);
}

void SystemTimer::Update()
{
	unsigned long current = timeGetTime();
	isFrameOver_ = (current - lastTime_) >= (1000 / 60);
	if (isFrameOver_)
	{
		lastTime_ = current;
	}
}
