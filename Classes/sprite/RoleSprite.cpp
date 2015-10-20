#include "RoleSprite.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool RoleSprite::init()
{
	if (!CCSprite::init())
		return false;
	CCLOG("============= player init");
	this->setContentSize(CCSizeMake(90.0f,120.0f));
	/*CCLayerColor * pBg = CCLayerColor::create(ccc4(200,200,200,200));
	pBg->setContentSize(this->getContentSize());
	this->addChild(pBg,0);*/

	skeletonNode = CCSkeletonAnimation::createWithFile("spine/spineboy.json", "spine/spineboy.atlas");
	skeletonNode->setMix("stand", "walk", 0.4f);
	skeletonNode->setMix("walk", "jump", 0.4f);
	skeletonNode->setMix("jump", "walk", 0.4f);
	skeletonNode->setAnimation("walk", true);

	skeletonNode->timeScale = 0.3f;
	skeletonNode->debugBones = false;

	skeletonNode->setPosition(ccp(0.0f,20.0f));
	skeletonNode->setScale(0.3f, 0.3f);
	
	this->addChild(skeletonNode,1);
	
	skeletonNode->setPosition(ccp(this->getContentSize().width/2,0.0f));
	return true;
}

void RoleSprite::stop()
{
	skeletonNode->setAnimation("stand", true);
}