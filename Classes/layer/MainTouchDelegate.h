#ifndef __MAIN_TOUCH_DELEGATE_
#define __MAIN_TOUCH_DELEGATE_

#include "cocos2d.h"

class MainTouchDelegate
{
public:
	virtual void singleTouchDirecting(cocos2d::CCPoint point) = 0;
	virtual void singleTouchEndsIn(cocos2d::CCPoint point) = 0;
};



#endif