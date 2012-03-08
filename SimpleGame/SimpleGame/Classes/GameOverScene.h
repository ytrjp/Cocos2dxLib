//
//  GameOverScene.h
//  SimpleGame
//
//  Created by kdanmobile09 on 12-3-8.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//
#ifndef __GameOverScene_H
#define __GameOverScene_H

#include  "cocos2d.h"

USING_NS_CC;

class GameOverScene : public CCLayerColor
{
public:
    LAYER_NODE_FUNC(GameOverScene);
    
    static CCScene *scene();
    
    ~GameOverScene();
    virtual bool init();
    
    void gameOverDone();
    
    //property
    CC_SYNTHESIZE(CCLabelTTF*, _label, Label)
};

#endif
