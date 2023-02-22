/* 304 sec linux MAXEXP=8 */
#include <stdio.h>
#include <stdlib.h>
#define MAXEMP 7

int main() {
	//
	system("pause");
	unsigned n, x, k, factor, end, extra_factors, unique_factors, ET_artios, ET_perittos, ZP, sum, deficient, abundant, print, count;
	short mertens;
	//
	end=10;
	for(k=2;k<=MAXEMP;k++) {
		end*=10;
	}
	//
	printf("\n");
	mertens=0;
	ZP=0;
	k=10;
	print=0;
	count=0;
	for(n=1;n<=end+9;n++) {
		if(n>=k-9 && n<=k+9) {
			print=1;
			count++;
		}
		else {
			print=0;
		}
		x=n;
		extra_factors=0;
		unique_factors=0;
		ET_artios=0;
		ET_perittos=0;
		
		if(x%4==0 || x%9==0 || x%25==0 || x%49==0) {
			if(print) {
				printf("M(%u) = %hd\n",n,mertens);
				if(count==19) {
					count=0;
					k*=10;
					printf("........\n");
				}
			}
			if(mertens==0) ZP++;
			extra_factors++;
			continue;
		}
		if(x%2==0) {
			x/=2;
			unique_factors++;
		}
		if(x%3==0) {
			x/=3;
			unique_factors++;
		}
		if(x%5==0) {
			x/=5;
			unique_factors++;
		}
		if(x%7==0) {
			x/=7;
			unique_factors++;
		}
		
		for(factor=11;factor*factor<=x;factor+=6) {
			if(x%factor==0) {
				x/=factor;
				if(x%factor==0) {
					extra_factors++;
					break;
				}
				unique_factors++;
			}
			if(x%(factor+2)==0) {
				x/=(factor+2);
				if(x%(factor+2)==0) {
					extra_factors++;
					break;
				}
				unique_factors++;
			}
		}
		if(x!=1 && !extra_factors) {
			unique_factors++;
		}
		if(extra_factors==0) {
			if(unique_factors%2==0) {
				mertens++;
				ET_artios++;
			}
			else {
				mertens--;
				ET_perittos++;
			}
		}
		if(mertens==0) ZP++;
		if(print) {
			printf("M(%u) = %hd\n",n,mertens);
			if(count==19) {
				count=0;
				k*=10;
				printf(".........\n");
			}
		}
	}
	printf("\nFound %u zero points of the Mertens function\n",ZP);
	//
	deficient=0;
	abundant=0;
	printf("\nChecking numbers in the range [%u,%u]\n\n",2,1000*ZP);
	for(n=2;n<=1000*ZP;n++) {
		sum=1;
		k=0;
		if(n%2==0) { //artioi
			for(factor=2;factor*factor<n;factor++) {
				if(n%factor==0) {
					sum+=factor+(n/factor);
				}
				if(sum>n) break;
			}
		}
		else { //perittoi
			if(n%3!=0) {
				for(factor=5;factor*factor<n;factor+=6) {
					if(n%factor==0) {
						sum+=factor+(n/factor);
					}
					if(n%(factor+2)==0) {
						sum+=(factor+2)+(n/(factor+2));
					}
					if(sum>n) break;
				}
			}
			else {
				for(factor=3;factor*factor<n;factor+=2) {
					if(n%factor==0) {
						sum+=factor+(n/factor);
					}
					if(sum>n) break;
				}
			}
		}
		if(factor*factor==n) sum+=factor;
		if((factor+2)*(factor+2)==n) sum+=factor+2;
		//
		if(sum==n) {
			printf("Found perfect number: %u\n",n);
		}
		else if(sum<n) {
			deficient++;
		}
		else {
			abundant++;
		}
	}
	printf("\nFound %u deficient numbers",deficient);
	printf("\nFound %u abundant numbers",abundant);
	//
	printf("\n\n");
	system("pause");
	return 0;
	//
}