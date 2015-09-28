#include "GameMainScene.h"

USING_NS_CC;

bool GameMainScene::init()
{
	if (!CCScene::init())
		return false;
	//��Ӿ����
	spriteLayer = MainSpriteLayer::create();
	this->addChild(spriteLayer, 1);
	//��Ӳ˵���
	menuLayer = MainMenuLayer::create();
	this->addChild(menuLayer, 2);
	//��Ӵ����
	touchLayer = MainTouchLayer::create();
	touchLayer->setDelegate(spriteLayer);
	this->addChild(touchLayer, 3);

	return true;
}