#include "NpcSprite.h"
#include "layer\MainSpriteLayer.h"

USING_NS_CC;

bool NpcSprite::init()
{
	if (!CCSprite::init())
		return false;
	//ÉèÖÃ±³¾°É«
	CCLayerColor * bg = CCLayerColor::create(ccc4(255, 0, 0, 100));
	bg->setContentSize(CCSizeMake(200, 90));
	this->addChild(bg);
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	return true;
}

void NpcSprite::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool NpcSprite::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	pTouch->getLocationInView();
	return true;
}

void NpcSprite::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}

void NpcSprite::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	float t_fX = getPositionX() - getContentSize().width * getAnchorPoint().x;
	float t_fY = getPositionY() - getContentSize().height * getAnchorPoint().y;
	float t_fW = getContentSize().width;
	float t_fH = getContentSize().height;

	CCRect t_oRect = CCRect(t_fX, t_fY, t_fW, t_fH);
	t_oRect.origin = CCPointZero;

	CCPoint t_oPntPosi = convertTouchToNodeSpace(pTouch);
	CCLOG("================  npc touch %d", this->getTag());
	bool t_bIsTouched = t_oRect.containsPoint(t_oPntPosi);
	if (t_bIsTouched) {
		CCLOG("================  npc touch %d", this->getTag());
		MainSpriteLayer * layer = dynamic_cast<MainSpriteLayer*>(this->getParent());
		if (layer != NULL)
		{
			layer->removeNpc(this);
		}
	}
	else {
		
	}
}

void NpcSprite::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{

}