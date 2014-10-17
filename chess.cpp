//Pierre Alliez
#include "chess.h"
#include "constants.cpp"
#include "helper.cpp"
#include <iostream>
using namespace std;

Piece::Piece(int c,int i,int j){
	identity = c;
	alive = true;
	x = i;
	y = j;
	reset();
}

void Piece::reset(){
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j)
			{allowedMoves[i][j]=false;}
	}
}

Board::Board(){
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			if(i==2 || i==3)
				chessPiece[i][j] = new Piece(initialSetup[i+4][j],i+4,j);
			else if(i==0 || i==1)
				chessPiece[i][j] = new Piece(initialSetup[i][j],i,j);
			boardState[i][j] = initialSetup[i][j];
			pieceColor[i][j] = signOf(initialSetup[i][j]);
		}
	}
}

void Board::rook(Piece& p,int c){
	cout<<"Rook\n";
	//towards left
	for(int a = p.x,b = p.y-1;inBoard(a,b);--b){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
	//towards right
	for(int a = p.x,b = p.y+1;inBoard(a,b);++b){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
	//towards up
	for(int a = p.x-1,b = p.y;inBoard(a,b);--a){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
	//towards down
	for(int a = p.x+1,b = p.y;inBoard(a,b);++a){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
}

void Board::pawn(Piece& p, int c){
	cout<<"Pawn\n";
	if(inBoard(p.x-signOf(c),p.y) && pieceColor[p.x-signOf(c)][p.y]==0){
		p.allowedMoves[p.x-signOf(c)][p.y]=1;
		//check if two moves are allowed
		if(inBoard(p.x-2*signOf(c),p.y) && (p.x==6 || p.x==1) && pieceColor[p.x-2*signOf(c)][p.y]==0)
			{p.allowedMoves[p.x-2*signOf(c)][p.y]=1;}
	}
	//check for diagonal moves if piece of opposite color is present
	if(inBoard(p.x-signOf(c),p.y+1) && pieceColor[p.x-signOf(c)][p.y+1]==-signOf(c))
		{p.allowedMoves[p.x-signOf(c)][p.y+1]=1;}
	if(inBoard(p.x-signOf(c),p.y-1) && pieceColor[p.x-signOf(c)][p.y-1]==-signOf(c))
		{p.allowedMoves[p.x-signOf(c)][p.y-1]=1;}
}

void Board::bishop(Piece& p,int c){
	cout<<"Bishop\n";
	//upper left diagonal
	for(int a = p.x - 1, b = p.y - 1; inBoard(a,b);--a, --b){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
	//lower right diagonal
	for(int a = p.x + 1, b = p.y + 1; inBoard(a,b);++a, ++b){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
	//lower left diagonal
	for(int a = p.x + 1, b = p.y - 1; inBoard(a,b);++a, --b){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
	//upper right diagonal
	for(int a = p.x - 1, b = p.y + 1; inBoard(a,b);--a, ++b){
		if(pieceColor[a][b] == 1){
			if(c==1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//white found
		else if(pieceColor[a][b] == -1) {
			if(c==-1){break;}
			else {p.allowedMoves[a][b] = 1;break;}
		}//black found
		else {p.allowedMoves[a][b] = 1;}
	}
}

void Board::knight(Piece& p,int c){
	cout<<"Knight\n";
	int i = p.x, j = p.y;
	if(inBoard(i-2,j-1) && c*pieceColor[i-2][j-1]<=0)//check why <=0
		p.allowedMoves[i-2][j-1] = 1;
	if(inBoard(i-2,j+1) && c*pieceColor[i-2][j+1]<=0)//check why <=0
		p.allowedMoves[i-2][j+1] = 1;
	if(inBoard(i+2,j-1) && c*pieceColor[i+2][j-1]<=0)//check why <=0
		p.allowedMoves[i+2][j-1] = 1;
	if(inBoard(i+2,j+1) && c*pieceColor[i+2][j+1]<=0)//check why <=0
		p.allowedMoves[i+2][j+1] = 1;
	if(inBoard(i-1,j-2) && c*pieceColor[i-1][j-2]<=0)//check why <=0
		p.allowedMoves[i-1][j-2] = 1;
	if(inBoard(i-1,j+2) && c*pieceColor[i-1][j+2]<=0)//check why <=0
		p.allowedMoves[i-1][j+2] = 1;
	if(inBoard(i+1,j-2) && c*pieceColor[i+1][j-2]<=0)//check why <=0
		p.allowedMoves[i+1][j-2] = 1;
	if(inBoard(i+1,j+2) && c*pieceColor[i+1][j+2]<=0)//check why <=0
		p.allowedMoves[i+1][j+2] = 1;
}

void Board::queen(Piece& p,int c){
	cout<<"Queen\n";
	rook(p,c);
	bishop(p,c);
}

void Board::king(Piece& p,int c){
	cout<<"King\n";
	for(int a=p.x-1;a<=p.x+1;++a){
		for(int b=p.y-1;b<=p.y+1;++b){
			if(inBoard(a,b) && (pieceColor[a][b]!=c) && !isChecked(a,b,c))
				p.allowedMoves[a][b] = 1;
		}
	}
	p.allowedMoves[p.x][p.y] = 0;
}

bool Board::isChecked(int a,int b,int c){
	if(c==1){
		for(int i=0;i<2;++i){
			for(int j=0;j<8;++j){
				Piece *p = chessPiece[i][j];
				if(p->alive && p->allowedMoves[a][b])
					return true;
			}
		}
	}
	else{
		for(int i=2;i<4;++i){
			for(int j=0;j<8;++j){
				Piece *p = chessPiece[i][j];
				if(p->alive && p->allowedMoves[a][b])
					return true;
			}
		}	
	}
	return false;
}

void Board::possibleMoves(Piece& p){
	p.reset();
	switch(p.identity){
		case 1:
		case -1:
			rook(p,signOf(p.identity));
			break;
		
		case 4:
		case -4:
			pawn(p,signOf(p.identity));
			break;

		case 3:
		case -3:
			bishop(p,signOf(p.identity));
			break;

		case 2:
		case -2:
			knight(p,signOf(p.identity));
			break;

		case 5:
		case -5:
			queen(p,signOf(p.identity));
			break;

		case 6:
		case -6:
			king(p,signOf(p.identity));
			break;
	}
}