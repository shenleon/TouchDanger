#include "GameStartLayer.h"
#include "scene\GameMainScene.h"
#include "utils\Utils.h"

USING_NS_CC;

bool GameStartLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	//添加一个开始按钮
	CCLabelTTF * pLab = CCLabelTTF::create(Utils::getCString("start_str"), FONT_FZ, 32);
	CCMenuItemLabel * pStartItem = CCMenuItemLabel::create(pLab, this, menu_selector(GameStartLayer::menuCloseCallBack));
	CCSize size = pStartItem->getContentSize();
	pStartItem->setPosition(ccp((origin.x + visibleSize.width - size.width / 2) / 2, (origin.y + visibleSize.height - size.height / 2) / 2));

	CCMenu * pMenu = CCMenu::create();
	pMenu->setPosition(CCPointZero);
	pMenu->addChild(pStartItem, 1, 1);
	this->addChild(pMenu, 1);

	return true;
}

/* 切换场景 */
void transitionMainScene()
{
	GameMainScene * mainScene = GameMainScene::create();
	CCTransitionPageTurn * pageTurn = CCTransitionPageTurn::create(0.5, mainScene, false);
	CCDirector::sharedDirector()->replaceScene(pageTurn);
}

void GameStartLayer::menuCloseCallBack(cocos2d::CCObject * pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
#else
	transitionMainScene();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}
