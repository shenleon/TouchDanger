#ifndef __PLAYER_
#define __PLAYER_

#include "cocos2d.h"
#include "sqlite3.h"

/** ��ɫ������ */
class Player : public cocos2d::CCObject
{
public:
	static Player * instance();
public:
	Player();
	~Player();
	//��ɫuid
	CC_SYNTHESIZE(char*,p_mUid,Uid);
	//��ɫ����
	CC_SYNTHESIZE(char*,p_mName,Name);
	//��Ʒ�б�
	CC_SYNTHESIZE(cocos2d::CCArray*,p_mPropList,PropList);
	//����
	CC_SYNTHESIZE(int,experience,Experience);
	//���
	CC_SYNTHESIZE(int,money,Money);
public:
	void init();
	//׼�����ݿ�
	sqlite3 * prepareDb();
	//��������
	void loadData();
	//�洢����
	void saveData();
};

#endif
