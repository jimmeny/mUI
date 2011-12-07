#ifndef __VIEW_H__
#define __VIEW_H__

#include "../Presenter/ISquare.h"

class View
{
public:
	virtual void set_SquareState(const Point& location, SquareState::Enum state) = 0;
	virtual void set_RemainingMineTotal(int remainingTotal) = 0;
};

#endif // __VIEW_H__
