#ifndef __GAME_START_SCENE_
#define __GAME_START_SCENE_

#include "layer\GameStartLayer.h"

class GameStartScene : public cocos2d::CCScene
{
public:
	virtual bool init();
	CREATE_FUNC(GameStartScene);
};

#endif