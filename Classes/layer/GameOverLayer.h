#ifndef __GAME_OVER_LAYER_
#define __GAME_OVER_LAYER_

#include "cocos2d.h"

class GameOverLayer : public cocos2d::CCLayerColor
{
public:
	virtual bool init();
	void menuAction(cocos2d::CCObject * sender);
	CREATE_FUNC(GameOverLayer);
};

#endif

