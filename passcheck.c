/* passcheck.c */

#include <stdio.h>
#include <ctype.h>
#define MINLENGTH 9
#define MINCRITERIA 3

int main (void) {
    
    int length, vk1, ch=getchar(), line=0, k, mc, sup, low, dig, pun, c5, c6, x, y, w, z, error1, error2;
    int pc; /* Previous Char, einai o prohgoumenos 'xaraktiras' gia ta xalara kritiria 5 kai 6 */
   
   while (ch!=EOF) {
     line++;
     vk1=0;  /* vk1 = Vasiko Kritirio 1 */
     length=0;
     mc=0;  /* mini criteria (o arithmos twn xalarwm kritiriwn pou ikanopoiountai apo to ekastote password) */
     sup=0, low=0, dig=0, pun=0;
     x=0, y=0;  /* oi metavlites ws endeiksi oti: (x)- entopistikan 2 idioi sinexomenoi 'xaraktires' me diaforetiko 3o, (y)- entopistike akolou8ia 3 sinexomenwn 'xaraktirwn' me diaforetiko ton 4o */
     w=0, z=0;  /* ta w kai z einai oi prohgoumenes times twn x kai y antistoixa */
     printf("Line %d: Password \"",line);
     error1=1, error2=1;
     for (;;) {
          if (ch=='\n') break;
          length++;
          k=(ispunct(ch)!=0) || (isupper(ch)!=0) || (islower(ch)!=0) || (isdigit(ch)!=0);
          /* to k einai kata poso to ch pou diavastike einai mesa stous apodektous 'xaraktires' */
          if (k) vk1++; /* ama to ch ikanopoiei to prwto vasiko kritirio */
          if (isupper(ch)) sup++;
          if (islower(ch)) low++;
          if (isdigit(ch)) dig++;
          if (ispunct(ch)) pun++;
          if (error1) {  /* an estw mia fora vre8ei apomwnomeno zevgos idiwn 'xaraktirwn' tote to xalaro kritirio 5 den isxuei */
             if ((length>1) && (ch==pc)) {
               x++;
               w=x;
             }
             else if (w!=1) x=0;
             else if (w==1) error1=0;
          }
          if(error2) {  /* an estw mia fora vre8ei apomwnomeno motivo 'xaraktirwn' se auksousa seira tote to xalaro kritirio 6 den isxuei */
            if ((length>1) && (ch-pc==1)) {
              y++;
              z=y;
            }
            else if (z!=2) y=0;
            else if (z==2) error2=0;
          }
          pc=ch;  /* apo8ikeuse stin pc ton 'xaraktira' ch wste stin epomenh epanalipsi na mporw na elegxw to ekastote ch me to prohgoumeno */
          putchar(ch);
          ch=getchar();
     }
     if (x==1) error1=0;  /* an h for teleiwse kai oi teleutaioi 2 einai idioi 'xaraktires' */
     if (y==2) error2=0;  /* an h for teleiwse kai oi teleutaioi 3 'xaraktires' einai se auksousa seira */
     if (error1) mc++;
     if (error2) mc++;
     if (sup) mc++;
     if (low) mc++;
     if (dig) mc++;
     if (pun) mc++;
     
     if (vk1 < length) printf("\" is invalid <unacceptable character>");
     else if (length < MINLENGTH) printf("\" is invalid <too short>");
     else if (mc < MINCRITERIA) printf("\" is invalid <few criteria>");
     else {
          printf("\" is valid ");
          if ((mc == 6) && (length >= MINLENGTH*2)) printf("<very strong>");
          else if ((mc == 6) && (length < MINLENGTH*2)) printf("<strong>");
          else if (mc == 5) printf("<fair>");
          else if ((sup+low) >= dig) printf("<weak>");
          else if ((sup+low) < dig) printf("<very weak>");
     }
     
     printf("\n");
     ch=getchar();
   }
}
