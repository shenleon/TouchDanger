#include "BundleLayer.h"

USING_NS_CC;

bool BundleLayer::init()
{
	if(!AlertLayer::init())
		return false;
	//初始化物品列表
	CCArray * arr = CCArray::create();
	arr->retain();
	this->setPropNodeList(arr);
	return true;
}
