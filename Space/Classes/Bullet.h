#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

USING_NS_CC;

class Bullet : public Sprite
{
private:
    Size _winSize;
    float _speedX;
    float _speedY;
    float _rotation;
    
public:
    static Bullet* createWithFrameName(const std::string &fileName);
    
    virtual bool initWithSpriteFrame(SpriteFrame *spriteFrame);
    virtual void update(float delta);
    
    void setSpeed(Point point);
    
    CREATE_FUNC(Bullet);
};

#endif // __HELLOWORLD_SCENE_H__
