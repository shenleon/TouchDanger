#include "GameMainScene.h"

USING_NS_CC;

bool GameMainScene::init()
{
	if (!CCScene::init())
		return false;
	//������ʲ�
	resourceLayer = MainResourceLayer::create();
	this->addChild(resourceLayer, 3);
	//��Ӿ����
	spriteLayer = MainSpriteLayer::create();
	spriteLayer->setMainResourceDelegate(resourceLayer);
	this->addChild(spriteLayer, 1);
	//��Ӳ˵���
	menuLayer = MainMenuLayer::create();
	this->addChild(menuLayer, 2);
	//��Ӵ����
	touchLayer = MainTouchLayer::create();
	touchLayer->setDelegate(spriteLayer);
	this->addChild(touchLayer, 4);

	return true;
}

void GameMainScene::onExit()
{
	spriteLayer = NULL;
	menuLayer = NULL;
	touchLayer = NULL;
	resourceLayer = NULL;
	CCScene::onExit();
}