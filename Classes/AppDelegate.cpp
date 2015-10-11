#include "AppDelegate.h"
#include "scene/GameStartScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	//CCSize frameSize = pEGLView->getFrameSize();
	//CCSize winSize = CCSize(480,320);
	//float widthRate = frameSize.width/winSize.width;
	//float heightRate = frameSize.height/winSize.height;

	//if (widthRate > heightRate)
	//{
	//        //里边传入的前俩个参数就是逻辑分辨率的大小，也就是通过getWinSize()得到的大小
	//        pEGLView->setDesignResolutionSize(winSize.width,
	//            winSize.height*heightRate/widthRate, kResolutionNoBorder);
	//}
	//else
	//{
	//        pEGLView->setDesignResolutionSize(winSize.width*widthRate/heightRate, winSize.height,
	//            kResolutionNoBorder);
	// }

    // create a scene. it's an autorelease object
	CCScene *pScene = GameStartScene::create();
    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
