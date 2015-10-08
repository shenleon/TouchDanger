#include "MainResourceLayer.h"
#include "utils\Utils.h"

USING_NS_CC;

bool MainResourceLayer::init()
{
	if (!CCLayer::init())
		return false;
	this->setLife(0);
	this->setMoney(0);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//ÑªÌõ
	CCLabelTTF * lifeLab = CCLabelTTF::create("Life:0", FONT_2, 16);
	lifeLab->setPosition(ccp(lifeLab->getContentSize().width / 2 + 20, visibleSize.height-lifeLab->getContentSize().height/2));
	this->addChild(lifeLab, 0, LAB_LIFE);
	//½ðÇ®
	CCLabelTTF * moneyLab = CCLabelTTF::create("Money:0", FONT_2, 16);
	moneyLab->setPosition(ccp(moneyLab->getContentSize().width / 2 + lifeLab->getContentSize().width + 100, visibleSize.height - moneyLab->getContentSize().height / 2));
	this->addChild(moneyLab, 0, LAB_MONEY);
	return true;
}

void MainResourceLayer::incrLife(int val)
{
	this->setLife(this->getLife() + val);
	this->updateLifeShow();
}

void MainResourceLayer::decrLife(int val)
{
	this->setLife(this->getLife() - val);
	this->updateLifeShow();
}

void MainResourceLayer::updateLifeShow()
{
	CCNode * node = this->getChildByTag(LAB_LIFE);
	CCLabelTTF * lab = dynamic_cast<CCLabelTTF*>(node);
	if (lab != NULL)
	{
		lab->setString(CCString::createWithFormat("Life:%d", this->getLife())->getCString());
	}
}

void MainResourceLayer::incrMoney(int val)
{
	this->setMoney(this->getMoney() + val);
	this->updateMoneyShow();
}

void MainResourceLayer::decrMoney(int val)
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
		lab->setString(CCString::createWithFormat("Money:%d", this->getMoney())->getCString());
	}
}