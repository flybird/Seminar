//
//  Strategy.h
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#ifndef __STRATEGH__
#define __STRATEGH__

#include "cocos2d.h"
#include "../Bullet.h"

USING_NS_CC;

class Bullet;

#warning !!!Strategy其實必需是一個介面，but我想加一些其它的功能所以沒有百分之遵守真正的規格

class Strategy:public Ref
{
protected:
    Size _winSize;
    
public:
    Strategy(void)
    {
        _winSize = Director::getInstance()->getWinSize();
    };
    
    CC_SYNTHESIZE(Bullet*, _bullet, Bullet);
    CC_SYNTHESIZE(Point, _speed, Speed);
    CC_SYNTHESIZE(float, rotation, Rotation);
    
    virtual bool init(void) { return true; };
    virtual void move(void) {};
};

#endif
