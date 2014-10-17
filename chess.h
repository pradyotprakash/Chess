class Piece{
public:
//4-pawn,1-rook,2-knight,3-bishop,5-queen,6-king
	int identity;
	int pieceValue;
	int x,y;
	bool alive;
	bool allowedMoves[8][8];

	Piece(int,int,int);//set identity,x,y
	void reset();//set the allowedMoves matix to null
};	

class Board{
public:
	/*
	 *	-1,-2,-3,-5,-6,-3,-2,-1
	 *	-4,-4,-4,-4,-4,-4,-4,-4
	 *   4,4,4,4,4,4,4,4
	 *   1,2,3,5,6,3,2,1
	 */
	Piece *chessPiece[4][8];
	int pieceColor[8][8];//white or black piece
	int boardState[8][8];//pieces at different squares

	Board();
	void possibleMoves(Piece&);
	//color denotes the color of the present piece
	void rook(Piece&,int color);//finds and assigns all possible moves horizontally and vertically
	void pawn(Piece&,int color);
	void bishop(Piece&,int color);
	void queen(Piece&,int color);
	void knight(Piece&,int color);
	void king(Piece&,int color);
	bool isChecked(int i,int j,int color);
};