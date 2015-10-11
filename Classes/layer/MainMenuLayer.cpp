#include "MainMenuLayer.h"
#include "utils\Utils.h"

USING_NS_CC;

enum{
	ITEM_SYSTEM,
	ITEM_BUNDLE
};

bool MainMenuLayer::init()
{
	if (!CCLayer::init())
		return false;
	this->addSystemMenu();
	return true;
}

void MainMenuLayer::addSystemMenu()
{
	CCSize visbleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCMenu * menu = CCMenu::create();
	GLfloat _x = 0, _y = 0;
	//½ÇÉ«
	CCLabelTTF * pLab = CCLabelTTF::create(Utils::getCString("player_str"), FONT_FZ, 24);
	pLab->setColor(ccc3(255,0,0));
	CCMenuItemLabel * item = CCMenuItemLabel::create(pLab, this, menu_selector(MainMenuLayer::systemMenuAction));
	item->setTag(ITEM_SYSTEM);
	_x = item->getContentSize().width / 2 - visbleSize.width / 2;
	_y = item->getContentSize().height / 2 - visbleSize.height / 2;
	item->setPosition(ccp(_x, _y));
	menu->addChild(item);
	//°ü¹ü
	pLab = CCLabelTTF::create(Utils::getCString("bundle_str"), FONT_FZ, 24);
	pLab->setColor(ccc3(255,0,0));
	item = CCMenuItemLabel::create(pLab, this, menu_selector(MainMenuLayer::systemMenuAction));
	item->setTag(ITEM_BUNDLE);
	_x += item->getContentSize().width+10;
	item->setPosition(ccp(_x, _y));
	menu->addChild(item);

	this->addChild(menu);
}

void MainMenuLayer::systemMenuAction(cocos2d::CCObject * sender)
{
	CCMenuItem * item = dynamic_cast<CCMenuItem*>(sender);
	if (item == NULL) return;
	if (item->getTag() == ITEM_SYSTEM)
	{
		CCLOG("===========system");
	}
	else if (item->getTag() == ITEM_BUNDLE)
	{
		CCLOG("=============bundle");
	}
}
