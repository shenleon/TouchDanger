#include "MainSpriteLayer.h"

USING_NS_CC;

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//Ìí¼Ó½ÇÉ«
	playerSprite = RoleSprite::create("baihu.png", CCRectMake(0, 0, 114, 165));
	playerSprite->setPosition(ccp(playerSprite->getContentSize().width / 2, playerSprite->getContentSize().height / 2));
	this->addChild(playerSprite);
	CCAction * action = CCJumpTo::create(0.5f, ccp(visibleSize.width/2,playerSprite->getContentSize().height/2),visibleSize.height/2,1);
	playerSprite->runAction(action);

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