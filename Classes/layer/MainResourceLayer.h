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
protected:
	CC_SYNTHESIZE(int*, p_mLife, Life);
	CC_SYNTHESIZE(int*, p_mMoney, Money);
public:
	virtual bool init();
	/*增加生命值*/
	virtual void incrLife(int val);
	/*扣除生命值*/
	virtual void decrLife(int val);
	/*增加金钱*/
	virtual void incrMoney(int val);
	/*扣除金钱*/
	virtual void decrMoney(int val);
	/*更新生命值显示 */
	virtual void updateLifeShow();
	/*更新金钱显示*/
	virtual void updateMoneyShow();
	CREATE_FUNC(MainResourceLayer);
};

#endif

