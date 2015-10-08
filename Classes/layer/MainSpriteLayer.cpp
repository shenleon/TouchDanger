#include "MainSpriteLayer.h"

USING_NS_CC;

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//��ӽ�ɫ
	playerSprite = RoleSprite::create();
	playerSprite->setPosition(ccp(visibleSize.width/2, playerSprite->getContentSize().height / 2+30));
	this->addChild(playerSprite);
	//��ʼ��npc�б�
	npcs = CCArray::create();
	//����npc����¼�
	this->schedule(schedule_selector(MainSpriteLayer::updateNpc), 3, 10, 0);
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
	npc->setPosition(ccp(visibleSize.width - npc->getContentSize().width / 2, npc->getContentSize().height / 2 + 30));
	this->addChild(npc, 1, time(NULL));
	npcs->addObject(npc);

	CCAction * action = CCMoveTo::create(5.0f, ccp(visibleSize.width / 2, npc->getPositionY()));
	npc->runAction(action);

}

void MainSpriteLayer::updateNpc(float ft)
{
	this->addNpc();
}