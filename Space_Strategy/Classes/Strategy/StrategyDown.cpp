//
//  StrategyDown.cpp
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#include "StrategyDown.h"

bool StrategyDown::init(void)
{
    this->setSpeed(Point(10, -1.2f));
    
    float angleRadians = atanf(getSpeed().y / getSpeed().x);
    float angleDegrees = CC_RADIANS_TO_DEGREES(angleRadians);
    this->setRotation(-angleDegrees);
    
    return true;
}

void StrategyDown::move(void)
{
//    log("StrategyDown::update");
//    log("StrategyDown, speedX=%f, speedY=%f, rotation=%f", getSpeed().x, getSpeed().y, getRotation());
    
    Bullet *bullet = this->getBullet();
    if (bullet)
    {
        bullet->setRotation(getRotation());
        bullet->setPosition(bullet->getPosition() + Point(getSpeed().x, getSpeed().y));
        if (bullet->getPositionX() > _winSize.width)
        {
            _bullet->stop();
        }
    }
}