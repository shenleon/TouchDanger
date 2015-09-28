#include "MainTouchLayer.h"

USING_NS_CC;

bool MainTouchLayer::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		this->registerWithTouchDispatcher();
		this->setDelegate(NULL);
		bRet = true;
	} while (0);
	return bRet;
}


void MainTouchLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	if (pTouches->count() == 1)
	{
		CCTouch * touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		CCPoint position = touch->getLocationInView();
		position = CCDirector::sharedDirector()->convertToGL(position);
		if (this->getDelegate())
			this->getDelegate()->singleTouchDirecting(position);
	}
}

void MainTouchLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	if (pTouches->count() == 1)
	{
		CCTouch * touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		CCPoint position = touch->getLocationInView();
		position = CCDirector::sharedDirector()->convertToGL(position);
		if (this->getDelegate())
			this->getDelegate()->singleTouchDirecting(position);
	}
}

void MainTouchLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	if (pTouches->count() == 1)
	{
		CCTouch * touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		CCPoint position = touch->getLocationInView();
		position = CCDirector::sharedDirector()->convertToGL(position);
		if (this->getDelegate())
			this->getDelegate()->singleTouchEndsIn(position);
	}
}

void MainTouchLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
	
}

void MainTouchLayer::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}