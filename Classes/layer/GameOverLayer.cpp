#include "GameOverLayer.h"
#include "utils\Utils.h"
#include "scene\GameMainScene.h"

USING_NS_CC;

bool GameOverLayer::init()
{
	if(!CCLayerColor::init())
		return false;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//Ìí¼ÓÃèÊö
	CCLabelTTF * message = CCLabelTTF::create(Utils::getCString("game_over_str"),FONT_FZ,16);
	message->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	this->addChild(message);
	//Ìí¼Ó²Ëµ¥
	CCMenu * menu = CCMenu::create();
	CCLabelTTF * lab = CCLabelTTF::create(Utils::getCString("try_again_str"),FONT_FZ,16);
	CCMenuItemLabel * item = CCMenuItemLabel::create(lab,this,menu_selector(GameOverLayer::menuAction));
	item->setPosition(ccp(0.0f,-2*item->getContentSize().height));
	menu->addChild(item);
	this->addChild(menu);
	return true;
}

void GameOverLayer::menuAction(CCObject * sender)
{
	GameMainScene * mainScene = GameMainScene::create();
	CCTransitionFade * fade = CCTransitionFade::create(2.0f,mainScene);
	CCDirector::sharedDirector()->replaceScene(fade);
}