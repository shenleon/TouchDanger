#pragma once
#ifndef __MAIN_RESOURCE_LAYER_
#define __MAIN_RESOURCE_LAYER_

#include "cocos2d.h"
#include "MainResourceDelegate.h"
/*�ڵ��ʶ*/
enum{
	LAB_LIFE,
	LAB_MONEY
};

class MainResourceLayer : public cocos2d::CCLayer , public MainResourceDelegate
{
protected:
	CC_SYNTHESIZE(int*, p_mExperience, Experience);
	CC_SYNTHESIZE(int*, p_mMoney, Money);
public:
	virtual bool init();
	/*���Ӿ���*/
	virtual void incrExperience(int val);
	/*�۳�����*/
	virtual void decrExperience(int val);
	/*���ӽ�Ǯ*/
	virtual void incrMoney(int val);
	/*�۳���Ǯ*/
	virtual void decrMoney(int val);
	/*��������ֵ��ʾ */
	virtual void updateExperienceShow();
	/*���½�Ǯ��ʾ*/
	virtual void updateMoneyShow();
	CREATE_FUNC(MainResourceLayer);
};

#endif

