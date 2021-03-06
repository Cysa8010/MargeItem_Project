#include "object.h"
#include "component.h"

Object::Object()
{
}

Object::~Object()
{
	for (auto com : components_)
	{
		// removeをやった方が良さそうだけど
		// そもそもこの後Clearするなら関係ない説

		// というわけで解放処理
		delete com;
	}
	components_.clear();
	for (auto ob : children_)
	{
		// こっちも同じ

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
