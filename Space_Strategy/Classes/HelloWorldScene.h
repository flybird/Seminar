#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorldScene : public Layer
{
private:
    Size _winSize;
    
public:
    static Scene* createScene();
    virtual bool init();  
    
    SpriteBatchNode *_batchNode;
    Sprite *_ship;
    
    void shoou1Click(Ref* pSender);
    void shoou2Click(Ref* pSender);
    void shoou3Click(Ref* pSender);
    
    void c1Click(Ref* pSender);
    void c2Click(Ref* pSender);
    
    CREATE_FUNC(HelloWorldScene);
};

#endif // __HELLOWORLD_SCENE_H__
