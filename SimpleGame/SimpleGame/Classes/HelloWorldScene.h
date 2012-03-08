#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::CCLayerColor
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
	
	// a selector callback
	virtual void menuCloseCallback(CCObject* pSender);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	// implement the "static node()" method manually
	LAYER_NODE_FUNC(HelloWorld);
    
    ~HelloWorld();
    
public:
    void addTarget();
    void removeTarget(CCNode *sprite,int* data);
    void gameLogic(cocos2d::ccTime dt);
    void spriteMoveFinished(CCNode *sprite);
    void update(ccTime dt);
    
private:
    CCArray *_targets; 
    CCArray *_projectiles;
    
    int _projectilesDestroyed;

};

#endif // __HELLOWORLD_SCENE_H__
