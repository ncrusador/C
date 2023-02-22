#include <stdio.h>

int main(void) {
	
	char size, i;
	char text[] = "\nThe Fibonacci sequence of ";;
	unsigned long long prev1, prev2, curr, sum;
	
	printf("\nGive amount of Fibonacci terms (1-92):\n");
	do {
		printf("> ");
		scanf("%hd", &size);
	} while( (size<1) || (size>92) );
	
	prev2=0; // o n-2 oros
	prev1=1; // o n-1 oros
	sum = 0;
	
	if(size==1) {
		printf("%s", text);
		printf("%d term is:\n\tFib(%2d):\t(%d)\n", size, size, 0);
		printf("\nAvg: 0\n");
	}
	else if(size==2) {
		printf("%s", text);
		printf("%d terms is:\n\tFib(%2d):\t(%d)\n\tFib(%2d):\t(%d)\n", size, 1, 0, 2, 1);
		printf("\nAvg: 0.50\n");
	}
	else {
		sum = prev1 + prev2;
		printf("%s", text);
		printf("%d terms is:\n\tFib(%2d):\t(%d)\n\tFib(%2d):\t(%d)\n", size, 1, 0, 2, 1);
		for(i=3; i<=size; i++) {
			curr = prev1 + prev2; // trexwn oros
			prev2 = prev1;
			prev1 = curr;
			sum += curr;
			printf("\tFib(%2d):\t(%lld)\n", i, curr);
		}
		printf("\nEnd of Fibonacci Sequence!\n\nAdded %u terms\nSum: %llu\nAvg: %lf [%.2lf%% of last term]\n", size, sum, sum/(size+0.0), ( (sum/(size+0.0))/curr ) * 100 );
	}
	
	printf("\n");
	return 0;
}