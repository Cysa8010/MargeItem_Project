#include "manager.h"

int main(int argc, char* argv)
{
	Manager* m = new Manager;
	int res = m->Update();
	delete m;
	return res;
}