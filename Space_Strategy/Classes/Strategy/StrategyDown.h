//
//  StrategyDown.h
//  Space
//
//  Created by Neil on 2014/4/28.
//
//

#ifndef __STRATEGY_DOWN__
#define __STRATEGY_DOWN__

#include "Strategy.h"

class StrategyDown : public Strategy
{
public:
    virtual bool init();
    virtual void move();
};

#endif
