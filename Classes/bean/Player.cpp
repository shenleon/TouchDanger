#include "Player.h"

USING_NS_CC;

/** 角色信息静态引用  */
static Player * p_mPlayer;

Player * Player::player()
{
	if(p_mPlayer==NULL)
	{
		p_mPlayer = new Player();
		p_mPlayer->init();
	}
	return p_mPlayer;
}

void Player::init()
{
	CCString * name = CCString::create("name");
	name->retain();
	this->setName(name);
	CCPoolManager::sharedPoolManager()->push();
}

Player::Player(){}

Player::~Player()
{
	CCPoolManager::sharedPoolManager()->pop();
	CCPoolManager::purgePoolManager();
	p_mPlayer = NULL;
}