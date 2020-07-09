#ifndef COMPONENT_H_
#define COMPONENT_H_

class Object;

class Component :public Object
{
public:
	Component() {}
	virtual ~Component() = 0;
	virtual void Update() = 0;

	// unityèÄãí

private:

};

#endif // !COMPONENT_H_
