#ifndef WINDOW_H_
#define WINDOW_H_

//#define SCREEN_WIDTH (25)
//#define SCREEN_HEIGHT (25)

class Window
{
public:
	//Window();
	static void Init();
	
	static int GetWidth() { return width; }
	static int GetHeight() { return height; }

private:
	static int width;// = 25;
	static int height;// = 25;

};

#endif // !WINDOW_H_
