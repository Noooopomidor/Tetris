#pragma once

#include "../pieces/pieces.h"

#define BOARD_LINE_WIDTH 6
#define BOARD_POSITION 320
#define BOARD_WIDTH 10 // in blocks
#define BOARD_HEIGHT 20
#define BLOCK_SIZE 16
#define PIECE_BLOCKS 5

using namespace core;
using namespace pieces;

namespace core {
namespace board {

	class Board
	{
	public:
		Board(Pieces* pieces, int screenHeight);

		int GetXPosInPixel(int pos);
		int GetYPosInPixel(int pos);
		bool IsFreeBlock(int x, int y);
		bool IsPossibleMovement(int x, int y, int piece, int rotation);
		void StorePiece(int x, int y, int piece, int rotation);
		void DeletePossibleLines();
		bool IsGameOver();

	private:
		enum { POS_FREE, POS_FILLED };
		int board[BOARD_WIDTH][BOARD_HEIGHT];
		int screenHeight;
		Pieces* pieces;

		void InitBoard();
		void DeleteLine(int y);
	};

}}