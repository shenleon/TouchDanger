#ifndef __PLAYER_
#define __PLAYER_

#include "cocos2d.h"

/** ��ɫ������ */
class Player : public cocos2d::CCObject
{
public:
	static Player * player();
public:
	Player();
	~Player();
	//��ɫuid
	CC_SYNTHESIZE(cocos2d::CCString*,p_mUid,Uid);
	//��ɫ����
	CC_SYNTHESIZE(cocos2d::CCString*,p_mName,Name);
	//��Ʒ�б�
	CC_SYNTHESIZE(cocos2d::CCArray*,p_mPropList,PropList);
	void init();
};

#endif
