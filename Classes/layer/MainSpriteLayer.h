#ifndef __MAIN_SPRITE_LAYER_
#define __MAIN_SPRITE_LAYER_

#include "cocos2d.h"
#include "MainTouchDelegate.h"
#include "sprite\RoleSprite.h"
#include "sprite\NpcSprite.h"
#include "MainResourceDelegate.h"

/*æ´¡Èœ‘ æ≤„*/
class MainSpriteLayer : public cocos2d::CCLayer , public MainTouchDelegate
{
protected:
	cocos2d::CCPoint origin;
	cocos2d::CCSize visibleSize;
public:
	CC_SYNTHESIZE(RoleSprite *, playerSprite, PlayerSprite);
	CC_SYNTHESIZE(NpcSprite *, npcSprite, NpcSprite);
	CC_SYNTHESIZE(MainResourceDelegate *, p_mMainResourceDelegate, MainResourceDelegate);
public:
	virtual bool init();
	virtual void singleTouchDirecting(cocos2d::CCPoint point);
	virtual void singleTouchEndsIn(cocos2d::CCPoint point);
	CREATE_FUNC(MainSpriteLayer);
};

#endif