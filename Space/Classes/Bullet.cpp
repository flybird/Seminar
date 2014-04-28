
#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::createWithFrameName(const std::string &fileName)
{
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(fileName);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", fileName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    Bullet *bullet = new Bullet();
    if (frame && bullet && bullet->initWithSpriteFrame(frame))
    {
        bullet->autorelease();
        return bullet;
    }
    
    CC_SAFE_DELETE(bullet);
    return nullptr;
}

bool Bullet::initWithSpriteFrame(SpriteFrame *spriteFrame)
{
    if (!Sprite::initWithSpriteFrame(spriteFrame))
        return false;
    
    _winSize = Director::getInstance()->getWinSize();
    
    this->setSpeed(Point(10, 0));
    
    this->scheduleUpdate();
    
    return true;
}

void Bullet::setSpeed(Point point)
{
    _speedX = point.x;
    _speedY = point.y;
    
    float angleRadians = atanf(_speedY / _speedX);
    float angleDegrees = CC_RADIANS_TO_DEGREES(angleRadians);
    _rotation = -angleDegrees;
    
    this->setRotation(_rotation);
}

void Bullet::update(float delta)
{
    this->setPosition(this->getPosition() + Point(_speedX, _speedY));
    if (this->getPositionX() > _winSize.width || this->getPositionX() < 0)
    {
        this->unscheduleUpdate();
        this->removeFromParent();
    }
}