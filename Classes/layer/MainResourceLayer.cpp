#include "MainResourceLayer.h"
#include "utils\Utils.h"

USING_NS_CC;

bool MainResourceLayer::init()
{
	if (!CCLayer::init())
		return false;
	this->setExperience(0);
	this->setMoney(0);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCLayerColor * bg = CCLayerColor::create(ccc4(0, 0, 0, 255));
	bg->setContentSize(CCSizeMake(visibleSize.width, 45));
	bg->setPosition(ccp(0, visibleSize.height - bg->getContentSize().height / 2));
	this->addChild(bg, -1);
	//经验
	const char * experience_str = Utils::getCString("experience_str");
	CCLabelTTF * lifeLab = CCLabelTTF::create(CCString::createWithFormat(experience_str, this->getExperience())->getCString(), FONT_2, 16);
	lifeLab->setPosition(ccp(lifeLab->getContentSize().width / 2 + 20, visibleSize.height-lifeLab->getContentSize().height/2));
	this->addChild(lifeLab, 0, LAB_LIFE);
	//金钱
	const char * money_str = Utils::getCString("money_str");
	CCLabelTTF * moneyLab = CCLabelTTF::create(CCString::createWithFormat(money_str, this->getMoney())->getCString(), FONT_2, 16);
	moneyLab->setPosition(ccp(moneyLab->getContentSize().width / 2 + lifeLab->getContentSize().width + 100, visibleSize.height - moneyLab->getContentSize().height / 2));
	this->addChild(moneyLab, 0, LAB_MONEY);
	return true;
}

void MainResourceLayer::incrExperience(const int val)
{
	this->setExperience(this->getExperience() + val);
	this->updateExperienceShow();
}

void MainResourceLayer::decrExperience(const int val)
{
	this->setExperience(this->getExperience() - val);
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
		lab->setString(CCString::createWithFormat(experience_str, this->getExperience())->getCString());
	}
}

void MainResourceLayer::incrMoney(const int val)
{
	this->setMoney(this->getMoney() + val);
	this->updateMoneyShow();
}

void MainResourceLayer::decrMoney(const int val)
{
	this->setMoney(this->getMoney() - val);
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
		lab->setString(CCString::createWithFormat(money_str, this->getMoney())->getCString());
	}
}