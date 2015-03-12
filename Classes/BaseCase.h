#ifndef __BASECASE_LAYER_H__
#define __BASECASE_LAYER_H__

#pragma once
#include "cocos2d.h"

class BaseCase : public cocos2d::LayerColor
{
public:
	cocos2d::Size stage;

	static cocos2d::Scene* createScene();

	virtual bool init();
	void onBackClick(Ref* sender);

	CREATE_FUNC(BaseCase);

protected:

	cocos2d::Label* title;

	virtual void layout();
	virtual void layoutBackButton();
	virtual void addKeyboardEvents();
	virtual void setTitle(const char*);
	virtual const char* getTitle();

private:

	int titleMargin = 5;

	void layoutTitleLabel();
};

#endif //__BASECASE_LAYER_H__ 