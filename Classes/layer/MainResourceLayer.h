#pragma once
#ifndef __MAIN_RESOURCE_LAYER_
#define __MAIN_RESOURCE_LAYER_

#include "cocos2d.h"
#include "MainResourceDelegate.h"

class MainResourceLayer : public cocos2d::CCLayer , public MainResourceDelegate
{
protected:
	CC_SYNTHESIZE(int*, p_mLife, Life);
	CC_SYNTHESIZE(int*, p_mMoney, Money);
public:
	virtual bool init();
	virtual void incrLife(int val);
	virtual void decrLife(int val);
	virtual void incrMoney(int val);
	virtual void decrMoney(int val);
	CREATE_FUNC(MainResourceLayer);
};

#endif

