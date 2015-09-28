#include "MainSpriteLayer.h"

USING_NS_CC;

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//Ìí¼Ó½ÇÉ«
	playerSprite = new RoleSprite();
	playerSprite->init();
	playerSprite->autorelease();
	playerSprite->setPosition(ccp(playerSprite->getContentSize().width / 2, playerSprite->getContentSize().height / 2));
	this->addChild(playerSprite);

	return true;
}

void MainSpriteLayer::singleTouchDirecting(CCPoint point)
{
	CCLOG("==========================move: x= %f,y=%f",point.x,point.y);

}

void MainSpriteLayer::singleTouchEndsIn(CCPoint point)
{
	CCLOG("==========================end: x= %f,y=%f", point.x, point.y);
}