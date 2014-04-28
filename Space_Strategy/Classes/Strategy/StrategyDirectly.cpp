//
//  StrategyDirectly.cpp
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#include "StrategyDirectly.h"

bool StrategyDirectly::init(void)
{
    this->setSpeed(Point(10,0));
    this->setRotation(0);
    
    return true;
}

void StrategyDirectly::move(void)
{
//    log("StrategyDirectly::update");
//    log("StrategyDirectly, speedX=%f, speedY=%f, rotation=%f", getSpeed().x, getSpeed().y, getRotation());
    
    Bullet *bullet = this->getBullet();
    if (bullet)
    {
        bullet->setPosition(bullet->getPosition() + Point(getSpeed().x, getSpeed().y));
        if (bullet->getPositionX() > _winSize.width)
        {
            _bullet->stop();
        }
    }
}