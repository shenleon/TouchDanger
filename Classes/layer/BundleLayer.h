#ifndef __BUNDLE_LAYER_
#define __BUNDLE_LAYER_

#include "AlertLayer.h"

/** °ü¹üÃæ°å */
class BundleLayer : public AlertLayer
{
public:
	virtual bool init();
	CREATE_FUNC(BundleLayer);
};

#endif