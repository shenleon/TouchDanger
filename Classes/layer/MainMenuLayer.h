#ifndef __MAIN_MENU_LAYER_
#define __MAIN_MENU_LAYER_

#include "cocos2d.h"

/*�����˵���ʾ��*/
class MainMenuLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();
	/*���ϵͳ�˵�*/
	void addSystemMenu();
	void systemMenuAction(cocos2d::CCObject * sender);
	CREATE_FUNC(MainMenuLayer);
};

#endif
