#ifndef OBJECT_H_
#define OBJECT_H_

#include <list>
#include <string>

class Component;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Update();

	// Unity����
	int GetInstanceID()const { return 0xffffffff; };
	std::string ToString()const { return name_; }

private:
	// componentList
	std::list<Component*> components_;
	// �q�v�f
	std::list<Object*> children_;
	// �^�O?
	// Layer?
	std::string name_;
	// hideFrlags...engine���O��ɂȂ��Ă��܂�����g��Ȃ�
};

#endif // !OBJECT_H_
