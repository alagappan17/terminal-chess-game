Terminal based two player chess game built using C.

The grid is of the format:
	 1   	 2   	 3   	 4   	 5   	 6   	 7   	 8
1	B_R 	B_N 	B_B 	B_Q 	B_K 	B_B 	B_N 	B_R
2	B_P	B_P	B_P	B_P	B_P	B_P	B_P	B_P
3	 *	 *	 *	 *	 *	 *	 *	 *
4	 *	 *	 *	 *	 *	 *	 *	 *
5	 *	 *	 *	 *	 *	 *	 *	 *
6	 *	 *	 *	 *	 *	 *	 *	 *
7	W_P	W_P	W_P	W_P	W_P	W_P	W_P	W_P
8	W_R 	W_K 	W_B 	W_Q 	W_K 	W_B 	W_K 	W_R

	-> To select a piece enter a box number in which the piece is present in the format - a b --> where a,b<=8 && a,b>=0.
	-> Once you select the piece you will be shown all the possible moves and then the terminal will be ready to take the input.
	-> After the move is entered in the same format as earlier it takes effect on the board and the board is displayed.
	-> To view the board you can type - 0 0.
	-> To exit the game type 9 9.
	-> All the moves made are recorded in the moves.txt files.

