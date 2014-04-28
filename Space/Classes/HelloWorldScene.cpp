
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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    _winSize = Director::getInstance()->getWinSize();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites.plist");
    
//    auto background = Sprite::create("background.png");
//    background->setPosition(Point(_winSize.width/2, _winSize.height/2));
//    this->addChild(background, -1);
    
    _batchNode = SpriteBatchNode::create("Sprites.pvr.ccz");
    this->addChild(_batchNode, 1);
    
    _ship = Sprite::createWithSpriteFrameName("SpaceFlier_sm_1.png");
    _ship->setPosition(Point(_winSize.width * .3f, _winSize.height/2));
    _batchNode->addChild(_ship);
    
    auto closeItem = MenuItemImage::create("CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorldScene::menuCloseCallback, this));
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

//    auto label = LabelTTF::create("Hello World", "Arial", 24);
//    label->setPosition(Point(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//    this->addChild(label, 1);

    return true;
}


void HelloWorldScene::menuCloseCallback(Ref* pSender)
{
//    auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
//    shipLaser->setSpeed(Point(6,.8f));
//    shipLaser->setSpeed(Point(6,-.8f));
//    shipLaser->setSpeed(Point(-8,0));
//    shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
//    this->addChild(shipLaser, 0);
    
    
    Point points[6] = {Point(10,0), Point(6,.8f), Point(7,2), Point(6,-.8f), Point(7,-2), Point(-8,0)};
    for (int i=0; i<6; i++)
    {
        auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
        shipLaser->setSpeed(points[i]);
        shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
        this->addChild(shipLaser, 0);
    }
    
        
}
