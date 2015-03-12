#include <string>
#include "TestMainScene.h"
#include "BaseCase.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

float TestMain::TRANSITION_INTERVAL = 0.2;

Scene* TestMain::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = TestMain::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestMain::init()
{
	if (!Layer::init()) return false;

	this->addEvents();
	this->layout();
    
    return true;
}

void TestMain::layout()
{
	auto director = Director::getInstance();

	Size stageSize = director->getVisibleSize();

	const char* labels[] = {
		"hello world",
		"Drag Sprite"
	};

	// c function pointer array
	//this->createFuncs[0] = HelloWorldScene::createScene;

	//push_back createScene function pointer;
	this->scenes.push_back(HelloWorldScene::createScene);

	auto menu = Menu::create();

	for (int i = 0, l = sizeof(labels) / sizeof(char*); i < l; i++)
	{
		auto item = MenuItemFont::create(
			*(labels + i), CC_CALLBACK_1(TestMain::onMenuItemClick, this));

		item->setTag(i);
		item->setAnchorPoint(Point(0.5, 0.5));

		menu->addChild(item);
	};

	const float margin = 5.0;

	menu->alignItemsVertically();
	menu->setAnchorPoint(Point(0.5, 0.5));
	menu->setPosition(Point(stageSize.width / 2, stageSize.height / 2));

	this->addChild(menu);
}


void TestMain::addEvents()
{
	auto keyListener = EventListenerKeyboard::create();

	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event *e)
	{
		auto key = (int)keyCode - 77;

		if (key < 0 || key >= this->scenes.size()) return;

		this->changeLayer(key);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}

void TestMain::onMenuItemClick(Ref* sender)
{
	auto item = (MenuItemFont*)sender;
	int tag = item->getTag();

	if (tag >= this->scenes.size()) return;

	this->changeLayer(tag);
}

void TestMain::changeLayer(int tag)
{
	auto scene = TransitionSlideInR::create(TestMain::TRANSITION_INTERVAL, this->scenes[tag]());

	Director::getInstance()->replaceScene(scene);
}
