#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void lecture(char *tab)
{
	tab = (char*) malloc(37*sizeof(char));
	char nom_fichier[] = "Huffman.txt";
	FILE* fichier = fopen(nom_fichier,"r"); // ouverture en lecture (Read)
	if( fichier != NULL )
	{
		char c = fgetc(fichier); // lecture du 1er caractère dans fichier, 
           // puis fgetc se positionne sur le caractère suivant (pour la proichaine lecture)
		int i= 0;
		while( c != EOF )   // tant que le caractère lu n'est pas la fin de fichier (End Of File)
		{
			printf("%c", c);
			tab[i] = c;
			printf("yasser");
			c = fgetc(fichier); // lecture du caractère suivant
			i++;
		}
		
		fclose(fichier); // fermeture du fichier
	}
	else
	{
		printf("Problème lors de l'ouverture du fichier %s \n", nom_fichier);
	}
//	return tab;
}

typedef struct node_t node_t;
struct node_t{
  int   v;
  struct node_t * gauche,* droite;
};



void btPrint(node_t * n){
  if(n==NULL)
    return;
  btPrint(n->gauche);
  printf("%d\n",n->v);
  btPrint(n->droite);
}

void btFree(node_t ** p){
  if(*p){
    btFree(&((*p)->gauche));
    btFree(&((*p)->droite));
    free(*p);
  }  
  *p = NULL;
  
}

void btAdd1(node_t ** p,int v){
  while(*p){
    if((*p)->v > v) p = &((*p)->gauche);
    else p = &((*p)->droite );
  }
  *p = malloc ( 1*sizeof **p);
  assert(*p);
  (*p)->droite = (*p)->gauche = NULL;
  (*p)->v=v;
}
/*
int trans(node_t * n){
	int tab;
//tab = (int*) malloc(14*sizeof(int));

 if(n==NULL)return 2;
	//while()
  trans(n->gauche);
   tab= n->v ;
  trans(n->droite);
 return tab;
 
}
*/
void histogramme(char* fichier)
{
    int liste[256];
    memset(liste, 0, sizeof(liste));
    while(*fichier)
    {
        liste[*fichier]++;
        printf("%c : %d\n", *fichier, liste[*fichier]);
        fichier++;
    }
}
int main(void){
  node_t **a= NULL ;
  int t[] = {6,3,5,8,7,4,0,1,2};
  char * tab = NULL;
  /*
  int i;
  // printf("alo");
  for(i=0;i<9;i++){
    // printf("alo");
    btAdd1(&a,t[i]);
  
    //btPrint(a);
  }  //btFree(a);
  
  for(i=0;i<9;i++){
	
	a = &(*a)->gauche ;
	tab[i]=trans(a);
	a = &(*a)->droite ;
	
	
	
  }
	for(i=0;i<9;i++){
	printf("%d\n",tab[i]);
	}
	*/
	lecture(tab);
	histogramme(tab);
		//btFree(a);
  return 0;
}