#ifndef __ALERT_LAYER_
#define __ALERT_LAYER_

#include "cocos2d.h"

/*������*/
class AlertLayer : public cocos2d::CCLayer
{
private:
	cocos2d::CCSize visibleSize;
	cocos2d::CCNode * pBackground;
public:
	virtual bool init();
	virtual void onExit();
	//���ñ���
	virtual void setBackground(cocos2d::CCNode * background);
	//���Ч��
	void action(cocos2d::CCObject * sender);
	//����
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	CREATE_FUNC(AlertLayer);
};

#endif