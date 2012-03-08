//
//  GameOverScene.m
//  SimpleGame
//
//  Created by kdanmobile09 on 12-3-8.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#import "GameOverScene.h"

#import"HelloWorldScene.h"

CCScene* GameOverScene::scene()
{
    CCScene *scene = CCScene::node();
    
    GameOverScene *layer = GameOverScene::node();
    
    scene->addChild(layer);
    
    return scene;
}

GameOverScene::~GameOverScene()
{
    
}

bool GameOverScene::init()
{
    if (!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255))) {
        return false;
    }
    
    this->setLabel(CCLabelTTF::labelWithString("11", "Arial", 32));
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    this->getLabel()->setPosition(ccp(winSize.width / 2.0f, winSize.height / 2.0f));
    this->getLabel()->setColor(ccc3(0, 0, 0));
    this->addChild(_label);
    
    _label->runAction(CCSequence::actions(CCDelayTime::actionWithDuration(3.0f),CCCallFunc::actionWithTarget(this, callfunc_selector(GameOverScene::gameOverDone)),NULL));
    
    
    return true;
}

void GameOverScene::gameOverDone()
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

