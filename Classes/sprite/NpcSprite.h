#ifndef __NPC_SPRITE_
#define __NPC_SPRITE_

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>

/*系统人物精灵*/
class NpcSprite : public cocos2d::CCSprite
{
protected:
	cocos2d::extension::CCSkeletonAnimation* skeletonNode;
public:
	virtual bool init();
	CREATE_FUNC(NpcSprite);
};

#endif
