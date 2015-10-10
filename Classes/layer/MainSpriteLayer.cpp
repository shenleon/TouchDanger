#include "MainSpriteLayer.h"

USING_NS_CC;

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//添加背景底图
	pMap = CCTMXTiledMap::create("TileMaps/road.tmx");
	this->addChild(pMap, 0);
	//初始化npc列表
	npcs = new CCArray();
	npcs->autorelease();
	npcs->retain();
	//添加角色
	playerSprite = RoleSprite::create();
	playerSprite->setPosition(ccp(visibleSize.width*0.4, playerSprite->getContentSize().height / 2+50));
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
	this->getMainResourceDelegate()->incrExperience(100);
	playerSprite->stop();
}

void MainSpriteLayer::addNpc()
{
	NpcSprite * npc = NpcSprite::create();
	int tag = CCRANDOM_0_1()*100;
	npc->setName(CCString::create("npc"));
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
		CCPoint point = npc->getPosition();
		point = this->convertToNodeSpace(point);

		CCLOG("player x = %d",playerSprite->getPosition().x);

		CCLOG("x = %f,y=%f,name=%s", point.x, npc->getPositionY(), npc->getName());
		if (npc->getPositionX() <= 0)
		{
			this->removeNpc(npc);
		}
	}
}