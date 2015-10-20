#ifndef __PLAYER_
#define __PLAYER_

#include "cocos2d.h"

/** 角色数据类 */
class Player : public cocos2d::CCObject
{
public:
	static Player * player();
public:
	Player();
	~Player();
	//角色uid
	CC_SYNTHESIZE(cocos2d::CCString*,p_mUid,Uid);
	//角色名称
	CC_SYNTHESIZE(cocos2d::CCString*,p_mName,Name);
	//物品列表
	CC_SYNTHESIZE(cocos2d::CCArray*,p_mPropList,PropList);
	void init();
};

#endif
