#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "pile.h"


int main(int argc,char *argv[]){
  char * texte = argv[1];
  char * c ;
  char * c1;
  int i = 0;
  int j = 0;
  int n = 3 ; 
  c = malloc(3 * sizeof (*c));
  c1 = malloc(3 * sizeof (*c1));
  while(*texte){
    if(i<n){
    c[i] = *texte ;
    push((int) c[i]);
    printf(" %c\n",c[i]);
     i++;
    texte++;
    continue;
    }
    if (j<3){
      c1[j] = *texte ;
      printf(" %c\n",c1[j]);
      j++;
      texte++;
      continue;
    }
    //    printf("%c\n%c\n%c\n",c1[0],c1[1],c1[2]);
   
    while(!vide()){
      char tmp = (char) pop();
      int v = 0 ;
      if ((c1[0] != tmp) && (c1[1] != tmp) && (c1[2] != tmp)){
	v = 1;
	continue;
	
      }else { v = 0 };

      if(v == 1){

	printf("%c\n",c[i]);

      }


    }
   
    break;
  }
  //printf("%c\n%c\n%c\n",c1[0],c1[1],c1[2]);
   return 0;
}
