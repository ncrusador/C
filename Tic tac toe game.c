// Tic tac toe game
#include <stdio.h>

int check(char A[][3]);
const char ch1 = '.';
const char ch2 = 'X';
const char ch3 = 'O';

int main() {
	
	int player, moves, x, y, win;
	char A[3][3], ch;
	do { // GAME REPEAT
		// INITIALISE
		for(x=0; x<3; x++) {
			for(y=0; y<3; A[x][y++]=ch1);
		}
		printf("\n\n\t >> TIC TAC TOE <<\n\n");
		printf("Place your coordinates (1-3, 1-3) to play. | (0 0) to reset\n");
		moves = 9;
		player = 2023;
		ch = ch2;
		// GAME START
		do {
			printf("\n\t    1     2     3 \n\n");
			printf("\t1   %c  |  %c  |  %c \n", A[0][0], A[0][1], A[0][2]);
			printf("\t   ----|-----|----\n");
			printf("\t2   %c  |  %c  |  %c \n", A[1][0], A[1][1], A[1][2]);
			printf("\t   ----|-----|----\n");
			printf("\t3   %c  |  %c  |  %c \n", A[2][0], A[2][1], A[2][2]);
			
			win = check(A);
			if(!moves || win) break;
			player++;
			if(player%2) ch = ch3;
			else ch = ch2;
			printf("\n> Player %d [%c]: ", player%2 + 1, ch) ;
			
			scanf("%d %d", &x, &y);
			if(!x && !y) {
				win = 2;
				break;
			}
			else if(x<1 || y<1 || x>3 || y>3) {
				printf("\t\t\t wrong input!\n");
				player--;
				continue;
			}
			if(A[x-1][y-1]!=ch1) {
				printf("\t\t\t try again!\n");
				player--;
				continue;
			}
			
			if(player%2==0) A[x-1][y-1] = 'X';
			else A[x-1][y-1] = 'O';
			
			moves--;
		} while(2023);
		
		if(win==1) printf("\n\n > Player %d (%c) won !!!!\n\n\a", player%2 + 1, ch);
		else if(win==2) printf("\n\t\tRESET !\n\n\a");
		else printf("\n\t\tDRAW !\n\n\a");
		getchar(); // consunes the last \n
		printf("\n\n> Press ENTER to play again, or any other key to exit: \a");
		
	} while(getchar()=='\n');
	
	printf("\n\n\t\t\tmade by ncrusador - 01/07/2023\n\n");
	getchar();
	return 0;
}
////
int check(char A[][3]) {
	
	if     (A[0][0]==A[0][1] && A[0][1]==A[0][2] && A[0][0]!=ch1) return 1; //rows
	else if(A[1][0]==A[1][1] && A[1][1]==A[1][2] && A[1][0]!=ch1) return 1;
	else if(A[2][0]==A[2][1] && A[2][1]==A[2][2] && A[2][0]!=ch1) return 1;
	
	else if(A[0][0]==A[1][0] && A[1][0]==A[2][0] && A[0][0]!=ch1) return 1; //columns
	else if(A[0][1]==A[1][1] && A[1][1]==A[2][1] && A[0][1]!=ch1) return 1;
	else if(A[0][2]==A[1][2] && A[1][2]==A[2][2] && A[0][2]!=ch1) return 1;
	
	else if(A[0][0]==A[1][1] && A[1][1]==A[2][2] && A[0][0]!=ch1) return 1; //diagonals
	else if(A[2][0]==A[1][1] && A[1][1]==A[0][2] && A[2][0]!=ch1) return 1;
	
	else return 0;
}
//

