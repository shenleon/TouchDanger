#include "NpcSprite.h"
#include "layer\MainSpriteLayer.h"
#include "utils\Utils.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum{
	ACTION_MOVE
};

bool NpcSprite::init()
{
	if (!CCSprite::init())
		return false;
	this->setContentSize(CCSizeMake(90.0f,130.0f));
	//设置背景色
	/*CCLayerColor * bg = CCLayerColor::create(ccc4(255, 0, 0, 100));
	bg->setContentSize(this->getContentSize());
	this->addChild(bg,0);*/
	skeletonNode = CCSkeletonAnimation::createWithFile("spine/spineboy.json", "spine/spineboy.atlas");
	skeletonNode->setMix("stand", "walk", 0.4f);
	skeletonNode->setMix("walk", "jump", 0.4f);
	skeletonNode->setMix("jump", "walk", 0.4f);
	skeletonNode->setAnimation("walk", true);

	skeletonNode->timeScale = 0.3f;
	skeletonNode->debugBones = false;

	skeletonNode->setPosition(ccp(0.0f,20.0f));
	skeletonNode->setScale(0.3f, 0.3f);
	skeletonNode->setRotationY(180.0f);
	this->addChild(skeletonNode,1);
	
	skeletonNode->setPosition(ccp(this->getContentSize().width/2,0.0f));
	return true;
}

void NpcSprite::onEnter()
{
	this->move();
	CCSprite::onEnter();
}

void NpcSprite::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}

void NpcSprite::move()
{
	CCAction * action = CCMoveTo::create(14.0f, ccp(0, this->getPositionY()));
	action->setTag(ACTION_MOVE);
	this->runAction(action);
}

void NpcSprite::stop()
{
	skeletonNode->setAnimation("stand", true);
	//添加头顶对话框
	CCLabelTTF * msg = CCLabelTTF::create(Utils::getCString("please_hold_me_str"),FONT_FZ,16);
	msg->setPosition(ccp(0,0));
	/*msg->setColor(ccc3(255.0f,0.0f,0.0f));*/
	CCLayerColor * msglab = CCLayerColor::create(ccc4(0,0,0,255),msg->getContentSize().width,msg->getContentSize().height);
	msg->setPosition(ccp(msglab->getContentSize().width/2,msglab->getContentSize().height/2));
	msglab->addChild(msg);
	msglab->setPosition(ccp(0,this->getContentSize().height-msglab->getContentSize().height));
	this->addChild(msglab,2);
	this->stopActionByTag(ACTION_MOVE);
}

bool NpcSprite::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point = pTouch->getLocationInView();
	point = CCDirector::sharedDirector()->convertToGL(point);
	float px = point.x , py = point.y;

	float _x = this->getPositionX();
	float _y = this->getPositionY();
	float _w = this->getContentSize().width;
	float _h = this->getContentSize().height;
	
	//CCLOG("px=%f,py=%f,_x=%f,_y=%f,_w=%f,_h=%f",px,py,_x,_y,_w,_h);

	if(px>=_x-_w/2&&px<=_x+_w/2&&py>=_y-_h/2&&py<=_y+_h/2)
	{
		this->getNpcTouchDelegate()->touchNpc(this->getTag());
		return true;
	}
	return false;
}