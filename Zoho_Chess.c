#include<stdio.h>

int chessBoard[8][8] = {{1,2,3,4,5,3,2,1},{6,6,6,6,6,6,6,6},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{12,12,12,12,12,12,12,12},{7,8,9,10,11,9,8,7}}; //Initiating Chess Board
char chessPiecesFull[12][20] = {"B_Rook", "B_Knight", "B_Bishop","B_Queen","B_King","B_Pawn","W_Rook", "W_Knight", "W_Bishop","W_Queen","W_King","W_Pawn"};
char chessPieces[12][20] = {"B_R", "B_N", "B_B","B_Q","B_K","B_P","W_R", "W_N", "W_B","W_Q","W_K","W_P"};
int player = 0;
char alpha[8] = {'a','b','c','d','e','f','g','h'};

//Here, in the chess board each number deonotes one piece each
	//B_Rook   -> 1		W_Rook   -> 7
	//B_Knight -> 2		W_Knight -> 8
	//B_Bishop -> 3		W_Bishop -> 9
	//B_Queen  -> 4		W_Queen  -> 10
	//B_King   -> 5		W_King   -> 11
	//B_Pwan   -> 6		W_Pwan   -> 12

void switchPlayer(){ //switchPlayer is used to swap turns player 1 = 0 (White) and player 2 = 1 (Black)
	if(player == 0){
		player = 1;
		printf("Player 2 Turn: \n");
	}
	else{
		player = 0;
		printf("Player 1 Turn: \n");
	} 
}

void printBoard(){ //printBoard is used to print the whole Chess Board(2D array)
	int i=0;
	int j=0;
	int k=0;
	printf("\t1\t2\t3\t4\t5\t6\t7\t8\n\n");
	for(i=0;i<8;i++){
		printf("%d\t",i+1);
		for(j=0;j<8;j++){
//			printf("%d\t",chessBoard[i][j]);
			int val = chessBoard[i][j];
			if(val>0 && val<=12)
			printf("%s\t",chessPieces[val-1]);
			else printf(" *\t");
		}
		printf("\n\n");
	}
}

void movePiece(int x, int y){ //movePiece is used to move a piece on the board and also record the moves in moves.txt file 
	int a,b;
	printf("Choose Move: ");
	scanf("%d %d", &a,&b);
	a--;
	b--;
//	bool isValid = checkIfValid(x,y,a,b); //isValidFunction to be defined
	chessBoard[a][b] = chessBoard[x][y];
	chessBoard[x][y] = 0;
	int val = chessBoard[a][b];
	printBoard();
	FILE* f = fopen("moves.txt", "a+");
	if (f != NULL){
		if(player == 0)
			fprintf(f, "Player 1 - %s -- <%d %d> ----> <%d %d>\n",chessPiecesFull[val-1], x+1, y+1, a+1,b+1);
		else
			fprintf(f, "Player 2 - %s -- <%d %d> ----> <%d %d>\n", chessPiecesFull[val-1], x+1, y+1, a+1,b+1);
	fclose(f);
	f = NULL;
	}
	switchPlayer();
}

void checkRow(int p, int q){ //checkRow is used as a common function by the Queen and Rook, it is used to check all the possible moves in a row
	int x = p-1;
	int y = q-1;
	int i,j;
	if(y!=7){
//		printf("After y:\n");
		for(i=y+1;i<8;i++){
			if(chessBoard[x][i] != 0 && player == 0 && chessBoard[x][i]>=0 && chessBoard[x][i]<=6){
				printf("Black piece(Enemy) at <%d %d>\n",x+1,i+1);
				break;
			}
			else if(chessBoard[x][i] != 0 && player == 1 && chessBoard[x][i]>=7 && chessBoard[x][i]<=12){
				printf("White piece(Enemy) at <%d %d>\n",x+1,i+1);
				break;
			}
			else if(chessBoard[x][i] != 0 && player == 0 && chessBoard[x][i]>=7 && chessBoard[x][i]<=12){
				printf("White piece at <%d %d>\n",x+1,i+1);
				break;
			}
			else if(chessBoard[x][i] != 0 && player == 1 && chessBoard[x][i]>=1 && chessBoard[x][i]<=6){
				printf("Black piece at <%d %d>\n",x+1,i+1);
				break;
			}
			printf("<%d %d>",x+1,i+1);
		}
	}
	x = p-1;
	y = q-1;

	if(y!=0){
//		printf("Before y:\n");
		for(i=y-1;i>=0;i--){
			if(chessBoard[x][i] != 0 && player == 0 && chessBoard[x][i]>=0 && chessBoard[x][i]<=6){
				printf("Black piece(Enemy) at <%d %d>\n",x+1,i+1);
				break;
			}
			else if(chessBoard[x][i] != 0 && player == 1 && chessBoard[x][i]>=7 && chessBoard[x][i]<=12){
				printf("White piece(Enemy) at <%d %d>\n",x+1,i+1);
				break;
			}
			else if(chessBoard[x][i] != 0 && player == 0 && chessBoard[x][i]>=7 && chessBoard[x][i]<=12){
				printf("White piece at <%d %d>\n",x+1,i+1);
				break;
			}
			else if(chessBoard[x][i] != 0 && player == 1 && chessBoard[x][i]>=1 && chessBoard[x][i]<=6){
				printf("Black piece at <%d %d>\n",x+1,i+1);
				break;
			}
			printf("<%d %d>",x+1,i+1);
		}
	}
}

void checkColumn(int p, int q){ //checkColumn is used as a common function in the Queen and Rook, it is used to check all the possible moves in the column
	int x = p-1;
	int y = q-1;
	int i,j;
	int count = 0;
	if(x!=7){
//		printf("Below x:\n");
		for(i=x+1;i<8;i++){
			if(chessBoard[i][y] != 0 && player == 0 && chessBoard[i][y]>=0 && chessBoard[i][y]<=6){
				printf("\nBlack piece(Enemy) at <%d %d>\n",i+1,y+1);
				break;
			}
			else if(chessBoard[i][y] != 0 && player == 1 && chessBoard[i][y]>=7 && chessBoard[i][y]<=12){
				printf("White piece(Enemy) at <%d %d>\n",i+1,y+1);
				break;
			}
			else if(chessBoard[i][y] != 0 && player == 0 && chessBoard[i][y]>=7 && chessBoard[i][y]<=12){
				printf("White piece at <%d %d>\n",i+1,y+1);
				break;
			}
			else if(chessBoard[i][y] != 0 && player == 1 && chessBoard[i][y]>=1 && chessBoard[i][y]<=6){
				printf("Black piece at <%d %d>\n",i+1,y+1);
			break;
			}
			printf("<%d %d>",i+1,y+1);
			count++;
		}
	}
	x = p-1;
	y = q-1;

	if(x!=0){
//		printf("Above x:\n");
		for(i=x-1;i>0;i--){
			if(chessBoard[i][y] != 0 && player == 0 && chessBoard[i][y]>=0 && chessBoard[i][y]<=6){
				printf("Black piece(Enemy) at <%d %d>\n",i+1,y+1);
				break;
			}
			else if(chessBoard[i][y] != 0 && player == 1 && chessBoard[i][y]>=7 && chessBoard[i][y]<=12){
				printf("White piece(Enemy) at <%d %d>\n",i+1,y+1);
				break;
			}
			else if(chessBoard[i][y] != 0 && player == 0 && chessBoard[i][y]>=7 && chessBoard[i][y]<=12){
				printf("White piece at <%d %d>\n",i+1,y+1);
				break;
			}
			else if(chessBoard[i][y] != 0 && player == 1 && chessBoard[i][y]>=1 && chessBoard[i][y]<=6){
				printf("Black piece at <%d %d>\n",i+1,y+1);
				break;
			}
			printf("<%d %d>",i+1,y+1);
			count++;
		}
	}
}

int min(int x, int y){ // used to find the min of two numbers
	if(x<y) return x;
	else return y;
}

int max(int x, int y){ //used to find the max of two numbers
	if(x>y) return x;
	else return y;
}


//Prints x,y check error
void checkDiagonal(int p, int q){ //checkDiagonal is used as a common function in the Queen and the Bishop, it is used to check all the possible moves in the diagonals
	int x = p-1;					//Has runtime errors need to be checked
	int y = q-1;
	int topLeft = min(p,q)-1;
	int topRight = min(p,9-q)-1;
	int botLeft = 8 - max(p, 9-q);
	int botRight = 9 - max(p,q);
//	printf("%d %d %d %d",topLeft,topRight,botLeft,botRight);
	int i,j;
	if(x != 7){
	printf("Bottom Right:\n");
	for(i=x,j=y;j<=y+botRight;i++,j++){
		int val = chessBoard[i][j];
		if(val == 0)
			printf("<%d %d>\n",i+1,j+1);
		else{ 
			if(val != 0 && player == 0 && val>=0 && val<=6){
				printf("Black piece(Enemy) at <%d %d>\n",i+1,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val && val<=12){
				printf("White piece(Enemy) at <%d %d>\n",i+1,j+1);
				break;
			}
			else if(val != 0 && player == 0 && val>=7 && val<=12){
				printf("White piece at <%d %d>\n",i+1,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val>=1 && val<=6){
				printf("Black piece at <%d %d>\n",i+1,j+1);
				break;
			}
		}
	}
	
	printf("Bottom Left:\n");
	for(i=x,j=y;j>=y-botLeft;i++,j--){
		int val = chessBoard[i][j];
		if(val == 0)
			printf("<%d %d>\n",i+1,j+1);
		else{ 
			if(val != 0 && player == 0 && val>=0 && val<=6){
				printf("Black piece(Enemy) at <%d %d>\n",i+1,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val && val<=12){
				printf("White piece(Enemy) at <%d %d>\n",i+1,j+1);
				break;
			}
			else if(val != 0 && player == 0 && val>=7 && val<=12){
				printf("White piece at <%d %d>\n",i+1,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val>=1 && val<=6){
				printf("Black piece at <%d %d>\n",i+1,j+1);
				break;
			}
		}
	}
	}
	
	if(x!=0){
	printf("Top Right:\n");
	for(i=x-1,j=y+1;j<=y+topRight;i--,j++){
		int val = chessBoard[i][j];
		if(val == 0)
			printf("<%d %d>\n",i+1,j+1);
		else{ 
			if(val != 0 && player == 0 && val>=0 && val<=6){
				printf("Black piece(Enemy) at <%d %d>\n",i,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val && val<=12){
				printf("White piece(Enemy) at <%d %d>\n",i,j+1);
				break;
			}
			else if(val != 0 && player == 0 && val>=7 && val<=12){
				printf("White piece at <%d %d>\n",i,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val>=1 && val<=6){
				printf("Black piece at <%d %d>\n",i,j+1);
				break;
			}
		}
	}
	
	printf("Top Left:\n");
	for(i=x,j=y;j>=y-topLeft;i--,j--){
		int val = chessBoard[i][j];
		if(val == 0)
			printf("<%d %d>\n",i+1,j+1);
		else{ 
			if(val != 0 && player == 0 && val>=0 && val<=6){
				printf("Black piece(Enemy) at <%d %d>\n",i,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val && val<=12){
				printf("White piece(Enemy) at <%d %d>\n",i,j+1);
				break;
			}
			else if(val != 0 && player == 0 && val>=7 && val<=12){
				printf("White piece at <%d %d>\n",i,j+1);
				break;
			}
			else if(val != 0 && player == 1 && val>=1 && val<=6){
				printf("Black piece at <%d %d>\n",i,j+1);
				break;
			}
		}
		
	}
}
}

//Prints x,y check error
void kingMoves(int p, int q){ //Defines the movement of the king
	int x = p-1;
	int y = q-1;
	int i,j;
	printf("Available King moves:\n");
	for(i=x-1;i<=x+1;i++){
		for(j=y-1;j<=y+1;j++){
			int val = chessBoard[i][j];
			if(val == 0)
				printf("<%d %d>\n",i+1,j+1);
			else{ 
				if(val != 0 && player == 0 && val>=1 && val<=6){
					printf("Black piece(Enemy) at <%d %d>\n",i+1,j+1);
				}
				else if(val != 0 && player == 1 && val>=7 && val<=12){
					printf("White piece(Enemy) at <%d %d>\n",i+1,j+1);
				}
				else if(val != 0 && player == 0 && val>=7 && val<=12){
					printf("White piece at <%d %d>\n",i+1,j+1);
				}
				else if(val != 0 && player == 1 && val>=1 && val<=6){
					printf("Black piece at <%d %d>\n",i+1,j+1);
				}
			}	
		}
	}
	movePiece(x, y);
}

void knightMoves(int p, int q){ //defines the movement of the knight
	int x = p-1;
	int y = q-1;
	int i;
	int a[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int b[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    for (i = 0; i < 8; i++) {
    	x = p-1;
    	y = q-1;
        x = x + a[i];
        y = y + b[i];
//        printf("X = %d\n", x);
//        printf("Y = %d\n", y);
        if(x<8 && y<8 && x>=0 && y>=0){
        	int val = chessBoard[x][y];
        	if(val == 0)
				printf("<%d %d>\n",x+1,y+1);
			else{
				if(val != 0 && player == 0 && val>=1 && val<=6){
					printf("Black piece(Enemy) at <%d %d>\n",x+1,y+1);
				}
				else if(val != 0 && player == 1 && val>=7 && val<=12){
					printf("White piece(Enemy) at <%d %d>\n",x+1,y+1);
				}
				else if(val != 0 && player == 0 && val>=7 && val<=12){
					printf("White piece at <%d %d>\n",x+1,y+1);
				}
				else if(val != 0 && player == 1 && val>=1 && val<=6){
					printf("Black piece at <%d %d>\n",x+1,y+1);
				}
			}
		}
	}
	movePiece(p-1, q-1);
}

void pawnMoves_Black(int p, int q){ //defines the movement of the black pawns
	int x = p-1;
	int y = q-1;
	int i;
	int flag = 0;
	printf("Valid Pawn moves: \n");
	for(i=x+1;i<=x+2;i++){
		int val = chessBoard[i][y];
		if(val == 0 && player == 1){
		printf("<%d %d>\n",i+1,y+1);
		}
		else if(flag != 1){ 
			if(val != 0 && player == 1 && val>=7 && val<=12){
				printf("White piece(Enemy) at <%d %d>\n",i+1,y+1);
				flag = 1;
			}
			else if(val != 0 && player == 1 && val>=1 && val<=6){
				printf("Black piece at <%d %d>\n",i+1,y+1);
				flag = 1;
			}
		}
		if(i == x+1){
			if(chessBoard[i][y+1] != 0 && chessBoard[i][y+1]>=7 && chessBoard[i][y+1]<=12) {
				printf("White piece(Enemy-Killable) at <%d %d>\n",i+1,y+2);
			}
			if(chessBoard[i][y-1] != 0 && chessBoard[i][y-1]>=7 && chessBoard[i][y-1]<=12){
				printf("White piece(Enemy-Killable) at <%d %d>\n",i+1,y);
			}
		}
	}
	movePiece(x,y);
}


void pawnMoves_White(int p, int q){ //defines the movement of the white pawns
	int x = p-1;
	int y = q-1;
	int i;
	int flag = 0;
	printf("Valid Pawn moves: \n");
	for(i=x-1;i>=x-2;i--){
		int val = chessBoard[i][y];
		if(val == 0 && player == 0){
		printf("<%d %d>\n",i+1,y+1);
		}
		else if(flag != 1){
			if(val != 0 && player == 0 && val>=0 && val<=6){
				printf("Black piece(Enemy) at <%d %d>\n",i+1,y+1);
				flag = 1;
			}
			else if(val != 0 && player == 0 && val>=7 && val<=12){
				printf("White piece at <%d %d>\n",i+1,y+1);
				flag = 1;
			}
		}
		if(i == x-1){
			if(chessBoard[i][y+1] != 0 && chessBoard[i][y+1]>=0 && chessBoard[i][y+1]<=6) {
				printf("Black piece(Enemy-Killable) at <%d %d>\n",i+1,y+2);
			}
			if(chessBoard[i][y-1] != 0 && chessBoard[i][y-1]>=0 && chessBoard[i][y-1]<=6){
				printf("Black piece(Enemy-Killable) at <%d %d>\n",i+1,y);
			}
		}
	}
	movePiece(x,y);
}

void rookMoves(int x, int y){ //defines the movement of the rook
	printf("Valid Rook Moves:\n");
	checkRow(x,y);
	checkColumn(x,y);
	movePiece(x-1,y-1);
}

void bishopMoves(int x, int y){ //defines the movement of the bishop
	printf("Valid Bishop Moves:\n");
	checkDiagonal(x-1,y-1);
	movePiece(x-1, y-1);
}

void queenMoves(int x, int y){ //defines the movement of the queen
	printf("Valid Queen Moves:\n");
	checkDiagonal(x,y);
	checkRow(x,y);
	checkColumn(x,y);
	movePiece(x-1,y-1);
}

int pieceDetails(int p, int q){ //displays details of the piece existing in the box chosen by the user
	int x = p-1;
	int y = q-1;
	int val = chessBoard[x][y];
	if(val == 0) printf("No piece found\n");
	else printf("Piece: %s\n",chessPiecesFull[val-1]);
	return chessBoard[x][y];
}

void playGame(){ //runs continuous loop until 9 9 is entered
	int x,y;
	char c;
	int i;
	printf("Player 1 is White!\nPlayer 2 is Black!\nPlayer 1 Turn:\n");
	printf("Enter 9 9 to exit\n");
	printf("Enter 0 0 to print\n");
	while(x!=9){
		printf("Enter piece location: ");
		scanf("%d %d",&x,&y);
//		scanf("%c%d",&c,&x);
//		for(i=0;i<8;i++){
//			if(c == alpha[i]){
//				y = i+1;
//				break;
//			}
//		}
		int piece = pieceDetails(x,y);
		switch(piece){
			case 0:
				printBoard();
				break;
			case 1:
				rookMoves(x,y);
				break;
			case 2:
				knightMoves(x,y);
				break;
			case 3:
				bishopMoves(x,y);
				break;
			case 4:
				queenMoves(x,y);
				break;
			case 5:
				kingMoves(x,y);
				break;
			case 6:
				pawnMoves_Black(x,y);
				break;
			case 7:
				rookMoves(x,y);
				break;
			case 8:
				knightMoves(x,y);
				break;
			case 9:
				bishopMoves(x,y);
				break;
			case 10:
				queenMoves(x,y);
				break;
			case 11:
				kingMoves(x,y);
				break;
			case 12:
				pawnMoves_White(x,y);
				break;
			default:
				printf("Default");
				break;
		}
	}
}
int main(){ //main function
	playGame();
}

// Identified Issues:
	//Still takes input on not finding any possible moves
	//Player system is yet to be re-mastered i.e black can move only black pieces
	//The possible moves are only printed once and not stored, which does not let us verify users move as a valid move
	//Does not do pawn promotion
	//checkDiagonal has issues
