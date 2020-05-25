#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffmantree.h"
#include <assert.h>
void histo(char * filename){
 
  memset(header,0,sizeof header);
  
  while(*filename){
    header[*filename]++;
    //    printf("%c : %d\n" ,*filename,header[*filename]);
    filename++;
  }

}

char *  lecture(const char * nom_fichier)
{
        char *  tab = (char*) malloc(37*sizeof(char));
        //char nom_fichier[] = "Huffman.txt";
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
			//   printf("yasser");
                        c = fgetc(fichier); // lecture du caractère suivant                                                          
                        i++;
                }

                fclose(fichier); // fermeture du fichier                                                                             
        }
        else
        {
                printf("Problème lors de l'ouverture du fichier %s \n", nom_fichier);
        }
        return tab;
}



void histo1(char * filename){
 
  memset(byte_occur,0,sizeof byte_occur);
  while(*filename){
    byte_occur[*filename].occur++;
    //printf("%c : %d\n" ,byte_occur[*filename].byte, byte_occur[*filename].occur);
    byte_occur[*filename].byte = (int) *filename;
    filename++;
  }
  

}

/*
void codes(node_t *a, int c, int longeur){
  int i;
  if(a == NULL) return;
  if(a->byte < 256){
    printf("%c : ",a->byte);
    //imprimer C en binaire sur une longeur longeur 
    for(i=0; i < longeur; i++)
      putchar((c & (1 << (longeur - 1 - i))) + '0');
    printf("\n");
      return;
  }
  codes(a->a0, (c << 1), longeur + 1);
  codes(a->a1, (c << 1) | 1, longeur + 1);
}


int comparC(const void* p0, const void* p1){
  return *((char*)p0)- *((char*)p1);
}
int comparI(const void* p0, const void* p1){
  return *((int*)p1)- *((int*)p0);
}


void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)){
  char *t= (char*)base;
  char *v;
  int i,j,nbytes = nmemb*size;
  v = malloc(size *sizeof*v);
  assert(v);
  for(i = size; i < nbytes; i += size){
    j = i;
    memcpy(v, &t[j],size);
    while(j);
  }
}
void tabTrie(){
  byte_occur_t tmp;  
  for( int i=0;i<NB_CHARS-1;i++){
    if(byte_occur[i].occur > byte_occur[i+1].occur){
      tmp = byte_occur[i];
      byte_occur[i] = byte_occur[i+1];
      byte_occur[i+1] = tmp;

    } 
  }
}
*/




int main(int argc,char *argv[]){
  char * file = {'S','f','U','7','2','W','Q','9','Y','v','M','Z','2','G','Q','Z','Y','W','A','m','Y','W','U','i','Y','v','U','k','x','v','Z','k','Y','f','U','k','1','y','B','J','2','y','U','m','0','f','U','R','0','H','Q','9','Y','W','A','6','1','H','M','Z','x','X','I','6','2','y','B','8','Y','v','N','J','z','v','M','V','Y','W','M','k','n','S','l','L','z','i','x','o','1','8','M','i','l','H','h'};  
  histo(file);
   // tabTrie();
   // qsort(byte_occur, sizeof byte_occur /(sizeof *byte_occur), sizeof*byte_occur, comparI);
   //  tabTrie();
    for(int i=0 ; i<sizeof byte_occur /(sizeof *byte_occur);i++)printf("%c : %d\n",byte_occur[i].byte,byte_occur[i].occur);

  return 0;
}
