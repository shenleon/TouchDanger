#ifndef __PROP_NODE_
#define __PROP_NODE_

#include "cocos2d.h"
#include "bean\Prop.h"

/*��Ʒ��ʾ�ڵ�*/
class PropNode : public cocos2d::CCSprite
{
public:
	//��Ʒ����
	CC_SYNTHESIZE(Prop*,p_mProp,Prop);
public:
	virtual bool init();
	CREATE_FUNC(PropNode);
};

#endif