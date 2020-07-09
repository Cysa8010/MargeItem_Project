#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer
{
public:
	Renderer(float width, float height);
	~Renderer();
	void Draw();

private:
	union
	{
		char* backBuffer;//[SCREEN_HEIGHT * (SCREEN_WIDTH + 1) + 1]
		//char** accessBuffer;//[SCREEN_HEIGHT][SCREEN_WIDTH + 1]
	};
	int width_ = 0;
	int height_ = 0;

	void ClearBuffer();
	void Write(int x, int y, int len, const char* str);
	
	Renderer() = delete;
};

#endif // !RENDERER_H_
