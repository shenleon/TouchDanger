#include "MainSpriteLayer.h"

USING_NS_CC;

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//添加背景底图
	CCTMXTiledMap * map = CCTMXTiledMap::create("map/road.tmx");
	this->addChild(map, 1, 1);	
	//map->setAnchorPoint(ccp(0.5f, 0.5f));
	//map->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));

	//CCLayerColor * bg = CCLayerColor::create(ccc4(0, 255, 0, 100));
	//bg->setContentSize(visibleSize);
	////bg->setAnchorPoint(ccp(0.5f, 0.5f));
	//bg->setPosition(ccp(0,0));
	//this->addChild(bg);

	//初始化npc列表
	npcs = new CCArray();
	npcs->autorelease();
	npcs->retain();
	//添加角色
	playerSprite = RoleSprite::create();
	playerSprite->setPosition(ccp(visibleSize.width*0.4, playerSprite->getContentSize().height / 2+30));
	this->addChild(playerSprite);
	//启动npc添加事件
	this->schedule(schedule_selector(MainSpriteLayer::updateNpc), 1);
	return true;
}

void MainSpriteLayer::onExit()
{
	npcs->removeAllObjects();
	npcs = NULL;
}

void MainSpriteLayer::singleTouchDirecting(CCPoint point)
{
	this->getMainResourceDelegate()->incrMoney(1);
}

void MainSpriteLayer::singleTouchEndsIn(CCPoint point)
{
	this->getMainResourceDelegate()->incrLife(100);
	playerSprite->stop();
}

void MainSpriteLayer::addNpc()
{
	NpcSprite * npc = NpcSprite::create();
	int tag = time(NULL);
	npc->setName(CCString::createWithFormat("npc%d",tag));
	npc->setPosition(ccp(visibleSize.width - npc->getContentSize().width / 2, npc->getContentSize().height / 2 + 30));
	this->addChild(npc, 1, tag);
	npcs->addObject(npc);
	CCAction * action = CCMoveTo::create(10.0f, ccp(0, npc->getPositionY()));
	npc->runAction(action);
}

void MainSpriteLayer::removeNpc(NpcSprite * npc)
{
	this->removeChild(npc);
	npcs->removeObject(npc);
	npc = NULL;
}

void MainSpriteLayer::updateNpc(float ft)
{
	int n = npcs->count();
	if (n < NPC_MAX)
	{
		this->addNpc();
	}
	CCObject * obj = NULL;
	NpcSprite * npc = NULL;
	CCARRAY_FOREACH(npcs, obj)
	{
		if (obj == NULL) continue;
		npc = dynamic_cast<NpcSprite*>(obj);
		if (npc == NULL) continue;
		CCLOG("x = %d,y=%d,name=%s", npc->getPositionX(),npc->getPositionY(),npc->getName()->getCString());
		if (npc->getPositionX() <= 0)
		{
			this->removeNpc(npc);
		}
	}
}