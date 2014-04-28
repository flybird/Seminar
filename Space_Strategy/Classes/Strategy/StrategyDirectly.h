//
//  StrategyDirectly.h
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#ifndef __STRATEGY_DIRECTLY__
#define __STRATEGY_DIRECTLY__

#include "Strategy.h"

class StrategyDirectly : public Strategy
{
public:
    virtual bool init();
    virtual void move();
};

#endif
