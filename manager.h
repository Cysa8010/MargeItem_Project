#ifndef MANAGER_H_
#define MANAGER_H_

class Window;
class Renderer;

class Manager
{
public:
	Manager();
	~Manager();
	int Update();

private:
	Renderer* renderer;
};

#endif // !MANAGER_H_
