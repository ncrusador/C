// GAME: Bomb Puzzle - 26/05/2023
#include <iostream>
#include <time.h>
#define SIZE 10

using namespace std;
int off_boundry(int, int), next_cell(int, int, int*);
void current_cell(int, int);

char A[SIZE][SIZE], B[SIZE][SIZE]; // A: players screen, B game's hidden map
const char ch1 = '.'; // cell
const char ch2 = 'o'; // claimed cell
const char ch3 = 'A'; // current position
const char ch4 = 177; // destination
const char ch5 = 197; // cookie
const char ch6 = 254; // bomb
const char ch7 = 219; // detonated bomb
const char ch8 = 206; // claimed cookie
const char ch9 = 178; // claimed destination

int main() {
	// DECLARATION
	int i, j, bomb, a, b, score, cookie, x, moves;
	char input, current_state, ch;
	srand(time(0));
	do { // GAME'S REPEATETION
		// INITIALIZE		
		bomb = cookie = score = moves = 0; // counters
		a = b = 0; // indexes of current position in the game
		current_state = 0; // game's state flag
			
		for(i=0; i<SIZE; i++) {
			for(j=0; j<SIZE; j++) {
				x = rand()%20;
				if(i==0 && j==0) { // starting cell
					A[0][0] = ch3;
					B[0][0] = ch3;
				}
				else if((i==SIZE-1) && (j==SIZE-1)) { // winning cell
					A[i][j] = ch4;
					B[i][j] = ch4;
				}
				else if(!x) { // cookie cell
					A[i][j] = ch5;
					B[i][j] = ch5;
					cookie++;
				}
				else if(x>3) { // ordinary cell
					A[i][j] = ch1;
					B[i][j] = ch1;
				}
				else { // bomb cell
					A[i][j] = ch6;
					B[i][j] = ch1;
					bomb++;
				}
			}
		}	

		// GAME START
		printf("--------------------- BOMB PUZZLE ---------------------\n\n");
		printf("Get from start (%c) to finish (%c), avoiding the bombs (%c).\nEvery Cell (%c) is 1 point, every Cookie (%c) is 5 instead.\nThere are %d bombs and %d cookies randomly generated.\n", ch3, ch4, ch6, ch1, ch5, bomb, cookie);
		printf("Navigate using W, A, S, D. You can restart at any time using 0.\n");
		do {	
			printf("\n");
			for(i=0; i<SIZE; i++) {
				printf("\t");
				for(j=0; j<SIZE; j++) {
					if(current_state && A[i][j]==ch6 && B[i][j]!=ch7) printf(" %3c", ch6); // When game is over, reveal the bombs except the one that caused the death which it has its own character
					else printf(" %3c", B[i][j]); 
				}
				/*printf("\t\t"); // map tester
				for(j=0; j<SIZE; j++) { // map tester
					printf(" %3c", A[i][j]); // map tester
				}*/
				printf("\n\n");
			}
			if(current_state) break;
			printf("(Points: %2d) | (Move: %2d): ", score, moves);
			cin>>input;
			switch(input) {
				case '0': break;
				case 'w':
				case 'W': { // move up
					if(off_boundry(a-1, b)) break;
					current_cell(a, b);
					current_state = next_cell(--a, b, &score);
					moves++;
					break;
				}
				case 'a':
				case 'A': { // move left
					if(off_boundry(a, b-1)) break;
					current_cell(a, b);
					current_state = next_cell(a, --b, &score);
					moves++;
					break;
				}
				case 's':
				case 'S': { // move down
					if(off_boundry(a+1, b)) break;
					current_cell(a, b);
					current_state = next_cell(++a, b, &score);
					moves++;
					break;
				}
				case 'd':
				case 'D': { // move right
					if(off_boundry(a, b+1)) break;
					current_cell(a, b);
					current_state = next_cell(a, ++b, &score);
					moves++;
					break;
				}
				default: {
					break;
				}
			} // switch
			printf("\n\n\n------------------------------------------------------\n\n");
		}while(input!='0'); // while
		
		if(current_state==1) printf("\n> Points: %d| Moves: %d\t\tY O U   D I E D !\n\n", score, moves);
		else if(current_state==2) printf("\n> Points: %d| Moves: %d\t\tY O U   W O N !\n\n", score, moves);
		else printf("\n> Points: %d| Moves: %d\t\tA B O R T E D !\n\n", score, moves);
		printf("> Press ENTER to play again, or any other key to exit: \a");
		getchar();
	}while(getchar()=='\n');
	
	
	printf("\n\n\t\t\tmade by ncrusador - 26/05/2023\n\n");
	system("pause");
	
	return 0;
}
//
int off_boundry(int a, int b) {
	if(a<0 || b<0) return 1;
	else if(a>=SIZE || b>=SIZE) return 2;
	else return 0;
}

void current_cell(int a, int b) {
	if(A[a][b]==ch5) B[a][b] = ch8; // turn into claimed cookie
	else B[a][b] = ch2; // turn into body
	return;
}

int next_cell(int a, int b, int *x) {
	if(A[a][b]==ch6) { // bomb
		B[a][b] = ch7;
		return 1;
	}
	if(a==SIZE-1 && b==SIZE-1) { // win
		B[a][b] = ch9;
		return 2;
	}
	if(A[a][b]==ch5 && B[a][b]!=ch8) (*x)+=5; // if cookie && not claimed
	else if(B[a][b]!=ch2 && B[a][b]!=ch8) (*x)++;
	
	B[a][b] = ch3; // turn it to new head
	return 0;
}
////
