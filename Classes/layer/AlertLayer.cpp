#include "AlertLayer.h"
#include "utils\Utils.h"

USING_NS_CC;

/*菜单标签*/
enum MenuAction{
	ITEM_CLOSE
};

bool AlertLayer::init()
{
	if(!CCLayer::init())
		return false;
	pBackground = NULL;
	//设置面板背景
	this->setBackground(CCLayerColor::create(ccc4(0,0,0,255)));
	//显示区域大小
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//添加触摸时间，避免穿透到下层
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-100,true);
	//添加一个关闭按钮
	CCMenu * menu = CCMenu::create();
	menu->setPosition(CCPointZero);
	CCMenuItemImage * item = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",NULL,this,menu_selector(AlertLayer::action));
	item->setPosition(ccp(visibleSize.width-item->getContentSize().width/2,visibleSize.height-item->getContentSize().height/2));
	menu->addChild(item,0,ITEM_CLOSE);
	this->addChild(menu);
	return true;
}

void AlertLayer::setBackground(CCNode * _background)
{
	if(pBackground!=NULL)
	{
		pBackground->release();
		pBackground = NULL;
	}
	pBackground = _background;
	this->addChild(pBackground,-1);
}

void AlertLayer::action(CCObject * sender)
{
	CCMenuItem * item = dynamic_cast<CCMenuItem*>(sender);
	if(item==NULL) return;
	int tag = item->getTag();
	if(tag==ITEM_CLOSE)
	{
		this->removeFromParent();
	}
}

bool AlertLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void AlertLayer::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}
