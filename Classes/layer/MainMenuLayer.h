#ifndef __MAIN_MENU_LAYER_
#define __MAIN_MENU_LAYER_

#include "cocos2d.h"

/*主面板菜单显示层*/
class MainMenuLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();
	/*添加系统菜单*/
	void addSystemMenu();
	void systemMenuAction(cocos2d::CCObject * sender);
	CREATE_FUNC(MainMenuLayer);
};

#endif
