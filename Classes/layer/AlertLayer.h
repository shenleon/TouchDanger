#ifndef __ALERT_LAYER_
#define __ALERT_LAYER_

#include "cocos2d.h"

/*弹出层*/
class AlertLayer : public cocos2d::CCLayer
{
private:
	cocos2d::CCSize visibleSize;
	cocos2d::CCNode * pBackground;
public:
	virtual bool init();
	virtual void onExit();
	//设置背景
	virtual void setBackground(cocos2d::CCNode * background);
	//点击效果
	void action(cocos2d::CCObject * sender);
	//触摸
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	CREATE_FUNC(AlertLayer);
};

#endif