#include "MainSpriteLayer.h"

USING_NS_CC;

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//添加角色
	playerSprite = RoleSprite::create();
	playerSprite->setPosition(ccp(visibleSize.width/2, playerSprite->getContentSize().height / 2+30));
	this->addChild(playerSprite);
	//初始化npc列表
	npcs = CCArray::create();
	//启动npc添加事件
	this->schedule(schedule_selector(MainSpriteLayer::updateNpc),1);
	return true;
}

void MainSpriteLayer::singleTouchDirecting(CCPoint point)
{
	this->getMainResourceDelegate()->incrMoney(1);
}

void MainSpriteLayer::singleTouchEndsIn(CCPoint point)
{
	this->getMainResourceDelegate()->incrLife(100);
}

void MainSpriteLayer::addNpc()
{
	NpcSprite * npc = NpcSprite::create();
	npc->setPosition(ccp(npc->getContentSize().width / 2, npc->getContentSize().height / 2));
	npcs->addObject(npc);
	this->addChild(npc, 1, time(NULL));

	CCAction * action = CCMoveTo::create(5.0f, ccp(visibleSize.width/2,this->getContentSize().height/2));
	npc->runAction(action);

}

void MainSpriteLayer::updateNpc(float ft)
{
	
}