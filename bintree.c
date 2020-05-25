#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include "huffmantree.h"
typedef struct node_t node_t;
typedef struct list list;

struct node_t{
    int byte,occur;
    struct node_t * gauche, * droite;
  };
struct list{
  int byte;
  struct list * next;
};


void ltAdd(list **l , int byte){
  while(*l){
    (*l)= (*l)->next;
  }
  (*l) = malloc(sizeof (**l));
  assert(*l);
  (*l)->next = NULL;
  (*l)->byte = byte;

}

void RegleInfallible(char * texte){
  list **l;
  //  l = malloc(sizeof(*l));
  int i = 1;
  while(*texte){
    
    ltAdd(l,*texte);
    printf("allo");
    i++;
    printf("allo1");
    if(i%3 == 0){
      printf("%d %d %d",(*l)->byte,(*l)->next->byte,(*l)->next->next->byte);
    }
  }

}

node_t  byte_occur[256];
//byte_occur = malloc(sizeof (*byte_occur));
void histo1(char * filename){

  memset(byte_occur,0,sizeof byte_occur);
  while(*filename){
    
    byte_occur[*filename].occur++;
    byte_occur[*filename].byte = (int) *filename;
    filename++;
  }


}

int count_element(node_t * arbre)
{
  if(arbre == NULL) return 0;
  return (count_element(arbre->droite)+count_element(arbre->gauche)+1);
}

void btPrint(node_t * n){
  //int v ;
  if(n==NULL)
    return;
  btPrint(n->droite);
  printf("\n%c : %d\n",n->byte,n->occur);
  btPrint(n->gauche);
  
}
node_t tab[256];
int i = 0;

void btAdd(node_t ** p,int o,int l){
 
  while(*p){
    if((*p)->occur > o) p = &((*p)->gauche);
    else p = &((*p)->droite );
  }
  *p = malloc ( 1*sizeof **p);
  assert(*p);
  (*p)->droite = (*p)->gauche = NULL;
  (*p)->occur=o;
  (*p)->byte=l;
  
}


void btFree(node_t ** p){
  if(*p){
    btFree(&((*p)->gauche));
    btFree(&((*p)->droite));
    free(*p);
  }  
  *p = NULL;
  
}


int main(int argc,char *argv[]){
  node_t **a= NULL ;
  node_t ** h= NULL;
  RegleInfallible(argv[1]);
  /*  histo1(argv[1]);
   int i;

  for(i=0;i<256;i++){
    btAdd(&a,byte_occur[i].occur,byte_occur[i].byte);
    } 
  btPrint(a);
  btFree(a);
  */
  return 0;
}
