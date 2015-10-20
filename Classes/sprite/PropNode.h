#ifndef __PROP_NODE_
#define __PROP_NODE_

#include "cocos2d.h"
#include "bean\Prop.h"

/*物品显示节点*/
class PropNode : public cocos2d::CCSprite
{
public:
	//物品数据
	CC_SYNTHESIZE(Prop*,p_mProp,Prop);
public:
	virtual bool init();
	CREATE_FUNC(PropNode);
};

#endif