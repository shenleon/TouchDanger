#ifndef __BUNDLE_LAYER_
#define __BUNDLE_LAYER_

#include "AlertLayer.h"

/** ������� */
class BundleLayer : public AlertLayer
{
public:
	virtual bool init();
	CREATE_FUNC(BundleLayer);
};

#endif