//
//  StrategyBack.cpp
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#include "StrategyBack.h"

bool StrategyBack::init(void)
{
    this->setSpeed(Point(-6, 0));
    
    return true;
}

void StrategyBack::move(void)
{
//    log("StrategyBack::update");
//    log("StrategyBack, speedX=%f, speedY=%f, rotation=%f", getSpeed().x, getSpeed().y, getRotation());
    
    Bullet *bullet = this->getBullet();
    if (bullet)
    {
        bullet->setRotation(getRotation());
        bullet->setPosition(bullet->getPosition() + Point(getSpeed().x, getSpeed().y));
        if (bullet->getPositionX() < 0)
        {
            _bullet->stop();
        }
    }
}