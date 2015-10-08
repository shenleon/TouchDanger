#ifndef __UTILS_
#define __UTILS_

#include "cocos2d.h"

#define FONT_FZ "·½Õý´ÖÔ²¼òÌå"
#define FONT_2 "Arial"

class Utils : public cocos2d::CCObject
{
public:
	static cocos2d::CCString * getString(const std::string& key);
	static const char * getCString(const std::string& key);
	~Utils();
};

#endif
