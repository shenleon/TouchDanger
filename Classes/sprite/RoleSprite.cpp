#include "RoleSprite.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool RoleSprite::init()
{
	if (!CCSprite::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCLOG("============= player init");
	this->setContentSize(CCSizeMake(114,165));
	this->setPosition(ccp(this->getContentSize().width / 2, this->getContentSize().height / 2));

	skeletonNode = CCSkeletonAnimation::createWithFile("spine/spineboy.json", "spine/spineboy.atlas");
	skeletonNode->setMix("walk", "jump", 0.4f);
	skeletonNode->setMix("jump", "walk", 0.4f);
	skeletonNode->setAnimation("walk", true);

	skeletonNode->timeScale = 0.3f;
	skeletonNode->debugBones = false;

	skeletonNode->setPosition(ccp(0,20));
	skeletonNode->setScale(0.3, 0.3);
	this->addChild(skeletonNode);

	CCAction * action = CCMoveTo::create(5.0f, ccp(visibleSize.width/2,this->getContentSize().height/2));
	this->runAction(action);

	return true;
}
