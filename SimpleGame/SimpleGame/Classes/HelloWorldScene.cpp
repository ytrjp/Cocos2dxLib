#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::node();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false;
	}

    //add a ninjia sprite to the left screen center
    CCSprite *ninjiaSprite = CCSprite::spriteWithFile("Player.png");
    CCDirector *director = CCDirector::sharedDirector();
    CCSize screenSize = director->getWinSize();
    ninjiaSprite->setPosition(ccp(ninjiaSprite->getContentSize().width / 2.0f,
                              screenSize.height / 2.0f));
    this->addChild(ninjiaSprite);
    
    CCSprite *targetSprite = CCSprite::spriteWithFile("Target.png");
    targetSprite->setPosition(ccp(screenSize.width / 2.0f, screenSize.height / 2.0f));
    this->addChild(targetSprite);
    
    
//    this->schedule(schedule_selector())
	
	
	return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
