#include "object.h"
#include "component.h"

Object::Object()
{
}

Object::~Object()
{
	for (auto com : components_)
	{
		// remove������������ǂ�����������
		// �����������̌�Clear����Ȃ�֌W�Ȃ���

		// �Ƃ����킯�ŉ������
		delete com;
	}
	components_.clear();
	for (auto ob : children_)
	{
		// ������������

		delete ob;
	}
	children_.clear();
}

void Object::Update()
{
	for (auto com : components_)
	{
		com->Update();
	}
	for (auto ob : children_)
	{
		ob->Update();
	}
}
