#ifndef __PROP_
#define __PROP_

#include "cocos2d.h"

/*��Ʒ������*/
class Prop : public cocos2d::CCObject
{
public:
	//��Ʒuid
	CC_SYNTHESIZE(cocos2d::CCString*,p_mUid,Uid);
	//��Ʒ����
	CC_SYNTHESIZE(cocos2d::CCString*,p_mName,Name);
};

#endif
