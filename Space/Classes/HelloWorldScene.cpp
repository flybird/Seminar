
#include "HelloWorldScene.h"
#include "Bullet.h"

USING_NS_CC;

Scene* HelloWorldScene::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorldScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool HelloWorldScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    _winSize = Director::getInstance()->getWinSize();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites.plist");
    
    _batchNode = SpriteBatchNode::create("Sprites.pvr.ccz");
    this->addChild(_batchNode, 1);
    
    _ship = Sprite::createWithSpriteFrameName("SpaceFlier_sm_1.png");
    _ship->setPosition(Point(_winSize.width * .3f, _winSize.height/2));
    _batchNode->addChild(_ship);
    
    // Normal
    auto closeItem1 = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(HelloWorldScene::shoot1Click, this));
	closeItem1->setPosition(Point(_winSize.width/2 - 40, 40));
    
    auto closeItem2 = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(HelloWorldScene::shoot2Click, this));
	closeItem2->setPosition(Point(_winSize.width/2 + 0, 40));
    
    auto menu = Menu::create(closeItem1, closeItem2, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    return true;
}


void HelloWorldScene::shoot1Click(Ref* pSender)
{
    auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
//    shipLaser->setSpeed(Point(6,.8f));
//    shipLaser->setSpeed(Point(6,-.8f));
//    shipLaser->setSpeed(Point(-8,0));
    shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
    this->addChild(shipLaser, 0);
}

void HelloWorldScene::shoot2Click(Ref* pSender)
{
    Point points[6] = {Point(10,0), Point(6,.8f), Point(7,2), Point(6,-.8f), Point(7,-2), Point(-8,0)};
    for (int i=0; i<6; i++)
    {
        auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
        shipLaser->setSpeed(points[i]);
        shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
        this->addChild(shipLaser, 0);
    }
}
