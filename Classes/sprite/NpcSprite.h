#ifndef __NPC_SPRITE_
#define __NPC_SPRITE_

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>
#include "NpcTouchDelegate.h"

/*ϵͳ���ﾫ��*/
class NpcSprite : public cocos2d::CCSprite,public cocos2d::CCTouchDelegate
{
protected:
	cocos2d::extension::CCSkeletonAnimation* skeletonNode;
public:
	CC_SYNTHESIZE(const char *, pName, Name);
	CC_SYNTHESIZE(NpcTouchDelegate *, p_mNpcTouchDelegate, NpcTouchDelegate);
public:
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	/*��ʼ�ƶ�*/
	void move();
	/*ֹͣ�ƶ�*/
	void stop();
	CREATE_FUNC(NpcSprite);
};

#endif
