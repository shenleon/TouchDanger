#ifndef __MAIN_SPRITE_LAYER_
#define __MAIN_SPRITE_LAYER_

#include "cocos2d.h"
#include "MainTouchDelegate.h"
#include "sprite\RoleSprite.h"
#include "sprite\NpcSprite.h"
#include "MainResourceDelegate.h"
#include "sprite\NpcTouchDelegate.h"
/*������ͬʱ���־���ĸ���*/
#define NPC_MAX 1

/*������ʾ��*/
class MainSpriteLayer : public cocos2d::CCLayer , public MainTouchDelegate ,public NpcTouchDelegate
{
private:
	cocos2d::CCLayer * dialog;
	NpcSprite * selectNpc;
protected:
	cocos2d::CCPoint origin;
	cocos2d::CCSize visibleSize;
	cocos2d::CCArray * npcs;
	cocos2d::CCTMXTiledMap * pMap;
public:
	CC_SYNTHESIZE(RoleSprite *, playerSprite, PlayerSprite);
	CC_SYNTHESIZE(NpcSprite *, npcSprite, NpcSprite);
	CC_SYNTHESIZE(MainResourceDelegate *, p_mMainResourceDelegate, MainResourceDelegate);
public:
	virtual bool init();
	virtual void onExit();
	/*������Ӧ*/
	virtual void singleTouchDirecting(cocos2d::CCPoint point);
	/*������Ӧ����*/
	virtual void singleTouchEndsIn(cocos2d::CCPoint point);
	/*npc�������*/
	virtual void touchNpc(const int tag);
	/*���һ��npc*/
	void addNpc();
	/*�Ƴ�һ��npc*/
	void removeNpc(NpcSprite * npc);
	/*����npc*/
	void updateNpc(float ft);
	/* ��������ѡ��˵� */
	void popMenuDialog(const char * msg);
	/*����ѡ��*/
	void touchSelect(cocos2d::CCObject * sender);
	CREATE_FUNC(MainSpriteLayer);
};

#endif