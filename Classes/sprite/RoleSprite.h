#ifndef __ROLE_SPRITE_
#define __ROLE_SPRITE_

#include "cocos2d.h"
#include <spine/spine-cocos2dx.h>

/*½ÇÉ«¾«Áé*/
class RoleSprite : public cocos2d::CCSprite
{
protected:
	cocos2d::extension::CCSkeletonAnimation* skeletonNode;
public:
	virtual bool init();
	void stop();
	void walk();
	CREATE_FUNC(RoleSprite);
};

#endif