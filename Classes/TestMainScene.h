#ifndef __TESTMAIN_SCENE_H__
#define __TESTMAIN_SCENE_H__

#include <string>
#include <vector>
#include "cocos2d.h"

class TestMain : public cocos2d::Layer
{
public:

	// transition interval
	static float TRANSITION_INTERVAL;

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	

	// c style function pointer array
	cocos2d::Scene*(*createFuncs[20])();

	// createScene function pointer vector
	std::vector<cocos2d::Scene*(*)()> scenes;
	std::vector<cocos2d::Scene*(*)(float, cocos2d::Scene*)> transitions;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void onMenuItemClick(Ref* sender);

	void changeLayer(int tag);

	void layout();

	void addEvents();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestMain);
};

#endif // __TESTMAIN_SCENE_H__