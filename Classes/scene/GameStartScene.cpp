#include "GameStartScene.h"

USING_NS_CC;

/*构建一个场景*/
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



