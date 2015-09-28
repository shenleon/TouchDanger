#ifndef __ROLE_SPRITE_
#define __ROLE_SPRITE_

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>

/*½ÇÉ«¾«Áé*/
class RoleSprite : public cocos2d::CCSprite
{
protected:
	cocos2d::CCPoint origin;
	cocos2d::CCSize visibleSize;
	cocos2d::extension::CCSkeletonAnimation* skeletonNode;
public:
	virtual bool init();
	CREATE_FUNC(RoleSprite);
};

#endif