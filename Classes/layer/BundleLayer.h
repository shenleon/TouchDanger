#ifndef __BUNDLE_LAYER_
#define __BUNDLE_LAYER_

#include "AlertLayer.h"

/** ������� */
class BundleLayer : public AlertLayer
{
protected:
	CC_SYNTHESIZE(cocos2d::CCArray*,p_mPropNodeList,PropNodeList);
public:
	virtual bool init();
	CREATE_FUNC(BundleLayer);
};

#endif