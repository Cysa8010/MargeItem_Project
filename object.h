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

	// Unity準拠
	int GetInstanceID()const { return 0xffffffff; };
	std::string ToString()const { return name_; }

private:
	// componentList
	std::list<Component*> components_;
	// 子要素
	std::list<Object*> children_;
	// タグ?
	// Layer?
	std::string name_;
	// hideFrlags...engine作る前提になってしまうから使わない
};

#endif // !OBJECT_H_
