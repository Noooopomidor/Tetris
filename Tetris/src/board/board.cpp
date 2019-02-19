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

	void Board::DeleteLine(int y)
	{
		for (int j = y; j > 0; j--)
		{
			for (int i = 0; i < BOARD_WIDTH; i++)
			{
				board[i][j] = board[i][j - 1];
			}
		}
	}

	int Board::GetXPosInPixel(int blockPosition)
	{
		return (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (blockPosition * BLOCK_SIZE);
	}

	int Board::GetYPosInPixel(int blockPosition)
	{
		return (screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (blockPosition * BLOCK_SIZE);
	}

	bool Board::IsFreeBlock(int x, int y)
	{
		return board[x][y] == POS_FREE;
	}

	bool Board::IsPossibleMovement(int x, int y, int piece, int rotation)
	{
		for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
		{
			for (int j1 = y, j2 = 0; j2 < y + PIECE_BLOCKS; j1++, j2++)
			{
				if (i1 > BOARD_WIDTH || j1 > BOARD_HEIGHT)
				{
					if (pieces->GetBlockType(piece, rotation, j2, i2) != 0)
						return false;
				}

				if (pieces->GetBlockType(piece, rotation, j2, i2) != 0 && !IsFreeBlock(i1, j1))
					return false;
			}
		}

		return true;
	}

	void Board::DeletePossibleLines()
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			int i = 0;
			for (i = 0; i < BOARD_WIDTH; i++)
			{
				if (board[i][j] != POS_FILLED)
					break;
			}
			
			if (i == BOARD_WIDTH)
				DeleteLine(j);
		}
	}
}}