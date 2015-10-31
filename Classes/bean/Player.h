#ifndef __PLAYER_
#define __PLAYER_

#include "cocos2d.h"
#include "sqlite3.h"

/** 角色数据类 */
class Player : public cocos2d::CCObject
{
public:
	static Player * instance();
public:
	Player();
	~Player();
	//角色uid
	CC_SYNTHESIZE(char*,p_mUid,Uid);
	//角色名称
	CC_SYNTHESIZE(char*,p_mName,Name);
	//物品列表
	CC_SYNTHESIZE(cocos2d::CCArray*,p_mPropList,PropList);
	//经验
	CC_SYNTHESIZE(int,experience,Experience);
	//金币
	CC_SYNTHESIZE(int,money,Money);
public:
	void init();
	//准备数据库
	sqlite3 * prepareDb();
	//加载数据
	void loadData();
	//存储数据
	void saveData();
};

#endif
