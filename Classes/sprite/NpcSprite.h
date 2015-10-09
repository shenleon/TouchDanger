#ifndef __NPC_SPRITE_
#define __NPC_SPRITE_

#include "cocos2d.h"

/*系统人物精灵*/
class NpcSprite : public cocos2d::CCSprite,public cocos2d::CCTouchDelegate
{
public:
	CC_SYNTHESIZE(cocos2d::CCString *, pName, Name);
public:
	virtual bool init();
	virtual void onExit();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	CREATE_FUNC(NpcSprite);
};

#endif
