#include "board.h"

namespace core {
namespace board {

	Board::Board(Pieces* pieces, int screenHeight)
	{
		this->pieces = pieces;
		this->screenHeight = screenHeight;

		InitBoard();
	}

	void Board::InitBoard()
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			for (int j = 0; j < BOARD_HEIGHT; j++)
			{
				board[i][j] = POS_FREE;
			}
		}
	}

	void Board::StorePiece(int x, int y, int piece, int rotation)
	{
		for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
		{
			for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++)
			{
				if (pieces->GetBlockType(piece, rotation, j2, i2) != 0)
				{
					board[i1][j1] = POS_FILLED;
				}
			}
		}
	}

	bool Board::IsGameOver()
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (board[i][0] == POS_FILLED)
				return true;
		}

		return false;
	}

}}