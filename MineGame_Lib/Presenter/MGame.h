#ifndef __MGAME_H__
#define __MGAME_H__

#include <mUI.h>

using mUI::System::Drawing::Size;

class MineField;
class View;

class MGame
{
public:
	MGame(View* view);
	virtual ~MGame();

	void set_MineFieldWidth(int width);
	void set_MineFieldHeight(int height);
	const Size& get_MineFieldSize() const;
	void set_MineTotal(int mineTotal);
	int get_MineTotal() const;

	void NewGame();
	void Uncover(int x, int y);

	virtual void Lose();
	MineField* get_MineField();
private:
	MineField* _mineField;
	View* _view;
};

#endif // __MGAME_H__