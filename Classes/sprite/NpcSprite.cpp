#include "NpcSprite.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool NpcSprite::init()
{
	if (!CCSprite::init())
		return false;

	skeletonNode = CCSkeletonAnimation::createWithFile("spine/spineboy.json", "spine/spineboy.atlas");
	skeletonNode->setMix("walk", "jump", 0.4f);
	skeletonNode->setMix("jump", "walk", 0.4f);
	skeletonNode->setAnimation("walk", true);

	skeletonNode->timeScale = 0.3f;
	skeletonNode->debugBones = false;

	skeletonNode->setPosition(ccp(0, 20));
	skeletonNode->setScale(0.3, 0.3);
	skeletonNode->setRotationY(180);
	this->addChild(skeletonNode);
	this->setContentSize(skeletonNode->getContentSize());

	return true;
}
