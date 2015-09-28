#include "RoleSprite.h"

USING_NS_CC;

bool RoleSprite::init()
{
	if (!CCSprite::init())
		return false;
	CCLOG("============= player init");

	return true;
}

RoleSprite * RoleSprite::create(const char *pszFileName, const CCRect& rect)
{
	RoleSprite *pobSprite = new RoleSprite();
	if (pobSprite && pobSprite->initWithFile(pszFileName, rect))
	{
		pobSprite->autorelease();
		return pobSprite;
	}
	CC_SAFE_DELETE(pobSprite);
	return NULL;
}