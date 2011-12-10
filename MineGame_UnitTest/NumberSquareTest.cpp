#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::Return;

#include <mUI.h>
using namespace mUI::System;

#include <Presenter/MGame.h>
#include <Presenter/MineField.h>
#include <Presenter/NumberSquare.h>

#include "mocks/MineFieldMock.h"
#include "mocks/ViewMock.h"

class NumberSquareTest : public testing::Test
{
public:
	void SetUp()
	{
		_view = new ViewMock();
		_game = new MGame(_view);
		_mineField = new MineField(_game);
	}

	void TearDown()
	{
		delete _game;
		delete _mineField;
		delete _view;
	}

protected:
	MGame* _game;
	MineField* _mineField;
	View* _view;
};

TEST_F(NumberSquareTest, Constructor_Typical)
{
	NumberSquare* numberSquare = new NumberSquare(_game, _mineField, 0, 0);

	ASSERT_TRUE(NULL != numberSquare);
	ASSERT_EQ(SquareState::Covered, numberSquare->get_State());

	delete numberSquare;
}

TEST_F(NumberSquareTest, Uncover_Typical)
{
	NumberSquare numberSquare(NULL, NULL, 0, 0);

	numberSquare.Uncover();

	ASSERT_EQ(SquareState::Uncovered, numberSquare.get_State());
}

TEST_F(NumberSquareTest, Uncover_WhenFlagged)
{
	NumberSquare numberSquare(NULL, NULL, 0, 0);
	numberSquare.ToggleFlag();

	numberSquare.Uncover();

	ASSERT_EQ(SquareState::Flagged, numberSquare.get_State());
}

TEST_F(NumberSquareTest, Uncover_WhenQuestionMark)
{
	NumberSquare numberSquare(NULL, NULL, 0, 0);
	numberSquare.ToggleFlag();
	numberSquare.ToggleFlag();

	numberSquare.Uncover();

	ASSERT_EQ(SquareState::Uncovered, numberSquare.get_State());
}

TEST_F(NumberSquareTest, get_Number_Typical)
{
	int arbitraryNeighborMineTotal = 3;
	MineFieldMock mineField;
	NumberSquare numberSquare(NULL, &mineField, 0, 0);
	EXPECT_CALL(mineField, get_NeighborMineTotal(&numberSquare))
		.Times(1)
		.WillOnce(Return(arbitraryNeighborMineTotal));

	ASSERT_EQ(arbitraryNeighborMineTotal, numberSquare.get_Number());
}
