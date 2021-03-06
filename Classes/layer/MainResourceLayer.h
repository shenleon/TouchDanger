#pragma once
#ifndef __MAIN_RESOURCE_LAYER_
#define __MAIN_RESOURCE_LAYER_

#include "cocos2d.h"
#include "MainResourceDelegate.h"
/*节点标识*/
enum{
	LAB_LIFE,
	LAB_MONEY
};

class MainResourceLayer : public cocos2d::CCLayer , public MainResourceDelegate
{
public:
	virtual bool init();
	/*增加经验*/
	virtual void incrExperience(const int val);
	/*扣除经验*/
	virtual void decrExperience(const int val);
	/*增加金钱*/
	virtual void incrMoney(const int val);
	/*扣除金钱*/
	virtual void decrMoney(const int val);
	/*更新生命值显示 */
	virtual void updateExperienceShow();
	/*更新金钱显示*/
	virtual void updateMoneyShow();
	CREATE_FUNC(MainResourceLayer);
};

#endif

