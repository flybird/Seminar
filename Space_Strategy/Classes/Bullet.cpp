
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
    if (Sprite::initWithSpriteFrame(spriteFrame))
    {
        return true;
    }
    return false;
}

void Bullet::resetStrategy(Strategy *strategy)
{
    this->unscheduleUpdate();
    if (_strategy)
    {
        _strategy->setBullet(nullptr);
        CC_SAFE_RELEASE_NULL(_strategy);
    }
    
    this->setStrategy(strategy);
    this->start();
}

void Bullet::start(void)
{
    if (_strategy)
    {
        _strategy->setBullet(this);
        _strategy->retain();
        this->scheduleUpdate();
    }
}

void Bullet::stop(void)
{
    if (_strategy)
    {
        _strategy->setBullet(nullptr);
        
        log("Bullet stop, 'strategy' retain number:%d", _strategy->getReferenceCount());
        CC_SAFE_RELEASE_NULL(_strategy);
    }
    this->unscheduleUpdate();
    this->removeFromParent();
    
    log("Bullet stop, 'bullet' retain number:%d", this->getReferenceCount());
}

void Bullet::update(float delta)
{
    if (_strategy)
    {
        _strategy->move();
    }
}