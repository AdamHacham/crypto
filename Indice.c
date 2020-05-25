#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>




int countFile(const char * file){
  char c ;
  
  int i = 0;
  FILE *f = NULL;
  if ((f = fopen(file,"r")) == NULL){
    printf("erreur fopen");
  }
  while ((c = fgetc(f)) != EOF){
    i++;  
    }
  //  i = i-1;
  //printf("%d\n",i);
  return i ;
  fclose(f);
}

void indice_coincidence (const char * file) {
  int val ;
  int var;
  int i = 0;
  int j = 0;
  int k = 0;
  int cmt =0;
  double kappa = 0;
  char p;
  char *c,*d;
  FILE *f;
  val = countFile(file); 
  printf("Nombre total de caractère : %d\n",val);
  var = val/2;
  //  printf("Nombre de caractère de la partition divisée par 2 : %d\n",var);
  if((f = fopen(file,"r+")) == NULL){
    printf("erreur file");
  }
  d = (char *)malloc( sizeof (char *));
  c = (char *)malloc( sizeof (char *));
  while ((p = fgetc(f)) != EOF){
    if (i > val/2){
      d[j] = p;
    }else{
    c[i] = p;
    }
    j++;
    i++;
  }
  fclose(f);
  while (k < val/2){
    if (c[k] == d[k]){ cmt++;
    }
    k++;
  }
  printf("Nombre de similitude :  %d\n", cmt);
  printf("Nombre de caractère de la partition divisée par 2 : %d\n",var);   
 
}
/*
double testKappa(int a,int b){
  double d = (double)a/b;
  return d;
}
*/
int main(int argc,char *argv[]){
  char * c = NULL;
  char * d = NULL;
  indice_coincidence(argv[1]);
  return 0;
}
