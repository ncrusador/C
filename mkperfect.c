// mkperfect.c

#include <stdio.h>
#define MAXM 6
#define MAXNUM 400000


int main() {

unsigned long sum, b, i; 
unsigned int m, j, k, amount=0, appear=0, S1=0, S2=0, S3=0, P; /* amount to plithos twn perfect ari8mwn, appear oles oi emfaniseis sunolika kai S1, S2, S3 ta antistoixa athroismata twn multiperfect/perfect/superperfect arithmwn. */ 


for (i=2; i<= MAXNUM; i++) {
    P=1;      /* to P enas deiktis me ton opoio tha kserw oti exw pros8esei ton i sto plithos amount MONO mia fora. Ousiastika xrhsimopoiw tin P ws logiki metavliti, apla anti gia True/False exw 1/0. */
    sum=i;   /* arxikopoiw sto sum ton idio ton arithmo i pou elenxw, agou kathe arthmos exei diaireth ton idio tou ton eauto (Den ton pros8etw parakatw stin while). */
   for(m=1;m<=MAXM;m++) {
     b=sum;    /* to b einai to neo athroisma pou prokuptei kathe fora.*/
     sum++;    /* prosthetw episis kai to 1 afou apotelei diaireth kathe arithmou (Den ton prosthetw stin while).*/
     j=2;     /* j oi upopsifioi diairetes. */
     while (j*j<=b) {    /* h while kathws kai ta 2 akolouthoumena emfwleumena if apoteloun ton algorithmo euresis tou athroismatos sum twn diairetwn j enos arithmou b. */
        if(b%j==0) {
         sum+=j;
         if((b/j)!=j) sum+=b/j;
         }
        j++;
     }
     if (sum%i==0) {
        if(P) {
          P=0;   /* metatrepw thn P se 0 wste na min ksanaproste8ei o idios arithmos sto plithos amount.*/
          amount++;
        }
        appear++;
        k=sum/i;
        if (m==1 && k==2) {
         printf("%ld is a (1 - 2) - perfect especially perfect number\n", i, k);
         S2++;
        }
        else if (m==1) {
          printf("%ld is a (1 - %ld) - perfect especially multiperfect number\n", i);
          S1++;
        }
        
        else if (m==2 && k==2) {
         printf("%ld is a (2 - 2) - perfect especially superperfect number\n", i);
         S3++;
        }
        else printf("%ld is a (%ld - %ld) - perfect number\n", i, m, k);   
     } 
    
   }
   
}
double rate=((double)amount*100.0)/(double)MAXNUM; // pososto.

printf("Found %ld distinct (m-k)-perfect numbers (%5.4f%% of %ld) in %ld occurrences\n", amount, rate, MAXNUM, appear);
printf("Found:\n%ld perfect numbers\n%ld multiperfect (including perfect numbers)\n%ld superperfect numbers\n\n", S2, S1+S2, S3);

}
