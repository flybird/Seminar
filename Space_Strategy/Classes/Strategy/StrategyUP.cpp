//
//  StrategyUP.cpp
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#include "StrategyUP.h"

bool StrategyUP::init(void)
{
    this->setSpeed(Point(10, 2.0f));
    
    float angleRadians = atanf(getSpeed().y / getSpeed().x);
    float angleDegrees = CC_RADIANS_TO_DEGREES(angleRadians);
    this->setRotation(-angleDegrees);
    
    return true;
}

void StrategyUP::move(void)
{
//    log("StrategyUP::update");
//    log("StrategyUP, speedX=%f, speedY=%f, rotation=%f", getSpeed().x, getSpeed().y, getRotation());
    
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