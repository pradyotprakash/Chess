#include "chess.cpp"

int main(){
	Board b;
	Piece* p = b.chessPiece[3][3];
	b.possibleMoves(*p);
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			cout<<(p->allowedMoves[i][j])<<" ";
		}
		cout<<endl;
	}
}
