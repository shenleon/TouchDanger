#include "GameStartScene.h"

USING_NS_CC;

/*构建一个场景*/
bool GameStartScene::init()
{
	if (!CCScene::init())
		return false;
	GameStartLayer * startLayer = GameStartLayer::create();
	startLayer->initWithColor(ccc4(255,0,0,100));
	this->addChild(startLayer,1);
	return true;
}



