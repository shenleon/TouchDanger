#include "BundleLayer.h"

USING_NS_CC;

bool BundleLayer::init()
{
	if(!AlertLayer::init())
		return false;
	//��ʼ����Ʒ�б�
	CCArray * arr = CCArray::create();
	arr->retain();
	this->setPropNodeList(arr);
	return true;
}
