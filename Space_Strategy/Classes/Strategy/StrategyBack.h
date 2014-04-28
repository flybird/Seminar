//
//  StrategyBack.h
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#ifndef __STRATEGY_BACK__
#define __STRATEGY_BACK__

#include "Strategy.h"

class StrategyBack : public Strategy
{
public:
    virtual bool init();
    virtual void move();
};

#endif
