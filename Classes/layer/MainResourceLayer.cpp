#include "MainResourceLayer.h"
#include "GameOverLayer.h"
#include "utils\Utils.h"
#include "bean\Player.h"

USING_NS_CC;

bool MainResourceLayer::init()
{
	if (!CCLayer::init())
		return false;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCLayerColor * bg = CCLayerColor::create(ccc4(0, 0, 0, 255));
	bg->setContentSize(CCSizeMake(visibleSize.width, 45));
	bg->setPosition(ccp(0, visibleSize.height - bg->getContentSize().height / 2));
	this->addChild(bg, -1);
	//经验
	const char * experience_str = Utils::getCString("experience_str");
	CCLabelTTF * lifeLab = CCLabelTTF::create(CCString::createWithFormat(experience_str, Player::instance()->getExperience())->getCString(), FONT_2, 16);
	lifeLab->setPosition(ccp(lifeLab->getContentSize().width / 2 + 20, visibleSize.height-lifeLab->getContentSize().height/2));
	this->addChild(lifeLab, 0, LAB_LIFE);
	//金钱
	const char * money_str = Utils::getCString("money_str");
	CCLabelTTF * moneyLab = CCLabelTTF::create(CCString::createWithFormat(money_str, Player::instance()->getMoney())->getCString(), FONT_2, 16);
	moneyLab->setPosition(ccp(moneyLab->getContentSize().width / 2 + lifeLab->getContentSize().width + 100, visibleSize.height - moneyLab->getContentSize().height / 2));
	this->addChild(moneyLab, 0, LAB_MONEY);
	return true;
}

void MainResourceLayer::incrExperience(const int val)
{
	int experience = Player::instance()->getExperience();
	Player::instance()->setExperience(experience+val);
	Player::instance()->saveData();
	this->updateExperienceShow();
}

void MainResourceLayer::decrExperience(const int val)
{
	int experience = Player::instance()->getExperience();
	Player::instance()->setExperience(experience-val<0?0:(experience-val));
	Player::instance()->saveData();
	this->updateExperienceShow();
}

void MainResourceLayer::updateExperienceShow()
{
	CCNode * node = this->getChildByTag(LAB_LIFE);
	CCLabelTTF * lab = dynamic_cast<CCLabelTTF*>(node);
	if (lab != NULL)
	{
		//经验
		const char * experience_str = Utils::getCString("experience_str");
		lab->setString(CCString::createWithFormat(experience_str, Player::instance()->getExperience())->getCString());
	}
}

void MainResourceLayer::incrMoney(const int val)
{
	int money = Player::instance()->getMoney();
	Player::instance()->setMoney(money+val);
	Player::instance()->saveData();
	this->updateMoneyShow();
}

void MainResourceLayer::decrMoney(const int val)
{
	int money = Player::instance()->getMoney();
	Player::instance()->setMoney(money-val<0?0:(money-val));
	Player::instance()->saveData();
	if(Player::instance()->getMoney()<=0)
	{
		GameOverLayer * layer = GameOverLayer::create();
		layer->initWithColor(ccc4(0,0,0,255));
		this->getParent()->addChild(layer,20);
	}
	this->updateMoneyShow();
}

void MainResourceLayer::updateMoneyShow()
{
	CCNode * node = this->getChildByTag(LAB_MONEY);
	CCLabelTTF * lab = dynamic_cast<CCLabelTTF*>(node);
	if (lab != NULL)
	{
		//金钱
		const char * money_str = Utils::getCString("money_str");
		lab->setString(CCString::createWithFormat(money_str, Player::instance()->getMoney())->getCString());
	}
}