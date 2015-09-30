#include "GameStartLayer.h"
#include "scene\GameMainScene.h"

USING_NS_CC;

bool GameStartLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCLOG("%f %f", origin.x, visibleSize.width);
	CCLOG("%f %f", origin.y, visibleSize.height);

	CCDictionary * strings = CCDictionary::createWithContentsOfFile("strings.xml");
	CCString * str = dynamic_cast<CCString*>(strings->objectForKey("start_str"));
	

	//添加一个开始按钮
	CCLabelTTF * pLab = CCLabelTTF::create(str->getCString(), "方针粗圆简体", 32);
	CCMenuItemLabel * pStartItem = CCMenuItemLabel::create(pLab, this, menu_selector(GameStartLayer::menuCloseCallBack));
	CCSize size = pStartItem->getContentSize();
	pStartItem->setPosition(ccp((origin.x + visibleSize.width - size.width / 2) / 2, (origin.y + visibleSize.height - size.height / 2) / 2));

	CCMenu * pMenu = CCMenu::create();
	pMenu->setPosition(CCPointZero);
	pMenu->addChild(pStartItem, 1, 1);
	this->addChild(pMenu, 1);

	CCLOG("%f", size.width);

	return true;
}

/* 切换场景 */
void transitionMainScene()
{
	GameMainScene * mainScene = GameMainScene::create();
	CCDirector::sharedDirector()->replaceScene(mainScene);
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
