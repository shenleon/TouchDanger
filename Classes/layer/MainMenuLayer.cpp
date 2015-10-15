#include "MainMenuLayer.h"
#include "utils\Utils.h"
#include "RoleLayer.h"
#include "BundleLayer.h"

USING_NS_CC;

enum{
	ITEM_ROLE,
	ITEM_BUNDLE
};

bool MainMenuLayer::init()
{
	if (!CCLayer::init())
		return false;
	//添加系统菜单
	this->addSystemMenu();
	return true;
}

void MainMenuLayer::addSystemMenu()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCMenu * menu = CCMenu::create();
	menu->setPosition(CCPointZero);
	GLfloat _x = 0, _y = 0;
	//角色
	CCLabelTTF * pLab = CCLabelTTF::create(Utils::getCString("player_str"), FONT_FZ, 24);
	pLab->setColor(ccc3(255,0,0));
	CCMenuItemLabel * item = CCMenuItemLabel::create(pLab, this, menu_selector(MainMenuLayer::systemMenuAction));
	item->setTag(ITEM_ROLE);
	_x = item->getContentSize().width/2;
	_y = item->getContentSize().height/2;
	item->setPosition(ccp(_x,_y));
	menu->addChild(item);
	//包裹
	pLab = CCLabelTTF::create(Utils::getCString("bundle_str"), FONT_FZ, 24);
	pLab->setColor(ccc3(255,0,0));
	item = CCMenuItemLabel::create(pLab, this, menu_selector(MainMenuLayer::systemMenuAction));
	item->setTag(ITEM_BUNDLE);
	_x += item->getContentSize().width;
	item->setPosition(ccp(_x, _y));
	menu->addChild(item);
	//设置一个背景
	CCLayerColor * bg = CCLayerColor::create(ccc4(0,0,0,255));
	bg->setContentSize(CCSizeMake(visibleSize.width,item->getContentSize().height));
	bg->setPosition(ccp(0,0));
	this->addChild(bg,-1);
	this->addChild(menu);
}

void MainMenuLayer::systemMenuAction(cocos2d::CCObject * sender)
{
	CCMenuItem * item = dynamic_cast<CCMenuItem*>(sender);
	if (item == NULL) return;
	if (item->getTag() == ITEM_ROLE)
	{
		//打开角色面板
		RoleLayer * roleLayer = RoleLayer::create();
		this->getParent()->addChild(roleLayer,10);
	}
	else if (item->getTag() == ITEM_BUNDLE)
	{
		//打开包裹面板
		BundleLayer * bundleLayer = BundleLayer::create();
		this->getParent()->addChild(bundleLayer,10);
	}
}
