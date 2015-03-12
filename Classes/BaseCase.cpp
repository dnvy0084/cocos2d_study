#include "BaseCase.h"
#include "TestMainScene.h"

using namespace cocos2d;

Scene* BaseCase::createScene()
{
	auto scene = Scene::create();
	auto layer = BaseCase::create();

	scene->addChild(layer);

	return scene;
}

bool BaseCase::init()
{
	if (!LayerColor::initWithColor(Color4B(255,255,255,255)) ) return false;

	this->stage = Director::getInstance()->getVisibleSize();

	this->layoutTitleLabel();
	this->layoutBackButton();
	this->layout();
	
	this->addKeyboardEvents();

	return true;
}

const char* BaseCase::getTitle()
{
	return this->title->getString().c_str();
}

void BaseCase::setTitle(const char* title)
{
	this->title->setString(std::string(title));
}

void BaseCase::addKeyboardEvents()
{
	Director* dir = Director::getInstance();

	dir->getOpenGLView()->setIMEKeyboardState(true);

	auto key = EventListenerKeyboard::create();

	key->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_GRAVE:
		case EventKeyboard::KeyCode::KEY_BACKSPACE:
			this->onBackClick(NULL);
			break;
		}
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);
}

void BaseCase::layout()
{
	auto label = Label::create("Base Case Scene - had to overwritten", "NanumGothic", 30);

	label->setPosition(this->stage.width / 2, this->stage.height / 2);
	label->setColor(Color3B(0, 0, 0));

	this->addChild(label);
}

void BaseCase::layoutTitleLabel()
{
	auto title = Label::create("title label", "dotum", 12);

	title = Label::create("some title", "dotum", 11);
	title->setAnchorPoint(Point(0.0, 1.0));
	title->setPosition(Point(this->titleMargin, this->stage.height - this->titleMargin));
	title->setColor(Color3B(60, 60, 60));

	this->addChild(title);

	this->title = title;
}

void BaseCase::layoutBackButton()
{
	Size size = Director::getInstance()->getVisibleSize();
	float margin = 5.0;

	auto item = MenuItemImage::create(
		"back-alt-128.png", 
		"back-alt-128-down.png", 
		CC_CALLBACK_1(BaseCase::onBackClick, this)
	);

	item->setAnchorPoint(Point(1.0, 1.0));

	auto menu = Menu::create();

	menu->addChild(item);
	menu->setAnchorPoint(Point(1.0, 1.0));
	menu->setPosition(size.width - margin, size.height - margin);

	this->addChild(menu);
}

void BaseCase::onBackClick(Ref* sender)
{
	auto scene = TransitionSlideInL::create(TestMain::TRANSITION_INTERVAL, TestMain::createScene());

	Director::getInstance()->replaceScene(scene);
}