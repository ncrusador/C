// GAME: Battleship - 01/07/2023
#include <iostream>
#include <time.h>
#define SIZE 10

using namespace std;

const char ch1 = '-'; // empty sea
const char ch2 = 254; // ship part
const char ch3 = 'x'; // hit

int main() {
	
	short i, j, moves, valid, a, b, direction, length, dl, dr, dd, dt, extra_ship, c2, x, ships;
	char Player_view[SIZE][SIZE], Board[SIZE][SIZE], c1, letter, M[SIZE];
	string message;
	srand(time(0));
	
	do { // GAME REPEAT
		// INITIALISE
		moves = 0;
		ships = 5 + 4 + 3 + 3 + 2;
		for(i=0; i<SIZE; i++) {
			for(j=0; j<SIZE; j++) {
				Player_view[i][j] = ch1;
				Board[i][j] = ch1;
			}
			M[i] = 219; // percentage message visual bar
		}
		
		// SHIPS CREATION		
		length = 5; // 1st ship's size, then 4, 3, 3, 2
		letter = 'a'; // visualisation of differents ships on test board: aaaaaa, bbbb, ccc, ddd, ee
		extra_ship = 0;
		while(length>=2) {
			valid = 0;
			a = rand()%SIZE; b = rand()%SIZE; // coordinates
			if(Board[a][b]!=ch1) continue;
			dl = dr = dt = dd = 0; // flags of directions been checked
			do {
				direction = rand()%4; // direction of ship , 0=right 1=down 2=left 3=top
				if(!direction && !dr) { // right
					dr=1;
					if(b+length>=SIZE-1) continue; // off boundry
					j=0;
					for(i=1; i<=length; i++) {
						if(Board[a][b+i]==ch1) j++; // count of valid cells
					}
					if(j==length) { // if all cells are valid then ship can be spawn
						valid = 1;
						for(i=1; i<=length; i++) Board[a][b+i] = letter; // draw ship onto test board with a different letter
					};
				}
				else if(direction==1 && !dd) { // down
					dd = 1;
					if(a+length>=SIZE-1) continue;
					j=0;
					for(i=1; i<=length; i++) {
						if(Board[a+i][b]==ch1) j++;
					}
					if(j==length) {
						valid = 1;
						for(i=1; i<=length; i++) Board[a+i][b] = letter;
					};
				}
				else if(direction==2 && !dl) { // left
					dl = 1;
					if(b-length<0) continue;
					j=0;
					for(i=1; i<=length; i++) {
						if(Board[a][b-i]==ch1) j++;
					}
					if(j==length) {
						valid = 1;
						for(i=1; i<=length; i++) Board[a][b-i] = letter;
					};
				}
				else if(direction==3 && !dt) { // top
					dt = 1;
					if(a-length<0) continue;
					j=0;
					for(i=1; i<=length; i++) {
						if(Board[a-i][b]==ch1) j++;
					}
					if(j==length) {
						valid = 1;
						for(i=1; i<=length; i++) Board[a-i][b] = letter;
					};
				}
			} while(dr+dd+dt+dl<4 && !valid); // while possible direction
			
			if(valid) {
				if(length==3 && !extra_ship) { // create an extra 3-long ship
					extra_ship = 1;
					length++;
				}
				length--;
				letter++;
			}
		}
		
		// GAME START
		printf("\n--------------------- BATTLESHIP GAME ---------------------\n\n");
		printf("Find and sink all enemy ships!\nThere are: (1x) 5-long, (1x) 4-long, (2x) 3-long, (1x) 2-long ships.\n");
		printf("Coordinates: [A-F, 1-10]. | 00 to stop.\n");
		
		do {
			printf("\n\t ");
			for(i=1; i<=SIZE; printf(" %3d", i++));
			//for(i=1, printf("\t "); i<=SIZE; printf(" %3d", i++)); // Reveal Board for Testing
			if(moves<17) message = "IMPOSSIBLE";
			else if(moves<SIZE*SIZE*0.3) message = "GOD";
			else if(moves<SIZE*SIZE*0.4) message = "SMART";
			else if(moves<SIZE*SIZE*0.5) message = "VERY GOOD";
			else if(moves<SIZE*SIZE*0.6) message = "GOOD";
			else if(moves<SIZE*SIZE*0.7) message = "AVERAGE";
			else if(moves<SIZE*SIZE*0.8) message = "BAD";
			else message = "VERY BAD";
			printf("\t{%s}", message.c_str());
			printf("\n\n");
					
			letter = 'A';
			for(i=0; i<SIZE; i++) {
				printf("\t%c", letter);
				for(j=0; j<SIZE; printf(" %3c", Player_view[i][j++]));
				//for(j=0, printf("\t%c", letter); j<SIZE; printf(" %3c", Board[i][j++])); // Reveal Board for Testing
				printf("\t |%c|", M[i]);
				printf("\n\n");
				letter++;
			}
			
			if(!ships) break;
			printf("(Moves: %d) | Next hit: ", moves);
			cin>>c1>>c2; // coordinates
			
			if(c1=='0' && c2==0) break; // reset game
			if(c1>='a' && c1<='z') c1 -= 'a'-'A'; // turn lowercase into caps				
			if(c1<'A' || c2<1 || c1>'A'+SIZE-1 || c2>SIZE) { // out of boundries or random shit
				printf("\n\n\t\tWrong input!\n");
				continue;
			}
			
			c1 -= 'A'; // turn letter into number
			if(Board[c1][c2-1]==ch3 || Board[c1][c2-1]==ch2) {
				printf("\n\n\t\tAlready hit there - Ship parts remain {%d}\n", ships);
			}
			else if(Board[c1][c2-1]==ch1) {
				Board[c1][c2-1] = ch3;
				Player_view[c1][c2-1] = ch3;
				printf("\n\n\t\tEmpty sea !    -    Ship parts remain {%d}\n", ships);
				moves++;
			}
			else {
				Board[c1][c2-1] = ch2;
				Player_view[c1][c2-1] = ch2;
				printf("\n\n\t\tSuccessful hit!  -  Ship parts remain {%d}\n\a", --ships);
				moves++;
			}
			for(i=0, x=moves/SIZE; i<x; M[i++]=177); // message bar update every 10 valid moves
		} while(2023);
		
		printf("\n\t\t");
		if(!ships) printf("You Won !!!\t(Moves: %d)\t ~ %s", moves, message.c_str());
		else printf("Game Reset!");
		printf("\n\n> Press ENTER to play again, or any other key to exit: \a");
		getchar();
					
	} while(getchar()=='\n');
	
	printf("\n\n\t\t\tmade by ncrusador - 01/07/2023\n\n");
	system("pause");
	return 0;
}
////
