#include "MainSpriteLayer.h"
#include "utils\Utils.h"

USING_NS_CC;

enum{
	ITEM_OK,//确认
	ITEM_CANCEL//取消
};

bool MainSpriteLayer::init()
{
	if (!CCLayer::init())
		return false;
	selectNpc = NULL;
	dialog = NULL;
	randomVal = RANDOM_MIN;
	//初始化随机种子
	srand(time(NULL));
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//添加背景底图
	/*pMap = CCTMXTiledMap::create("TileMaps/road.tmx");
	this->addChild(pMap, 0);*/
	CCSprite * bg = CCSprite::create("road.jpg");
	bg->setScaleX(visibleSize.width/bg->getContentSize().width);
	bg->setScaleY(visibleSize.height/bg->getContentSize().height);
	float _x = (visibleSize.width/bg->getContentSize().width)*bg->getContentSize().width;
	float _y = (visibleSize.height/bg->getContentSize().height)*bg->getContentSize().height;
	bg->setPosition(ccp(_x/2,_y/2));

	this->addChild(bg,0);
	//初始化npc列表
	npcs = CCArray::create();
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
	CCLayer::onExit();
}

void MainSpriteLayer::singleTouchDirecting(CCPoint point)
{
	
}

void MainSpriteLayer::singleTouchEndsIn(CCPoint point)
{
	
}

void MainSpriteLayer::addNpc()
{
	NpcSprite * npc = NpcSprite::create();
	int tag = time(NULL);
	npc->setName("npc");
	npc->setPosition(ccp(visibleSize.width, npc->getContentSize().height / 2 + 50));
	this->addChild(npc, 1, tag);
	npcs->addObject(npc);
	npc->setNpcTouchDelegate(this);
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
		//判断点击范围是否为npc
		if(npc->getPositionX() - npc->getContentSize().width/2 <= playerSprite->getPositionX()+playerSprite->getContentSize().width/2)
		{
			pauseSchedulerAndActions();
			playerSprite->stop();
			npc->stop();
			CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(npc, 0, false);
		}
	}
}

void MainSpriteLayer::touchNpc(const int tag)
{
	if(selectNpc!=NULL) return;
	CCNode * child = this->getChildByTag(tag);
	NpcSprite * npc = dynamic_cast<NpcSprite*>(child);
	if(npc!=NULL)
	{
		selectNpc = npc;
		npc->stopAllActions();
		//判断几率
		float rate = CCRANDOM_0_1()*100;
		CCLOG("rate = %f,randomVal=%f",rate,randomVal);
		if(rate <= randomVal)
		{
			randomVal --;
			if(randomVal <= RANDOM_MIN)
			{
				randomVal = RANDOM_MIN;
			}
			this->getMainResourceDelegate()->decrExperience(1);
			this->getMainResourceDelegate()->decrMoney(1);
			popMenuDialog(CCString::createWithFormat(Utils::getCString("bad_luck_str"),1,1)->getCString());
		}else
		{
			randomVal ++;
			if(randomVal >= RANDOM_MAX)
			{
				randomVal = RANDOM_MAX;
			}
			this->getMainResourceDelegate()->incrExperience(1);
			this->getMainResourceDelegate()->incrMoney(1);
			popMenuDialog(CCString::createWithFormat(Utils::getCString("good_luck_str"),1,1)->getCString());
		}
	}
}

/*弹出选择菜单*/
void MainSpriteLayer::popMenuDialog(const char * msg)
{
	dialog = CCLayerColor::create(ccc4(0,0,0,255));
	//添加说明文字
	CCLabelTTF * message = CCLabelTTF::create(msg,FONT_FZ,16);
	message->setPosition(ccp(visibleSize.width/2,visibleSize.height-50));
	dialog->addChild(message,0);
	//显示选择菜单
	CCLabelTTF * lab = CCLabelTTF::create(Utils::getCString("I_know_str"),FONT_FZ,16);
	CCMenuItemLabel * itemOk = CCMenuItemLabel::create(lab,this,menu_selector(MainSpriteLayer::touchSelect));
	CCMenu * menu = CCMenu::create();
	menu->addChild(itemOk,0,ITEM_OK);
	dialog->addChild(menu,0);
	this->getParent()->addChild(dialog,10);
}

void MainSpriteLayer::touchSelect(CCObject * sender)
{
	CCMenuItem * item = dynamic_cast<CCMenuItem*>(sender);
	if(item!=NULL)
	{
		if(item->getTag()==ITEM_OK)
		{
			npcs->removeObject(selectNpc);
			this->removeChild(selectNpc);
			selectNpc = NULL;
			this->getParent()->removeChild(dialog);
			dialog = NULL;
			resumeSchedulerAndActions();
		}
	}
}