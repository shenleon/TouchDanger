#ifndef __GAME_START_LAYER_
#define __GAME_START_LAYER_

#include "cocos2d.h"

/*游戏开始面板*/
class GameStartLayer : public cocos2d::CCLayer
{
private:
	cocos2d::CCPoint origin;
	cocos2d::CCSize visibleSize;
public:
	virtual bool init();
	void menuCloseCallBack(cocos2d::CCObject * pSender);
	CREATE_FUNC(GameStartLayer);
};

#endif
