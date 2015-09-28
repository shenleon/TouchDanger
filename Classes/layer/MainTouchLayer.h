#ifndef __MAIN_TOUCH_LAYER_
#define __MAIN_TOUCH_LAYER_

#include "cocos2d.h"
#include "layer\MainTouchDelegate.h"

/*´¥µãÊÂ¼þ²ã */
class MainTouchLayer : public cocos2d::CCLayer
{
public:
	CC_SYNTHESIZE(MainTouchDelegate*, m_pDelegate, Delegate);
public:
	virtual bool init();
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesCancelled(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void onExit();
	CREATE_FUNC(MainTouchLayer);
};

#endif