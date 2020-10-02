#include <stdio.h>
#include <stdlib.h>
#define grandezza 30

float contagio( float contagiati, float num, float contgiorn[]);


int main()
{
 float R;
 float N;
 float contgiorn[grandezza];

 printf("inserisci il valore di contagio\n");
 scanf("%f", &R);
 printf("inserire il numero di studenti da contagiare\n");
 scanf("%f", &N);
 contagio(R, N, contgiorn[]);
 return 0;
}

float contagio( float contagiati, float num, float contgiorn[])
{
  int cont;
  for (int i=0; i<num; i++){
    contgiorn[i]= contagiati * num;
    cont=cont+1;
    printf("al giorno %d  ci sono stati %f", &cont contgiorn[i]);
  }


return cont;
}
