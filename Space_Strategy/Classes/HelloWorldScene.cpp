
#include "HelloWorldScene.h"
#include "Bullet.h"
#include "StrategyDirectly.h"
#include "StrategyUP.h"
#include "StrategyDown.h"
#include "StrategyBack.h"

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
    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Point origin = Director::getInstance()->getVisibleOrigin();
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
    
    
    // Normal
    auto closeItem1 = MenuItemImage::create("CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorldScene::shoou1Click, this));
	closeItem1->setPosition(Point(_winSize.width/2 - 40, 40));
    
    auto closeItem2 = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(HelloWorldScene::shoou2Click, this));
	closeItem2->setPosition(Point(_winSize.width/2 + 0, 40));
    
    auto closeItem3 = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(HelloWorldScene::shoou3Click, this));
	closeItem3->setPosition(Point(_winSize.width/2 + 40, 40));
    
    auto menu = Menu::create(closeItem1, closeItem2, closeItem3, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);


    
    //Change Strategy
    auto closeItemC1 = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(HelloWorldScene::c1Click, this));
	closeItemC1->setPosition(Point(_winSize.width/2 + 110, 40));
    
    auto closeItemC2 = MenuItemImage::create("CloseNormal.png",
                                             "CloseSelected.png",
                                             CC_CALLBACK_1(HelloWorldScene::c2Click, this));
	closeItemC2->setPosition(Point(_winSize.width/2 + 150, 40));
    
    auto menuC = Menu::create(closeItemC1, closeItemC2, NULL);
    menuC->setPosition(Point::ZERO);
    this->addChild(menuC, 1);
    
    return true;
}

//Normal
void HelloWorldScene::shoou1Click(Ref* pSender)
{
    //建立子彈
    auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
    shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
    this->addChild(shipLaser, 0);
    
    //建立移動策略
#warning 建立移動策略1
    Strategy *strategy = new StrategyDirectly();
    strategy->init();
    strategy->autorelease();
    shipLaser->setStrategy(strategy);
    
    //開始移動
    shipLaser->start();
}

void HelloWorldScene::shoou2Click(Ref* pSender)
{
    //建立子彈
    auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
    shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
    this->addChild(shipLaser, 0);
    
    //建立移動策略
#warning 建立移動策略2
    Strategy *strategy = new StrategyUP();
    strategy->init();
    strategy->autorelease();
    shipLaser->setStrategy(strategy);
    
    //開始移動
    shipLaser->start();
}

void HelloWorldScene::shoou3Click(Ref* pSender)
{
#warning 建立複合子彈
    for (int i = 0; i<3; i++)
    {
        //建立子彈
        auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
        shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
        this->addChild(shipLaser, 0);
        
        //建立移動策略
        Strategy *strategy = nullptr;

        switch (i) {
            case 0:
                strategy = new StrategyDirectly();
                break;
            case 1:
                strategy = new StrategyUP();
                break;
            case 2:
                strategy = new StrategyDown();
                break;
            default:
                strategy = new StrategyDirectly();
                break;
        }
        strategy->init();
        strategy->autorelease();
        shipLaser->setStrategy(strategy);
        
        //開始移動
        shipLaser->start();
    }
}


#warning 讓子彈轉彎
//Change Strategy
void HelloWorldScene::c1Click(Ref* pSender)
{
    Bullet *bullet = dynamic_cast<Bullet*>(this->getChildByTag(100));
    if (bullet)
        return;
    
    //建立子彈
    auto *shipLaser = Bullet::createWithFrameName("laserbeam_blue.png");
    shipLaser->setPosition(_ship->getPosition() + Point(4, 0));
    this->addChild(shipLaser, 0, 100);
    
    //建立移動策略
    Strategy *strategy = new StrategyDirectly();
    strategy->init();
    strategy->autorelease();
    shipLaser->setStrategy(strategy);
    
    //開始移動
    shipLaser->start();
}

void HelloWorldScene::c2Click(Ref* pSender)
{
    Bullet *bullet = dynamic_cast<Bullet*>(this->getChildByTag(100));
    if (bullet)
    {
        Strategy *strategy = new StrategyUP();
        strategy->init();
        strategy->autorelease();
        
#warning 重制演算法!!
        bullet->resetStrategy(strategy);
    }
}