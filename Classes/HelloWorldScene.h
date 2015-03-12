#ifndef __HELLOWORLD_SCENE__
#define __HELLOWORLD_SCENE__

#include "cocos2d.h"
#include "BaseCase.h"

class HelloWorldScene : public BaseCase
{
public:

	static cocos2d::Scene* createScene();
	void layout();

	CREATE_FUNC(HelloWorldScene);
};

#endif