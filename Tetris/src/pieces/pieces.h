#pragma once

namespace core {
namespace pieces {

	class Pieces
	{
	public:
		int GetBlockType(int piece, int rotation, int x, int y);
		int GetXInitialPosition(int piece, int rotation);
		int GetYInitialPosition(int piece, int rotation);
	};

}}