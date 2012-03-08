#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#import "GameOverScene.h"


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

void HelloWorld::addTarget()
{
    //1.create a target sprite & add it to the layer
    CCSprite *targetSprite = CCSprite::spriteWithFile("Target.png");
    targetSprite->setTag(1);
    this->addChild(targetSprite);
    
    _targets->addObject(targetSprite);
    
    
    
    //2.caculate the sprite spawn position
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float targetWidth =  winSize.width + targetSprite->getContentSize().width / 2.0f;
    float targetMinY = targetSprite->getContentSize().height / 2.0f;
    float targetMaxY = winSize.height - targetSprite->getContentSize().height / 2.0f;
    float targetHeight = rand() % (int)(targetMaxY - targetMinY) + targetMinY;
 
    targetSprite->setPosition(ccp(targetWidth,targetHeight));
    
    
    //3.caculate the sprite spawn speed
    int minDuration = 2;
    int maxDuration = 4;
    int actualDuration = rand() % (maxDuration - minDuration) + minDuration;
    
    //4.run a sequence action with a callback to remove the sprite 
    CCSize targetSize = targetSprite->getContentSize();
    CCMoveTo *moveAc = CCMoveTo::actionWithDuration(actualDuration, ccp(-targetSize.width / 2.0f, targetHeight));
//    int* data = new int(10);
    //int data = 10;  //tips:!! don't use stack variable to pass value
    
    
    
    CCCallFuncN *moveDone = CCCallFuncN::actionWithTarget(this, 
                                                            callfuncN_selector(HelloWorld::spriteMoveFinished));
    targetSprite->runAction(CCSequence::actions(moveAc,moveDone,NULL));
}

void HelloWorld::removeTarget(CCNode* sprite,int* data)
{
//    CCSprite *targetSprite = (CCSprite*)sprite;
    this->removeChild(sprite, true);
//    CCLOG("removeTarget! tag = %d, data =%d",sprite->getTag(),*data);
}



// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first with a colored background
	if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false;
	}

    //2.add a ninjia sprite to the left screen center
    CCSprite *ninjiaSprite = CCSprite::spriteWithFile("Player.png");
    CCDirector *director = CCDirector::sharedDirector();
    CCSize screenSize = director->getWinSize();
    ninjiaSprite->setPosition(ccp(ninjiaSprite->getContentSize().width / 2.0f,
                              screenSize.height / 2.0f));
    this->addChild(ninjiaSprite);
    
   //3.init the rand seed
    srand(time(NULL));
    
//    this->addTarget();
    //4.schedule the game logic tick method
    this->schedule(schedule_selector(HelloWorld::gameLogic),1.0f);
    
    
    //5. activate the touch 
    this->setIsTouchEnabled(true);
    
    _targets = CCArray::arrayWithCapacity(20);
    _targets->retain();
    
    _projectiles = CCArray::arrayWithCapacity(20);
    _projectiles->retain();
    
    schedule(schedule_selector(HelloWorld::update));
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background-music-aac.caf",true);
	
	return true;
}

void HelloWorld::update(ccTime dt)
{
    CCArray *projectilesToDelete = CCArray::array();
    
    CCObject *projectile_obj;
    CCARRAY_FOREACH(_projectiles, projectile_obj)
    {
        CCSprite *projectile = (CCSprite*)projectile_obj;
        CCRect projectRect = CCRectMake(projectile->getPosition().x - projectile->getContentSize().width /2.0,
                                        projectile->getPosition().y - projectile->getContentSize().height /2.0, projectile->getContentSize().width, 
                                        projectile->getContentSize().height);
        
        CCObject *target_obj;
        
        CCArray *targetsToDelete = CCArray::array();
        
        CCARRAY_FOREACH(_targets, target_obj)
        {
            CCSprite *target = (CCSprite*)target_obj;
            CCRect targetRect = CCRectMake(target->getPosition().x - target->getContentSize().width /2.0f, 
                                           target->getPosition().y - target->getContentSize().height/2.0f, 
                                           target->getContentSize().width, 
                                           target->getContentSize().height);
            
            if (CCRect::CCRectIntersectsRect(projectRect, targetRect)) {
                targetsToDelete->addObject(target);
            }
        }
        
        CCARRAY_FOREACH(targetsToDelete, target_obj)
        {
            CCSprite *target = (CCSprite*)target_obj;
            _targets->removeObject(target);
            this->removeChild(target, true);
            
            _projectilesDestroyed++;
            
            if (_projectilesDestroyed > 3) {
                CCScene *gameOver = GameOverScene::scene();
                GameOverScene *layer = (GameOverScene*)gameOver->getChildren()->objectAtIndex(0);
                layer->getLabel()->setString("You Win!");
                CCDirector::sharedDirector()->replaceScene(gameOver);
            }
        }
        
        if (targetsToDelete->count() > 0) {
            projectilesToDelete->addObject(projectile);
        }
    }
    
    
    CCARRAY_FOREACH(projectilesToDelete, projectile_obj)
    {
        CCSprite *projectile = (CCSprite*)projectile_obj;
        _projectiles->removeObject(projectile);
        this->removeChild(projectile, true);
    }
}

#pragma mark - touch dispatch callback
void HelloWorld::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCLOG("touches ended!");
    //1. get the actual touch position
    cocos2d::CCTouch *touch = (cocos2d::CCTouch*)pTouches->anyObject();
    CCPoint pt = touch->locationInView(touch->view());
    pt = CCDirector::sharedDirector()->convertToGL(pt);
    
    //2.set up the projectile 's initial position & state
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite *projectile = CCSprite::spriteWithFile("Projectile.png",CCRectMake(0, 0, 20, 20));
    projectile->setTag(2);
    _projectiles->addObject(projectile);
    projectile->setPosition(CCPointMake(20, size.height / 2.0f));
    
    
    //3.caculate the offset of the projectile & the touch point
    float offsetX = pt.x - projectile->getPosition().x;
    float offsetY = pt.y - projectile->getPosition().y;
    
    if (offsetX < 0) {
        return;
    }
    
    this->addChild(projectile);
    
    //4.determin where we wan't the projectile to fly
    float realX = size.width + projectile->getPosition().x;
    float ratio = offsetY / offsetX;
    float realY = realX * ratio + projectile->getPosition().y;
    CCPoint realDest = CCPointMake(realX, realY);
    
    //5.determin the real distance & move duration
    float offsetRealX = realX - projectile->getPosition().x;
    float offsetRealY = realY - projectile->getPosition().y;
    float offsetRealLength = sqrtf(offsetRealX * offsetRealX + offsetRealY * offsetRealY);
    float velocity = 480.0f / 1.0f;
    float moveDuration = offsetRealLength / velocity;
    
    
    SimpleAudioEngine::sharedEngine()->playEffect("pew-pew-lei.caf");
    
    //6.make the projectile to run a moveTo action
    CCLOG( "projectile shooting!");
    CCMoveTo *move = CCMoveTo::actionWithDuration(moveDuration, realDest);
    projectile->runAction(CCSequence::actions(move,
                                              CCCallFuncN::actionWithTarget(this, callfuncN_selector(HelloWorld::spriteMoveFinished)),NULL));
    
}

HelloWorld::~HelloWorld()
{
    CC_SAFE_RELEASE(_targets);
    CC_SAFE_RELEASE(_projectiles);
}

void HelloWorld::spriteMoveFinished(cocos2d::CCNode *sprite)
{
    if (sprite->getTag() == 1) {
        _targets->removeObject(sprite);
        
        CCScene *gameOver = GameOverScene::scene();
        GameOverScene *layer = (GameOverScene*)gameOver->getChildren()->objectAtIndex(0);
        layer->getLabel()->setString("You Lose!");
        CCDirector::sharedDirector()->replaceScene(gameOver);
        
        
    }else if(sprite->getTag() == 2){
        _projectiles->removeObject(sprite);
    }
    this->removeChild(sprite, true);
    CCLOG("remove projectile!");
}

#pragma mark - game logic scheduler
void HelloWorld::gameLogic(cocos2d::ccTime dt)
{
    this->addTarget();
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
