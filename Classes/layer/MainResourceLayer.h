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
public:
	virtual bool init();
	/*���Ӿ���*/
	virtual void incrExperience(const int val);
	/*�۳�����*/
	virtual void decrExperience(const int val);
	/*���ӽ�Ǯ*/
	virtual void incrMoney(const int val);
	/*�۳���Ǯ*/
	virtual void decrMoney(const int val);
	/*��������ֵ��ʾ */
	virtual void updateExperienceShow();
	/*���½�Ǯ��ʾ*/
	virtual void updateMoneyShow();
	CREATE_FUNC(MainResourceLayer);
};

#endif

