#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace ::testing;

#include "mocks/PieceMock.h"
#include "mocks/SquareMock.h"
#include "mocks/CGameMock.h"

#include <Presenter/Square.h>

#include <mUI.h>
using namespace mUI::System::Forms;

struct SquareTestable : public Square
{
	using Square::OnMouseClick;
	using Square::set_Piece;
};

class SquareTest : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		_game = new CGameMock();
		_sut = (SquareTestable*)new Square(_game, Point::Empty);
		_piece = new PieceMock();
	}

	virtual void TearDown()
	{
		delete _sut; _sut = nullptr;
		delete _game; _game = nullptr;
		delete _piece; _piece = nullptr;
	}

protected:
	PieceMock* _piece;
	SquareTestable* _sut;
	CGameMock* _game;
};

TEST_F(SquareTest, Constructor_Typical)
{
	ASSERT_TRUE(nullptr != _sut);
}

TEST_F(SquareTest, get_Piece_WhenDefault)
{
	ASSERT_TRUE(nullptr == _sut->get_Piece());
}

TEST_F(SquareTest, OnMouseClick_WhenNoPiecePicked)
{
	_sut->set_Piece(_piece);
	EXPECT_CALL(*_game, get_Picked()).WillRepeatedly(Return(nullptr));
	EXPECT_CALL(*_game, Pick(_piece)).Times(1);

	_sut->OnMouseClick(nullptr, nullptr);
}

TEST_F(SquareTest, OnMouseClick_WhenPiecePickedAndClickOnSameSquare)
{
	_sut->set_Piece(_piece);
	EXPECT_CALL(*_game, get_Picked()).WillRepeatedly(Return(_piece));
	EXPECT_CALL(*_game, Pick(nullptr)).Times(1);

	_sut->OnMouseClick(nullptr, nullptr);
}

TEST_F(SquareTest, OnMouseClick_WhenPiecePickedAndClickOnAnotherEmptySquare)
{
	EXPECT_CALL(*_game, get_Picked()).WillRepeatedly(Return(_piece));
	EXPECT_CALL(*_game, Pick(nullptr)).Times(1);
	EXPECT_CALL(*_piece, MoveTo(_sut)).WillOnce(Return(true));

	_sut->OnMouseClick(nullptr, nullptr);
}

TEST_F(SquareTest, OnMouseClick_WhenMoveFailed)
{
	EXPECT_CALL(*_game, get_Picked()).WillRepeatedly(Return(_piece));
	EXPECT_CALL(*_game, Pick(_)).Times(0);
	EXPECT_CALL(*_piece, MoveTo(_sut)).WillOnce(Return(false));

	_sut->OnMouseClick(nullptr, nullptr);
}

