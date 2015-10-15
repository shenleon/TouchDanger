#include "AlertLayer.h"
#include "utils\Utils.h"

USING_NS_CC;

/*�˵���ǩ*/
enum MenuAction{
	ITEM_CLOSE
};

bool AlertLayer::init()
{
	if(!CCLayer::init())
		return false;
	pBackground = NULL;
	//������屳��
	this->setBackground(CCLayerColor::create(ccc4(0,0,0,255)));
	//��ʾ�����С
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//��Ӵ���ʱ�䣬���⴩͸���²�
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-100,true);
	//���һ���رհ�ť
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
