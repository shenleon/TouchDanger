#ifndef __PROP_
#define __PROP_

#include "cocos2d.h"

/*物品数据类*/
class Prop : public cocos2d::CCObject
{
public:
	//物品uid
	CC_SYNTHESIZE(cocos2d::CCString*,p_mUid,Uid);
	//物品名称
	CC_SYNTHESIZE(cocos2d::CCString*,p_mName,Name);
};

#endif
