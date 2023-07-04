#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINEDEF 119 // characters that fit to a line in default window
#define LINEMAX 236 // characters that fit to a line in full screen
#define LINEPOR 50 // characters that fit to a line in mobile portrait
#define LINELAN 101 // characters that fit to a line in mobile landscape

void sortInc(int*, int), sortDec(int*, int), sortRan(int*, int), sortSym(int*, int);
void swap(int*, int*), printOpt(int*, int, int, int), printPyr(int*, int, int), printVal(int*, int, int, int), poolSet(int*, int*, int, int, int);
float findSym(int*, int);
int findPop(int*, int, int*), findDif(int*, int, int, int), findMax(int*, int), findMin(int*, int), findSum(int*, int), findCon(int*, int, int*);
int search(int*, int, int), calcDig(int, int), sq_rt(int), scan_int(int*), rand_int(int, int);

int main(void) {
	// DECLARATION
	unsigned char pool, sort, message, input, device; // flags
	short case1, case2, case3, case4, case5, case6, case7, case8, case9, case10; // counters
	short option, option1, option2, option3, option4, option5, option6, option8, option10; // optionX: menu options
	int *A, *B, start, end, size, x, y, i, j; // A/B the dynamic Array, x/y/i/j: changable variables to play with, start/end/size: fixed vars
	long long int pro; // product
	float symmetry; // symmetry percentage (0-100)
	srand(time(NULL));
	// ARRAY CREATION
	printf("-----------------------\nA R R A Y  E D I T O R\n   (int version)\n-----------------------\n");
	do {
		printf("Array's size: ");
		if(!scan_int(&size)) {
			printf("\nProgram aborted\n");
			return -2;
		}
	}
	while(size<1);
	B = calloc(size, sizeof(int));
	if(B==NULL) {
		printf("\nCan not allocate memory\n");
		return -1;
	}
	A = B;
	// MENU  REPEAT
	message = 14;
	sort = 0;
	device = 1; // default windows pc
	case1=case2=case3=case4=case5=case6=case7=case8=case9=case10=0;
	do {
		printf("\n\n-------------------------------------------\n>> ");
		switch(message) { // ACTION MESSAGES
			case 0: {
				printf("Wrong Input!");
				break;
			}
			case 1: {
				printf("Array is Empty!");
				break;
			}
			case 2: {
				printf("No chosen value pool!");
				break;
			}
			case 3: {
				printf("No action");
				break;
			}
			case 4: {
				printf("Pool set from %d to %d (F)", start, end);
				break;
			}
			case 5: {
				printf("Array sorted in an increasing order");
				break;
			}
			case 6: {
				printf("Array sorted in an decreasing order");
				break;
			}
			case 7: {
				printf("Array sorted in a random order");
				break;
			}
			case 8: {
				printf("Summary: (%d)", x);
				break;
			}
			case 9: {
				printf("Average: (%.2f)", x/(size+0.0));
				break;
			}
			case 10: {
				printf("Product: (%lld)", pro);
				break;
			}
			case 11: {
				printf("Array filled randomly");
				break;
			}
			case 12: {
				printf("Array filled with (%d)s", x);
				break;
			}
			case 13: {
				printf("Array filled manually");
				break;
			}
			case 14: {
				printf("Array created with %d cells", size);
				break;
			}
			case 15: {
				printf("Most popular: (%d) x%d [%.2f%% of Array]", x, j, ((j+0.0)/(size))*100);
				break;
			}
			case 16: {
				printf("Unique values: %d [%.2f%% of pool]", x, ((x+0.0)/(end-start+1))*100);
				break;
			}
			case 17: {
				printf("There are values with 0");
				break;
			}
			case 18: {
				printf("Product is too large (>9.2 quantillion)");
				break;
			}
			case 19: {
				printf("Cell A[%d] replaced with the value (%d)", i-1, x);
				break;
			}
			case 20: {
				printf("Array printed optimally above");
				break;
			}
			case 21: {
				printf("Array printed only with (%d)s visible", y);
				break;
			}
			case 22: {
				printf("Action Aborted");
				break;
			}
			case 23: {
				printf("Value (%d) replaced with (%d) [x%d]", y, x, j);
				break;
			}
			case 24: {
				printf("Array's information & stats printed ^");
				break;
			}
			case 25: {
				printf("Min: (%d) x%d | Max: (%d) x%d", x, search(A, size, x), y, search(A, size, y));
				break;
			}
			case 26: {
				printf("Value (%d) found x%d [%.2f%% of Array]", y, j, (j+0.0)/size*100);
				break;
			}
			case 27: {
				printf("Value (%d) was not found", y);
				break;
			}
			case 28: {
				printf("Array filled with values from [%d, %d]", A[0], A[size-1]);
				break;
			}
			case 29: {
				printf("Cell [%d] contains the value of (%d)", i, A[i-1]);
				break;
			}
			case 30: {
				printf("Array is (%.2f%%) Symmetric", symmetry);
				break;
			}
			case 31: {
				printf("Array is full Symmetric!");
				break;
			}
			case 32: {
				printf("Array sorted in a symmetric order (%.2f%%)", symmetry);
				break;
			}
			case 33: {
				printf("Array printed in %d columns above", j);
				break;
			}
			case 34: {
				printf("Array printed in maximum line length above");
				break;
			}
			case 35: {
				printf("Array printed serially above");
				break;
			}
			case 36: {
				printf("Array printed in a pyramid shape above");
				break;
			}
			case 37: {
				printf("Pool set from %d to %d (R)", start, end);
				break;
			}
			case 38: {
				printf("Pool mode switched from (F) to (R)");
				break;
			}
			case 39: {
				printf("Pool mode switched from (R) to (F)");
				break;
			}
			case 40: {
				printf("Couldn't reallocate extra memory");
				break;
			}
			case 41: {
				printf("Array resized from [%d] to [%d] cells", y, size);
				break;
			}
			case 42: {
				printf("Array resized from [%d] to [%d] cells\n   Extra cells initialized with (%d)s", y, size, x);
				break;
			}
			case 43: {
				printf("Value (%d) repeats x%d consecutively", x, j);
				break;
			}
			case 44: {
				printf("Device set to Default [PC]");
				break;
			}
			case 45: {
				printf("Device set to Full Screen [PC]");
				break;
			}
			case 46: {
				printf("Device set to Mobile [Portrait]");
				break;
			}
			case 47: {
				printf("Device set to Mobile [Landscape]");
				break;
			}
			case 48: {
				printf("");
				break;
			}
			case 49: {
				printf("");
				break;
			}
			case 50: {
				printf("");
				break;
			}
			case 51: {
				printf("");
				break;
			}
			case 52: {
				printf("");
				break;
			}
			case 53: {
				printf("");
				break;
			}
			default: {
				printf("No action");
				break;
			}
		}
		printf("\n");
		// ARRAY INFO
		printf("* Array's Size [%d]", size);
		if(case2) {
			if(pool==1) printf("\n* Values (F): [%d, %d]", start, end);
			else if(pool==2) printf("\n* Values (R): [%d, %d]", start, end);
		}
		if(case5) { // SORT INFO
			if(sort==1) {
				printf("\n* Sorting: Increasingly");
			}
			else if(sort==2) {
				printf("\n* Sorting: Decreasingly");
			}
			else if(sort==3) {
				printf("\n* Sorting: Randomly");
			}
			else if(sort==4) {
				printf("\n* Sorting: All equal");
			}
			else if(sort==5) {
				printf("\n* Sorting: Symmetricly");
			}
			else { //sort=0
				printf("\n* Sorting: Unknown");
			}
		}
		// MAIN MENU
		printf("\n");
		printf("*************** ARRAY MENU ****************\n");
		printf("** (0)  Exit                             **\n** (1)  Calculate                        **\n** (2)  Adjust value pool                **\n** (3)  Sort Array                       **\n");
		printf("** (4)  Print Array                      **\n** (5)  Fill Array                       **\n** (6)  Replace                          **\n** (7)  Info & Stats                     **\n");
		printf("** (8)  Search                           **\n** (9)  Change Array's size              **\n** (10) Settings                         **\n*******************************************\n");
		printf("> "); // 43 chars menu line length
		scanf("%hd", &option);
		printf("\n");
		switch(option) {
			case 0: { // EXIT
				break;
			}
			case 1: { // CALCULATE
				if(!case5) {
					message = 1;
					break;
				}
				do {
					printf(":------{Calculations}------:\n| 0. Back                  |\n| 1. Summary               |\n| 2. Average               |\n| 3. Product               |\n| 4. Most Popular value    |\n");
					printf("| 5. Unique values         |\n| 6. Min & Max             |\n| 7. Most Consecutive      |\n| 8. Symmetry              |\n:--------------------------:\n");
					printf(">> "); // 28 chars menu line length
					scanf("%hd", &option1);
				}
				while((option1<0) || (option>8));
				switch(option1) {
					case 0: { // back
						message = 3;
						break;
					}
					case 1: { // sum
						x = findSum(A, size);
						message = 8;
						case1++;
						break;
					}
					case 2: { // avg
						x = findSum(A, size);
						message = 9;
						case1++;
						break;
					}
					case 3: { // pro
						pro=1;
						j=0; // counting negative numbers
						for(i=0; i<size; i++) {
							if(A[i]==0) { // multiply with 0
								message = 17;
								break;
							}
							if(A[i]<0) j++; // negative numbers
								
							pro *= A[i];
						}
						if(message==17) break; // multiply with 0
						if(!pro) { // for some reason when product gets too high it returns 0 :?
							message = 18;
							break;
						}
						else if((pro<0) && (j%2==0)) { // if product is negative, but there is an even amount of negative numbers, then overflowed.
							message = 18;
							break;
						}
						case1++;
						message = 10;
						break;
					}
					case 4: { // popular
						case1++;
						x = findPop(A, size, &j);
						message = 15;
						break;
					}
					case 5: { // different
						case1++;
						x = findDif(A, size, start, end);
						message = 16;
						break;
					}
					case 6: { // min & max
						case1++;
						x = findMin(A, size);
						y = findMax(A, size);
						message = 25;
						break;
					}
					case 7: { // consecutive
						case1++;
						x = findCon(A, size, &j);
						message = 43;
						break;
					}
					case 8: { // symmetry
						case1++;
						symmetry=findSym(A, size);
						if(symmetry==100) {
							message = 31;
							sort=5;
						}
						else if((symmetry>50) && (sort!=4)) {
							message = 30;
							sort=5;
						}
						else {
							message = 30;
						}
						break;
					}
				}
				break;  
			}
			case 2: { // POOL
				do {
					printf(":-----------{Adjust Pool}-----------:\n| 0. Back                           |\n| 1. Adjust new pool (flexible)     |\n");
					printf("| 2. Adjust new pool (restricted)   |\n| 3. Switch mode (F) <=> (R)        |\n| 4. Fit to [min, max]              |\n:-----------------------------------:\n>> "); // 37 char menu line length)
					scanf("%hd", &option2);
				}
				while((option2<0)||(option2>4));
				switch(option2) {
					case 0: { // back
						message = 3;
						break;
					}
					case 1: { // new pool (F)
						pool = 1;
						if(case2) {
							printf("Previous pool: [%d, %d]\n", start, end);
						}
						printf("Values (F) [?, ?]: ");
						scanf("%d %d", &x, &y);
						poolSet(&start, &end, x, y, 2);
						message = 4;
						case2++;
						break;
					}
					case 2: { // new pool (R)
						pool = 2;
						if(case2) {
							printf("Previous pool: [%d, %d]\n", start, end);
						}
						printf("Values (R) [?, ?]: ");
						scanf("%d %d", &x, &y);
						poolSet(&start, &end, x, y, 2);
						message = 37;
						case2++;
						break;
					}
					case 3: { // switch mode
						if(!case2) {
							message = 2;
							break;
						}
						if(pool==1) {
							pool = 2;
							message = 38;
						}
						else {
							pool = 1;
							message = 39;
						}
						break;
					}
					case 4: { // fit to min-max
						if(!case2) {
							message = 2;
							break;
						}
						poolSet(&start, &end, findMin(A, size), findMax(A, size), 2);
						pool = 2;
						case2++;
						message = 37;
						break;
					}
				}
				break;
			}
			case 3: { // SORT
				if(!case5) {
					message=1;
					break;
				}			
				do {
					printf(":-------{Sort}-------:\n| 0. Back            |\n| 1. Increasingly    |\n| 2. Decreasingly    |\n"); 
					printf("| 3. Randomly        |\n| 4. Symmetricly     |\n:--------------------:\n");
					printf(">> "); // 22 chars menu line length
					scanf("%hd", &option3);
				}
				while((option3<0)||(option3>4));
				switch(option3) {
					case 0: { // back
						message=3;			
						break;
					}
					case 1: { // increasing
						sort=1;
						sortInc(A, size);
						case3++;
						message=5;
						break;
					}
					case 2: { // decreasing
						sort=2;
						sortDec(A, size);
						case3++;
						message=6;
						break;
					}
					case 3: { // randomly
						sort=3;
						sortRan(A, size);
						case3++;
						message=7;
						break;
					}
					case 4: { // symmetricly
						sortSym(A, size);
						symmetry=findSym(A, size);
						if((symmetry>50) && (sort!=4)) {
							sort=5;
						}
						else sort=0;
						case3++;
						message=32;
						break;
					}
				}
				break;
			}
			case 4: { // PRINT
				if(!case5) {
					message = 1;
					break;
				}
				do {
					printf(":----------{Print}-----------:\n| 0. Back                    |\n| 1. Optimally               |\n| 2. In one column           |\n| 3. In one line             |\n");
					printf("| 4. Pyramid shape           |\n| 5. Show only a value       |\n| 6. Choose the columns      |\n:----------------------------:\n");
					printf(">> "); // 28 chars menu line length
					scanf("%hd", &option4);
				}
				while((option4<0)||(option4>12));
				switch(option4) {
					case 0: { // back
						message = 3;
						break;
					}
					case 1: { // optimal default
						if (device==1) printOpt(A, size, 1, LINEDEF);
						else if (device==2) printOpt(A, size, 1, LINEMAX);
						else if (device==3) printOpt(A, size, 1, LINEPOR);
						else if (device==4) printOpt(A, size, 1, LINELAN);
						
						case4++;
						message = 20;
						break;
					}
					case 2: { // one column
						printOpt(A, size, 2, 1);
						
						case4++;
						message = 35;
						break;
					}
					case 3: { // one line 
						printOpt(A, size, 3, LINEMAX);
						
						case4++;
						message = 34;
						break;
					}
					case 4: { // pyramid
						if (device==1) printPyr(A, size, LINEDEF);
						else if (device==2) printPyr(A, size, LINEMAX);
						else if (device==3) printPyr(A, size, LINEPOR);
						else if (device==4) printPyr(A, size, LINELAN);
						
						case4++;
						message = 36;
						break;
					}
					case 5: { // show value only
						printf("\nChoose value not to hide: ");
						if(!(input=scan_int(&y))) {
							message = 22;
							break;
						}
						if(!search(A, size, y)) {
							message = 27;
							break;
						}
						if (device==1) printVal(A, size, y, LINEDEF);
						else if (device==2) printVal(A, size, y, LINEMAX);
						else if (device==3) printVal(A, size, y, LINEPOR);
						else if (device==4) printVal(A, size, y, LINELAN);
						
						case4++;
						message = 21;
						break;
					}
					case 6: { // x columns
						printf("\nColumns: ");
						if(!(input=scan_int(&j))) {
							message = 22;
							break;
						}
						if(j<1) {
							message = 0;
							break;
						}
						printOpt(A, size, 2, j);
						
						case4++;
						message = 33;
						break;
					}
				}
				break;
			}
			case 5: { // FILL
				if(!case2) {
					message = 2;
					break;
				}
				do {
					printf(":--------------{Fill}-------------:\n| 0. Back                         |\n| 1. Randomly within pool         |\n| 2. One same value               |\n| 3. Manually                     |\n");
					printf("| 4. Counting up from a value     |\n| 5. Counting down from a value   |\n:---------------------------------:\n");
					printf(">> "); // 35 chars menu line length
					scanf("%hd", &option5);
				}
				while((option5<0)||(option5>5));
				switch(option5) {
					case 0: { // back
						message = 3;
						break;
					}
					case 1: { // randomly
						x = end - start + 1; // size of pool
						for(i=0;i<size;i++) {
							if(x>RAND_MAX) A[i] = rand_int(start, end);
							else A[i] = rand()%x + start;
						}
						case5++;
						sort = 3;
						message = 11;
						break;
					}
					case 2: { // one value
						if(pool==2) { // (R)
								do {
								printf("\nPool (R) [%d, %d]\nValue: ", start, end);
								if(!(input=scan_int(&x))) break;
							}
							while((x<start)||(x>end));
						}
						else { // (F)
							printf("\nPool (F) [%d, %d]\nValue: ", start, end);
							if(!(input=scan_int(&x))) {
								message = 22;
								break;
							}
							poolSet(&start, &end, start, x, 1);
						}
						if(!input) { // eof
							message = 22;
							break;
						}
						for(i=0;i<size;i++) {
							A[i]=x;
						}
						case5++;
						sort = 4;
						message = 12;
						break;
					}
					case 3: { // manually
						if(pool==2) printf("\nPool (R) [%d, %d]\n", start, end);
						else printf("\nPool (F) [%d, %d]\n", start, end);
						for(i=0; i<size; i++) {
							printf("(%d/%d): ", i+1, size);
							if(pool==2) { // (R)
								do {
									if(!(input=scan_int(&x))) break;
									if((x<start) || (x>end)) {
										printf("Pool (R) [%d, %d]\n(%d/%d): ", start, end, i+1, size);
									}
								} while( (x<start) || (x>end) );
								if(!input) break;
							}
							else { // (F)
								if(!(input=scan_int(&x))) break;
							}
							A[i]=x;
						}
						if(!input) { // eof
							message = 22;
							break;
						}
						if(pool==1) poolSet(&start, &end, findMin(A, size), findMax(A, size), 1);
						sort = 0;
						case5++;
						message = 13;
						break;
					}
					case 4: { // counting up
						printf("\nGive starting value: ");
						if(!(input=scan_int(&j))) {
							message = 22;
							break;
						}
						if(pool==1) { // (F)
							poolSet(&start, &end, j, size+j-1, pool);
							for(i=0; i<size; i++) A[i]=j++;
						}
						else { // (R)
							for(i=0; i<size; i++, j++) {
								if((j>=start) && (j<=end)) A[i] = j;
								else if(j<start) A[i] = start;
								else A[i] = end;
							}
						}
						case5++;
						message = 28;
						sort = 1;
						break;
					}
					case 5: { // counting down
						
						printf("\nGive starting value: ");
						if(!(input=scan_int(&j))) {
							message = 22;
							break;
						}
						if(pool==1) { // (F)
							poolSet(&start, &end, j-size+1, j, pool);
							for(i=0; i<size; i++) A[i]=j--;
						}
						else { // (R)
							for(i=0; i<size; i++, j--) {
								if((j>=start) && (j<=end)) A[i] = j;
								else if(j<start) A[i] = start;
								else A[i] = end;
							}
						}
						case5++;
						message = 28;
						sort = 2;
						break;
					}
				}
				break;
			}
			case 6: { // REPLACE
				if(!case5) {
					message=1;
					break;
				}
				do {
					printf(":-----{Replace values}-----:\n| 0. Back                  |\n| 1. A cell                |\n");
					printf("| 2. A value               |\n:--------------------------:\n");
					printf(">> "); // 28 chars menu line length
					scanf("%hd", &option6);
				}
				while((option6<0)||(option6>2));
				switch(option6) {
					case 0: { // back
						message = 3;
						break;
					}
					case 1: { // replace a cell
						printf("\n");
						do {
							printf("Pick the cell (%d - %d): ", 1, size);
							if(!(input=scan_int(&i))) break;
						}
						while((i<1)||(i>size));
						if(!input) {
							message = 22;
							break;
						}
						if(pool==2) { // (R)
							printf("\nPool (R): [%d, %d]\n", start, end);
							do {
								printf("Previous: (%d) | New: ", A[i-1]);
								if(!(input=scan_int(&x))) break;
							} while((x<start)||(x>end));
						}
						else { // (F)
							printf("\nPool (F): [%d, %d]\n", start, end);
							printf("Previous: (%d) | New: ", start, end, A[i-1]);
							if(!(input=scan_int(&x))) {
								message = 22;
								break;
							}
							poolSet(&start, &end, start, x, 1);
						}
						if(!input) {
							message = 22;
							break;
						}
						A[i-1]=x;
						message = 19;
						sort = 0;
						case6++;
						break;
					}
					case 2: { // replace a value 
						printf("\nPool (R): [%d, %d]", start, end);
						printf("\nReplace the value: ");
						if(!(input=scan_int(&y))) {
							message = 22;
							break;
						}
						if((y<start)||(y>end)) {
							message = 27;
							break;
						}
						
						if(pool==2) { // (R)
							do {
								printf("With the new: ");
								if(!(input=scan_int(&x))) {
									message = 22;
									break;
								}
							} while((x<start)||(x>end));
						}
						else { // (F)
							printf("With the new: ", start, end);
							if(!(input=scan_int(&x))) {
								message = 22;
								break;
							}
							poolSet(&start, &end, start, x, 1);
						}
						
						j = 0; //count
						for(i=0; i<size; i++) {
							if(A[i]==y) {
								A[i]=x;
								j++;
							}
						}
						if(j) {
							message = 23;
							sort = 0;
							case6++;
						}
						else {
							message = 27;
						}
						break;
					}
				}
				break;	
			}
			case 7: { // INFO
				if(!case5) {
					message = 1;
					break;
				}
				printf("\n (%d)---{I N F O R M A T I O N}---", ++case7);
				printf("\n Calculations:%3d | Pool sets: %3d\n Sortings:    %3d | Printages: %3d\n Fillages:    %3d | Replaces:  %3d\n Searches:    %3d | Resizes:   %3d\n",case1,case2,case3,case4,case5,case6,case8,case9);
				printf("\n Array[%d] , Pool: [%d, %d]", size, start, end);
				x = findMin(A, size);
				y = findMax(A, size);
				i = (int) findSum(A, size)/(size+0.0);
				printf("\n Min: (%d) x%d , Max: (%d) x%d , Avg: (%d) x%d", x, search(A, size, x), y, search(A, size, y), i, search(A, size, i));
				printf("\n Symmetry: (%.2f%%)", findSym(A, size));
				printf("");
				message = 24;
				break;
			}
			case 8: { // SEARCH
						if(!case5) {
							message = 1;
							break;
						}
						do {
							printf(":------{Search}------:\n| 0. Back            |\n| 1. A value         |\n| 2. Check a cell    |\n:--------------------:\n");
							printf(">> "); // 22 chars menu line length
							scanf("%hd", &option8);
						} while((option8<0)||(option8>2));
						switch(option8) {
							case 0: { // back
								message = 3;
								break;
							}
							case 1: { // a value
								printf("\n");
								do {
									printf("Value to search [%d, %d]: ", start, end);
									if(!(input=scan_int(&y))) break;
								} while((y<start)||(y>end));
								if(!input) {
									message = 22;
									break;
								}
								j = search(A, size, y);
								if(j) message = 26;
								else message = 27;
								case8++;
								break;
							}
							case 2: { // a cell
								printf("\n");
								do {
									printf("Choose a cell (%d-%d): ", 1, size);
									if(!(input=scan_int(&i))) break;
								} while((i<1) || (i>size));
								if(!input) {
									message = 22;
									break;
								}
								message = 29;
								case8++;
								break;
							}
						}
						break;
					}
			case 9: { // RESIZE
				printf("\nChoose the new size of the Array\n");
				do {
					printf("Previous: [%d]. New: ", size);
					if(!(input=scan_int(&x))) break;
				} while(x<1);
				if(!input) {
					message = 22;
					break;
				}
				B = realloc(B, x * sizeof(int));
				if(B==NULL) {
					message = 40;
					break;
				}
				else A = B;
				y = size; // previous size
				size = x; // new size
				if(!case5) {
					message = 41;
					break;
				}
				else if(size>y){
					printf("Initialize all extra cells with a value\n");
					if(pool==1) { // (F)
						printf("Pool (F) [%d, %d]: ", start, end);
						if(!(input=scan_int(&x))) x=start;
						poolSet(&start, &end, start, x, 1);
					}
					else if(pool==2) { // (R)
						do {
							printf("Pool (R) [%d, %d]: ", start, end);
							if(!(input=scan_int(&x))) x=start;
						} while((x<start)||(x>end));
					}
					for(i=y; i<size; A[i++]=x);
					message = 42;
				}
				else message = 41;
				case9++;
				break;
			}
			case 10: { // SETTINGS
				do {
					printf(":-----{Settings}-----:\n| 0. Back            |\n| 1. Device          |\n:--------------------:\n");
					printf("> "); // 22 chars menu line length
					scanf("%hd", &option10);
				}
				while((option10<0)||(option10>1));
				switch(option10) {
					case 0: { // back
						message = 3;
						break;
					}
					case 1: { // device
						printf(":--------{Device}--------:\n| 1. Default window [PC] |\n| 2. Full Screen [PC]    |\n| 3. Mobile Portrait     |\n| 4. Mobile Landscape    |\n:------------------------:\n");
						printf("> "); // 26 chars menu line length
						input = scan_int(&x);
						if((x<2) || (x>4) || !input) {
							device = 1;
							message = 44;
						}
						else if(x==2) {
							device = 2;
							message = 45;
						}
						else if(x==3) {
							device = 3;
							message = 46;
						}
						else if(x==4) {
							device = 4;
							message = 47;
						}
						case10++;
						break;
					}
					case 2: { // data type
						
						break;
					}
					case 3: { // setting III
						
						break;
					}
				}
				break;
			}
			default: { // DEFAULT
				message = 3;
				break;
			}
		}
	} while(option);
	free(B);
	printf("\nmade by ncrusador\n~ Goodbye ~\n\n");
	system("pause\n");
	return 0;
}
////
void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return;
}
////
void sortInc(int* Array, int size) {
	int i, j;
	for(i=0;i<size;i++) {
		for(j=i;j<size;j++) {
			if(Array[i]>Array[j]) {
				swap(&Array[i],&Array[j]);
			}
		}
	}
	return;
}
////
void sortDec(int* Array, int size) {
	int i, j;
	for(i=0;i<size;i++) {
		for(j=i;j<size;j++) {
			if(Array[i]<Array[j]) {
				swap(&Array[i],&Array[j]);
			}
		}
	}
	return;
}
////
void sortRan(int* Array, int size) {
	int i, x, left_over, number1, number2;
	number1 = number2 = 0;
	for(i=0;i<size;i++) {
		if(size>RAND_MAX) {
			number1 = rand_int(0, size-1);
			number2 = rand_int(0, size-1);
		}
		else {
			number1 = rand()%size;
			number2 = rand()%size;
		}
		swap(&Array[number2],&Array[number1]);
	}
	return;
}
////
void sortSym(int* Array, int size) {
	int i, j, found;
	found=0;
	for(i=0; i<size-found; i++) {
		for(j=found; j<size-found; j++) {
			if(i==j) continue;
			if(Array[i]==Array[j]) {
				swap(&Array[i], &Array[found]);
				swap(&Array[j], &Array[size-1-found]);
				found++;
				break;
			}
		}
	}
	return;
}
////
void printOpt(int* Array, int size, int format, int format_input) {
	int i, columns;
	char digits;
	
	digits = calcDig(findMin(Array, size), findMax(Array, size));
	if(format==1) { // automatic
		for(i=1; (i*i<=size) && (i*(digits+1)<=format_input); i++);
		columns = i-1;
	}
	else if(format==2) { // columns
		columns = format_input;
	}
	else if(format==3) { // max line
		for(i=1; i*(digits+1)<=format_input; i++);
		columns = i-1;
	}
	
	printf("\n\n");
	for(i=0; i<size; i++) {
		if(i%columns==0) printf("\n");
		if(digits==1) printf(" %d", Array[i]);
		else if(digits==2) printf(" %2d", Array[i]);
		else if(digits==3) printf(" %3d", Array[i]);
		else if(digits==4) printf(" %4d", Array[i]);
		else if(digits==5) printf(" %5d", Array[i]);
		else if(digits==6) printf(" %6d", Array[i]);
		else if(digits==7) printf(" %7d", Array[i]);
		else if(digits==8) printf(" %8d", Array[i]);
		else if(digits==9) printf(" %9d", Array[i]);
		else if(digits==10) printf(" %10d", Array[i]);
		else printf(" %11d", Array[i]);
	}
	printf("\n\n");
	return;
}
//// symmetry percentage
float findSym(int* Array, int size) {
	int i, count;
	if(size==1) return 100;
	count=0;
	for(i=0; i<size/2; i++) {
		if(Array[i]==Array[size-1-i]) {
			count++;
		}
	}
	return ((count+0.0)/(size/2))*100;
}
//// finds the most popular value (complexity: size^2)
int findPop(int* Array, int size, int* maxCount) {
	int i, j, popular, count;
	popular = Array[0];
	*maxCount = 1;
	for (i=0; i<size; i++) {
		count = 1;
		for(j=0; j<size; j++) {
			if((Array[i]==Array[j]) && (i!=j)) {
				count++;
			}
		}
		if(count>*maxCount) {
			popular = Array[i];
			*maxCount = count;
		}
	}
	return popular;
}
//// finds the amount of unique values within given pool (complexity: size*pool).
int findDif(int* Array, int size, int start, int end) {
	int different, i, value;
	different = 0;
	for(value=start; value<=end; value++) {
		for(i=0; i<size; i++) {
			if(value==Array[i]) {
				different++;
				break;
			}
		}
	}
	return different;
}
////
int findMax(int* Array, int size) {
	int max, i;
	max=Array[0];
	for(i=1; i<size; i++) {
		if(Array[i]>max) {
			max = Array[i];
		}
	}
	return max;
}
////
int findMin(int* Array, int size) {
	int min, i;
	min=Array[0];
	for(i=1; i<size; i++) {
		if(Array[i]<min) {
			min = Array[i];
		}
	}
	return min;
}
////
int search(int* Array, int size, int value) {
	int count, i;
	count = 0;
	for(i=0; i<size; i++) {
		if(Array[i]==value) {
			count++;
		}
	}
	return count;
}
//// calculate max amount of digits given 2 numbers.
int calcDig(int number1, int number2) {
	int x, i, j;
	i = j = 0; // counting digits
	
	x = number1;
	if(x<0) { // if negative +1 digit
		i++;
		x *= -1; // turn it to positive
	}
	do {
		x /= 10;
		i++;
	} while(x);
	x = number2;
	if(x<0) {
		j++;
		x *= -1;
	}
	do {
		x /= 10;
		j++;
	} while(x);
	
	if(!i&&!j) return -1;
	else if(i>j) return i;
	else return j;
}
////
int findSum(int* Array, int size) {
	int i, sum;
	sum = 0;
	for(i=0; i<size; i++) {
		sum += Array[i];
	}
	return sum;
}
////
int sq_rt(int x) {
	int i;
	for(i=1; i*i<=x; i++);
	return i-1;
}
////
void poolSet(int* start, int* end, int new_start, int new_end, int format) {
	if(new_start > new_end) swap(&new_start, &new_end);
	if(*start > *end) swap(start, end);
	
	if(format==1) { // flexible pool
		if(new_start < *start) *start = new_start;
		if(*end < new_end) *end = new_end;
	}
	else if(format==2) { // restricted pool
		*start = new_start;
		*end = new_end;
	}
	return;
}
//// scans an integer within any type of inputs, if wrong scan again. Can be EOF'd by eof shortcut or typing \ twice. Returns amount of digits.
int scan_int(int* sum) {
	char ch, negative, error, valid_digit, eof, spacebars;
	int i;
	*sum = 0;
	negative = error = eof = valid_digit = spacebars = 0; // flags
	
	for(i=1; (ch=getchar())!='\n'; i++) {
		if(!error) {
			if((ch>='0') && (ch<='9')) {
				*sum *= 10;
				*sum += ch-'0';
				valid_digit++;
			}
			else if((i==1) && (ch=='-')) negative = 1; // if the first character indicates negative number
			else if((i==1) && (ch=='+')); // if the first character indicates positive number
			else if((!valid_digit) && (ch==' ')) spacebars = 1; // if characters are empty spaces without having typed numbers yet.
			else if(ch=='\\') eof++;
			else if(ch==EOF) eof=2;
			else error=1;
		}
	}
	if(spacebars && !valid_digit) error=1; // if empty spaces, but 0 given numbers
	if(negative && !valid_digit) error=1; // if negative sign, but 0 given numbers
	
	if(eof>1) return 0;
	else if(eof) error=1;
	if(((ch=='\n') && (i==1)) || error) return scan_int(sum); // if wrong input or empty input, try again.
	else {
		if(negative) *sum *= -1;
		return calcDig(*sum, 0); // return the amount of digits the scanned number has (including signed).
	}
}
//// random number generator for pool greater than RAND_MAX.
int rand_int(int start, int end) {
	int i, pool;
	long long sum;
	
	if(start>end) swap(&start, &end);
	pool = end-start+1;
	sum = 0;
	for(i=1; i<=12; i++) { // create a huge random 12-digit number (>int)
		sum *= 10;
		sum += rand()%10;
	}
	return sum%pool + start;
}
//// find most consecutive sequence of repeating values.
int findCon(int* Array, int size, int* maxCount) {
	int i, count, popular;
	
	*maxCount = 1;
	popular = Array[0];
	if(size==1) return popular;
	count = 1;
	for(i=0; i<size-1; i++){
		if(Array[i]==Array[i+1]) {
			count++;
			if(count>*maxCount) {
				*maxCount = count;
				popular = Array[i];
			}
		}
		else count = 1;
	}
	return popular;
}
////
void printPyr(int* Array, int size, int max_line_length) {
	int i, extra_values, columns, max_columns, count;
	char flag, digits;
	
	digits = calcDig(findMin(Array, size), findMax(Array, size));
	for(i=1; (i*i<=size) && (i*(digits+1)<=max_line_length); i++);
	max_columns = --i;
	columns = 1;
	count = 0;
	extra_values = size - max_columns*max_columns; // extra values if size is not a perfect square. 
	flag = 0;
	
	printf("\n\n");
	for(i=0; i<size; i++, count++) {
		if(count==columns) {
			count = 0;
			if(!flag) columns++; // going up
			else { // going down or staying on same lvl
				if(extra_values>=columns) {
					extra_values -= columns;
					columns++;
				}
				columns--;
			}
			printf("\n");
		}
		if((columns==max_columns) && !flag) flag=1;
		
		if(digits==1) printf(" %d", Array[i]);
		else if(digits==2) printf(" %2d", Array[i]);
		else if(digits==3) printf(" %3d", Array[i]);
		else if(digits==4) printf(" %4d", Array[i]);
		else if(digits==5) printf(" %5d", Array[i]);
		else if(digits==6) printf(" %6d", Array[i]);
		else if(digits==7) printf(" %7d", Array[i]);
		else if(digits==8) printf(" %8d", Array[i]);
		else if(digits==9) printf(" %9d", Array[i]);
		else if(digits==10) printf(" %10d", Array[i]);
		else printf(" %11d", Array[i]);
	}
	printf("\n\n");
	return;
}
////
void printVal(int* Array, int size, int shown_value, int max_line_length) {
	int i, columns;
	char count, digits;
	
	digits = calcDig(findMin(Array, size), findMax(Array, size));
	for(i=1; (i*i<=size) && (i*(digits+1)<=max_line_length); i++);
	columns = i-1;
	
	printf("\n\n");
	for(i=0; i<size; i++) {
		if(i%columns==0) printf("\n");
		if(Array[i]!=shown_value) {
			for(count=0; count++<digits; printf(" "));
			printf("-");
			continue;
		}
		
		if(digits==1) printf(" %d", Array[i]);
		else if(digits==2) printf(" %2d", Array[i]);
		else if(digits==3) printf(" %3d", Array[i]);
		else if(digits==4) printf(" %4d", Array[i]);
		else if(digits==5) printf(" %5d", Array[i]);
		else if(digits==6) printf(" %6d", Array[i]);
		else if(digits==7) printf(" %7d", Array[i]);
		else if(digits==8) printf(" %8d", Array[i]);
		else if(digits==9) printf(" %9d", Array[i]);
		else if(digits==10) printf(" %10d", Array[i]);
		else printf(" %11d", Array[i]);
	}
	printf("\n\n");
	return;
}
////

////

////

////

////

////