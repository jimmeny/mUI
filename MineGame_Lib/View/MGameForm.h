#ifndef __MAINFORM_H__
#define __MAINFORM_H__

#include <mUI.h>
using namespace mUI::System::Forms;

#include "View.h"

#include <vector>
using std::vector;

class MGameForm : public Form, public View
{
public:
	MGameForm();

	virtual void set_SquareState(const Point& location, SquareState::Enum state, IntPtr param);
	virtual void set_RemainingMineTotal(int remainingTotal);

protected:
	virtual void OnPaint( PaintEventArgs* e );

private:
	vector<SquareState::Enum> _squareStates;
};

#endif // __MAINFORM_H__