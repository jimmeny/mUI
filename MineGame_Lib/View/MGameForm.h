#ifndef __MAINFORM_H__
#define __MAINFORM_H__

#include <mUI.h>
using namespace mUI::System::Forms;

#include "View.h"

#include <vector>
using std::vector;

class SquareControl;
class MGame;

class MGameForm : public Form, public View
{
public:
	MGameForm();
    virtual ~MGameForm();

    virtual void CreateSquares(const Size& size);
    virtual void set_SquareState(const Point& location, SquareState::Enum state, IntPtr param);
    virtual void set_RemainingMineTotal(int remainingTotal);

protected:
	virtual void OnPaint( PaintEventArgs* e );

    virtual void OnNewGame(void* sender, EventArgs* e);
    virtual void OnFieldSizeChanged(void* sender, FieldSizeChangedEventArgs* e);
    virtual void OnMineTotalChanged(void* sender, MineTotalChangedEventArgs* e);

    void DisposeSquares();


private:
	vector<SquareControl*> _squareStates;
    MGame* _game;
};

#endif // __MAINFORM_H__
