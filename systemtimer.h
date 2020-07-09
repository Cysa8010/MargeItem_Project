#ifndef SYSTEMTIMTER_H_
#define SYSTEMTIMTER_H_

class SystemTimer
{
public:
	SystemTimer();
	~SystemTimer();
	void  Update();
	bool GetFrameOver() const
	{
		return isFrameOver_;
	}

private:
	unsigned long lastTime_;
	unsigned long currentTime_;
	unsigned long framePerSecond_;
	bool isFrameOver_;

};

#endif // !SYSTEMTIMTER_H_
