int signOf(int x){
	if(x>0) return 1;
	else if(x<0) return -1;
	else return 0;
}

bool inBoard(int x,int y){
	if(x>=0 && x<8 && y>=0 && y<8)
		return true;
	else return false;
}