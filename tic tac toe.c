#include <stdio.h>

int check(char A[][3]);
char c = '.';

int main() {
	
	int player, moves, x, y, win;
	char A[3][3];
	//
	for(x=0; x<3; x++) {
		for(y=0; y<3; y++) {
			A[x][y]=c;
		}
	}
	//
	printf("\t >> TIC TAC TOE <<\n\n");
	moves = 9;
	player = 2023;
	do {
		printf("\n\t    1     2     3 \n\n");
		printf("\t1   %c  |  %c  |  %c \n", A[0][0], A[0][1], A[0][2]);
		printf("\t   ----|-----|----\n");
		printf("\t2   %c  |  %c  |  %c \n", A[1][0], A[1][1], A[1][2]);
		printf("\t   ----|-----|----\n");
		printf("\t3   %c  |  %c  |  %c \n", A[2][0], A[2][1], A[2][2]);
		//
		win = check(A);
		if(!moves || win) break;
		player++;
		printf("\nPlayer %d: ", player%2 + 1);
		//
		do {
			scanf("%d %d", &x, &y);
		} while((x<1)||(x>3)||(y<1)||(y>3));
		if(A[x-1][y-1]!=c) {
			printf("\t\t\t try again!\n");
			player--;
			continue;
		}
		//
		if(player%2==0) {
			A[x-1][y-1] = 'X';
		}
		else {
			A[x-1][y-1] = 'O';
		}
		
		moves--;
	} while(2023);
	//
	if(win) printf("\n\n > Player (%d) won !!!!\n\n", player%2 + 1);
	else printf("\n\t\t\tISOPALIA\n\n");
	//
	return 0;
}
////
int check(char A[][3]) {
	
	if     (A[0][0]==A[0][1] && A[0][1]==A[0][2] && A[0][0]!=c) return 1; //rows
	else if(A[1][0]==A[1][1] && A[1][1]==A[1][2] && A[1][0]!=c) return 1;
	else if(A[2][0]==A[2][1] && A[2][1]==A[2][2] && A[2][0]!=c) return 1;
	
	else if(A[0][0]==A[1][0] && A[1][0]==A[2][0] && A[0][0]!=c) return 1; //columns
	else if(A[0][1]==A[1][1] && A[1][1]==A[2][1] && A[0][1]!=c) return 1;
	else if(A[0][2]==A[1][2] && A[1][2]==A[2][2] && A[0][2]!=c) return 1;
	
	else if(A[0][0]==A[1][1] && A[1][1]==A[2][2] && A[0][0]!=c) return 1; //diagonals
	else if(A[2][0]==A[1][1] && A[1][1]==A[0][2] && A[2][0]!=c) return 1;
	
	else return 0;
}
//

