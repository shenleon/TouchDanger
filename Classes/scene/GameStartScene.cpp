#include "GameStartScene.h"

USING_NS_CC;

/*����һ������*/
bool GameStartScene::init()
{
	if (!CCScene::init())
		return false;
	GameStartLayer * startLayer = new GameStartLayer();
	startLayer->init();
	startLayer->autorelease();
	startLayer->retain();
	this->addChild(startLayer,1);
	return true;
}



