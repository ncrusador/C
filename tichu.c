// tichu.c
// all rights reserved!
// by <ncrusador>
#include <stdio.h>

int main() {
	// Start //
	int i,j,ch,c,b,m,n,o,p,eof=1; /* c=plhthos kartwn, b=cards-of-same-symbol counter(b=1:monofulia,b=2:zeugos,b=3:tripleta,b=4:vomva */
	char k[15][5],bomb[13],triple[13],duo[13],single[13];
	/* original size=k[14][4], bomb[]=possible bombs, triple[]=tripletes, duo[]=zeugaria, single[]=monofullies */
	printf("\n-------TICHU-------  {by ncrusador}\n\n-> Ctrl+Z to restart at any time <-\n\n");
while(eof) {
	// Initialization //
	c=56;
	for(i=0;i<=12;i++) { /* arxikopoihsh pinaka[] vomvwn/tripletwn/diplwn (mh anagkaio) */
		bomb[i]='-';
		triple[i]='-';
		duo[i]='-';
	}
	for(j=2;j<=5;j++) { /* initialize the array[][] of cards - arxikopoihsh pinaka kartwn */
		k[2][j]='2';
		k[3][j]='3';
		k[4][j]='4';
		k[5][j]='5';
		k[6][j]='6';
		k[7][j]='7';
		k[8][j]='8';
		k[9][j]='9';
		k[10][j]='0'; // 0=10
		k[11][j]='j'; // j=Vales
		k[12][j]='q'; // q=Ntama
		k[13][j]='k'; // k=Rhgas
		k[14][j]='1'; // 1=Assos
		
	}
	k[15][2]='s', k[15][3]='m', k[15][4]='d', k[15][5]='f'; /* s=Skulia, m=Maj Yong, d=Drakos, f=Foinikas */
	// Search //
	printf("\nType all revealed cards {after trading!}\n=> Give: ");
	ch=getchar();
	while(ch!=EOF) {
		//
		for(;;) {
			if(ch=='\n') {
				break;
			}
			for(i=2;i<=15;i++) { /* search to find the given char in the array[][] of cards (if that given element exists) */
				for(j=2;j<=5;j++) {
					if((ch==k[i][j])&&(k[i][j]!='-')) {
						k[i][j]='-';
						c--;
						break;
					}
				}
			}
			ch=getchar();
		}
		// Kentes // [INCOMPLETE]
		if((k[15][5]=='f')&&(c<56)) { // kentes xwris foinika
			for(i=2;i<=10;i++) { // minimum=5 fulla
				//
			}
		}
		else { // kentes me foinika, minimum kkkkf/fkkkk/kfkkk/kkkfk/kkfkk fulla
			//
		}
		/* bomb/triple/double checking (joker f included) */
		m=n=o=p=0;
		for(i=2;i<=14;i++) { 
			b=1;
			for(j=2;j<=4;j++) {
				if((k[i][j]==k[i][5])&&(k[i][5]!='-')&&(c<56)) {
					b++;
				}
			}
			if(b==4) {
				m++;
				bomb[m]=k[i][5];
			}
			else if(b==3) {
				n++;
				triple[n]=k[i][5];
			}
			else if(b==2) {
				o++;
				duo[o]=k[i][5];
			}
			else if(k[i][5]!='-') { // b==1 and k[][] not '-'
				p++;
				single[p]=k[i][5];
			}
		}
		printf("||||\n");
		// Double -->
		if((k[15][5]=='f')&&(c<56)&&(p)) { //me foinika
			printf("Double: ");
			for(i=1;i<=o;i++) {
				putchar(duo[i]);
				putchar(',');
				putchar(' ');
			}
			for(i=1;i<=p;i++) {
				putchar(single[i]);
				putchar('f');
				putchar(',');
				putchar(' ');
			}
			printf("\b\b \n");
		}
		else if(o) { // xwris foinika
			printf("Double: ");
			for(i=1;i<=o;i++) {
				putchar(duo[i]);
				putchar(',');
				putchar(' ');
			}
			printf("\b\b \n");
		}
		// Triple -->
		if((k[15][5]=='f')&&(c<56)&&(o)) { // me foinika
			printf("Triple: ");
			for(i=1;i<=n;i++) {
				putchar(triple[i]);
				putchar(',');
				putchar(' ');
			}
			for(i=1;i<=o;i++) {
				putchar(duo[i]);
				putchar('f');
				putchar(',');
				putchar(' ');
			}
			printf("\b\b \n");
		}
		else if(n) { // xwris foinika
			printf("Triple: ");
			for(i=1;i<=n;i++) {
				putchar(triple[i]);
				putchar(',');
				putchar(' ');
			}
			printf("\b\b \n");
		}
		// Bomb -->
		if(m) {
			printf("Possible bomb: "); //(i)
			for(i=1;i<=m;i++) {
				putchar(bomb[i]);
				putchar(',');
				putchar(' ');
			}
			printf("\b\b \n"); //(i)
		}
		else if((c)&&(c<56)) {
			printf("No bombs\n"); //(ii)
		}
		else if(c==0) {
			printf("Finished\n"); //(iii)
		}
		else if(c==56) {
			printf("Start\n"); //(0)
		}
		// Ektupwseis //
		if(c) {
			printf("Remaining cards are: (%d)\n",c); //(i),(ii)
		}
		else {
			printf("Game is over!\nPress {Ctrl+Z} to restart or exit.\n"); //(iii)
		}
		for(i=1;i<=16;i++) { /* emfanish plaisiou */
			putchar('*');
			putchar(' ');
		}
		putchar('\n');
		for(j=2;j<=5;j++) { /* ektupwsh twn ekastote uparxontwn kartwn */
			putchar('*');
			putchar(' ');
			for(i=2;i<=15;i++) {
				putchar(k[i][j]);
				putchar(' ');
		}
			putchar('*');
			putchar('\n');
		}
		for(i=1;i<=16;i++) { /* emfanish plaisiou */
			putchar('*');
			putchar(' ');
		}
		printf("\n\n=> Give: ");
	ch=getchar();
	}
	// Repeat the game //
	printf("End of Game!\n--------------------------------\nPress ENTER to play again, or type everything else to exit: ");
	if((ch=getchar())!='\n') {
		eof=0;
	}
	printf("\n--------------------------------\n");
} // End //
	printf("\n!!!BYE!!!\n-- by ncrusador --  O:::[]======>\n");
	return;
}
