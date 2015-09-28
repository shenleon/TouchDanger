#ifndef __ROLE_SPRITE_
#define __ROLE_SPRITE_

#include "cocos2d.h"

/*½ÇÉ«¾«Áé*/
class RoleSprite : public cocos2d::CCSprite
{
public:
	static RoleSprite* create(const char *pszFileName, const cocos2d::CCRect& rect);
	virtual bool init();
	CREATE_FUNC(RoleSprite);
};

#endif