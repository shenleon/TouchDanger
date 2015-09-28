#include "GameMainScene.h"

USING_NS_CC;

bool GameMainScene::init()
{
	if (!CCScene::init())
		return false;
	//添加精灵层
	spriteLayer = MainSpriteLayer::create();
	this->addChild(spriteLayer, 1);
	//添加菜单层
	menuLayer = MainMenuLayer::create();
	this->addChild(menuLayer, 2);
	//添加触点层
	touchLayer = MainTouchLayer::create();
	touchLayer->setDelegate(spriteLayer);
	this->addChild(touchLayer, 3);

	return true;
}