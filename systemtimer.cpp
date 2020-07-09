#include "systemtimer.h"
#include <Windows.h>

SystemTimer::SystemTimer()
{
	//フレームカウント初期化
	timeBeginPeriod(1);
	lastTime_ = timeGetTime();
	framePerSecond_ = 0;
}

SystemTimer::~SystemTimer()
{
	// 分解能を戻す
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
