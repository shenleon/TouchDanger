#ifndef __NPC_SPRITE_
#define __NPC_SPRITE_

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>

/*ϵͳ���ﾫ��*/
class NpcSprite : public cocos2d::CCSprite
{
protected:
	cocos2d::extension::CCSkeletonAnimation* skeletonNode;
public:
	virtual bool init();
	CREATE_FUNC(NpcSprite);
};

#endif
