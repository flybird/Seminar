//
//  StrategyUP.h
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#ifndef __STRATEGY_UP__
#define __STRATEGY_UP__

#include "Strategy.h"

class StrategyUP : public Strategy
{
public:
    virtual bool init();
    virtual void move();
};

#endif
