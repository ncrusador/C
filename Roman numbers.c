#include <stdio.h>
#include <stdlib.h>

int main(void){

	unsigned short sum, i;
	char ch, length, prev, error, repI, repV, repX, repL, repC, repD, repM, roman, decimal;
    
	ch='\n';
	printf("------------------------\n");
	printf(" Roman Number Converter\n");
	printf("------------------------\n");
	i=1;
	do {
		printf("\n(%hu) Give number: ",i);
		sum=0;
		length=0;
		error=0;
		repI=repV=repX=repL=repC=repD=repM=0;
		prev='\0';
		roman=decimal=0;
		while(((ch=getchar())!='\n')&&(length<=15)&&(ch!=EOF)) {
			length++;
			switch(ch) {	
				case 'i': {
					ch-='a'-'A';
				}
				case 'I': {
					roman=1;
					repI++;
					if(repI>3) { // IIII
						error=1;
						break;
					}
					if(prev=='I') {
						repV=repX=repL=repC=repD=repM=99; // IIV, IIX, IIL, IIC, IID, IIM
					}
					sum++;
					break;
				}
				case 'v': {
					ch-='a'-'A';
				}
				case 'V': {
					roman=1;
					repV++;
					if(repV>1) { // VV
						error=1;
						break;
					}
					if(prev=='I'){
						sum-=2;
						repI=repV=repX=repL=repC=repD=repM=99; // IVI, IVV, IVX, IVL, IVC, IVD, IVM
					}
					sum+=5;
					break;
				}
				case 'x': {
					ch-='a'-'A';
				}
				case 'X': {
					roman=1;
					repX++;
					if((repX>3)&&(prev!='I')) { // XXXVX
						error=1;
						break;
					}
					if(repV) { // VX
						error=1;
						break;
					}
					if((repX>1)&&repC&&(prev=='C')) { // XCX, XCCX, 
						error=1;
						break;
					}
					if(prev=='I') {	
						sum-=2;
						repI=repV=repX=repL=repC=repD=repM=99; // IXI, IXV, IXX, IXL, IXC, IXD, IXM
					}
					else if(prev=='X') {
						repL=repC=repD=repM=99; // XXL, XXC, XXD, XXM
					}
					sum+=10;
					break;
				}
				case 'l': {
					ch-='a'-'A';
				}
				case 'L': {
					roman=1;
					repL++;
					if(repI||repV||(repL>1)) { // IL, VL, LL
						error=1;
						break;
					}
					if(prev=='X') { // XL
						sum-=20;
						repX=repL=repC=repD=repM=99; // XLX, XLL, XLC, XLD, XLM
					}
					sum+=50;
					break;
				}
				case 'c': {
					ch-='a'-'A';
				}
				case 'C': {
					roman=1;
					repC++;
					if((repC>3)&&(prev!='X')) { // CCCVC
						error=1;
						break;
					}
					if(repI||repV||repL) { // IC, VC, LC
						error=1;
						break;
					}
					if(repM&&(repC>1)&&(prev=='M')) { // CMC
						error=1;
						break;
					}
					if(prev=='X') {
						sum-=20;
						repL=repC=repD=repM=99; // XCL, XCC, XCD, XCM
					}
					sum+=100;
					break;
				}
				case 'd': {
					ch-='a'-'A';
				}
				case 'D': {
					roman=1;
					repD++;
					if(repI||repV||repX||repL||(repD>1)) { // ID, VD, XD, LD, DD
						error=1;
						break;
					}
					if(prev=='C') {
						sum-=200;
						repC=repD=repM=99; // CDC, CDD, CDM
					}
					sum+=500;
					break;
				}
				case 'm': {
					ch-='a'-'A';
				}
				case 'M': {
					roman=1;
					repM++;
					if(repI||repV||repX||(repC>1)||repL||repD||(repM>4)) { // IM, VM, XM, CCM, LM, DM, MMMCMM
						error=1;
						break;
					}
					else if((repM==4) && (prev=='M')) { // MMMM
						error=1;
						break;
					}
					if(prev=='C') {
						sum-=200;
						repD=repM=99; // CMM, CMD
					}
					sum+=1000;
					break;
				}
				default: {
					if((ch>='0')&&(ch<='9')&&(!roman)) {
						decimal++;
						sum*=10;
						sum+=ch-'0';
					}
					else {
						error=1;
					}
					break;
				}
			} // telos switch
			prev=ch;
			if(length==1) {
				printf("> ");
			}
			putchar(ch);
			if(decimal&&roman) {
				error=1;
			}
			if((decimal>4)||(sum>3999)) {
				error=1;
			}
		} // telos while
		if(ch!=EOF) {
			if(error) {	
    			printf(" is invalid.\n");
			}
			else {
				if(roman) {
					printf(" = %hu\n",sum);
				}
				else if(decimal) {
					// ...
					printf(" = %hu\n",sum);
				}
			}
		}
		else {
			printf("\nGoodbye!\n");
		}
		i++;
	} while(ch!=EOF); 
	
	system("pause");
	return 0;
}