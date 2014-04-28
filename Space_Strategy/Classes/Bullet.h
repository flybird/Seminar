#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"
#include "Strategy/Strategy.h"

USING_NS_CC;

class Strategy;
class Bullet : public Sprite
{
public:
    static Bullet* createWithFrameName(const std::string &fileName);
    
    virtual bool initWithSpriteFrame(SpriteFrame *spriteFrame);
    
    CC_SYNTHESIZE(Strategy*, _strategy, Strategy);
    
    void resetStrategy(Strategy *strategy);
    
    virtual void update(float delta);
    void start(void);
    void stop(void);
    CREATE_FUNC(Bullet);
};

#endif // __HELLOWORLD_SCENE_H__
