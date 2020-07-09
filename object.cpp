#include "object.h"
#include "component.h"

Object::Object()
{
}

Object::~Object()
{
	for (auto com : components_)
	{
		// remove‚ð‚â‚Á‚½•û‚ª—Ç‚³‚»‚¤‚¾‚¯‚Ç
		// ‚»‚à‚»‚à‚±‚ÌŒãClear‚·‚é‚È‚çŠÖŒW‚È‚¢à

		// ‚Æ‚¢‚¤‚í‚¯‚Å‰ð•úˆ—
		delete com;
	}
	components_.clear();
	for (auto ob : children_)
	{
		// ‚±‚Á‚¿‚à“¯‚¶

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
