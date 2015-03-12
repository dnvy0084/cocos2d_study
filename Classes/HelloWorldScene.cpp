#include "HelloWorldScene.h"

using namespace cocos2d;


Scene* HelloWorldScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorldScene::create();

	scene->addChild(layer);

	return scene;
}

void HelloWorldScene::layout()
{
	Label* label = Label::create();

	label->setString("Hello, Cocos2D-x");

	label->setSystemFontName("RixGo B");
	label->setColor(Color3B(255, 0, 0));
	label->setSystemFontSize(30);
	label->setAnchorPoint(Point(0.5, 0.5));
	label->setPosition(Point(this->stage.width / 2, this->stage.height / 2));

	this->addChild(label);

	this->setTitle("Hello world scene");
}