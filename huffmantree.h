#ifndef _HUFFMANTREE_H
#define _HUFFMANTREE_H
#define NB_CHARS 256
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
typedef struct byte_occur_t byte_occur_t;
typedef struct node_t node_t;
typedef struct code_t code_t;
struct byte_occur_t {
  int byte,occur;
  struct node_t * node;
};
  struct node_t{
    int byte,occur;
    struct node_t * a0, * a1;
  };
struct code_t{
  unsigned long code;
  int length;
};
int header[NB_CHARS];
byte_occur_t byte_occur[NB_CHARS];
node_t * huffmanTree(void);
void printHuffmanTree(node_t * n);
void ht_compress(char * filename);
void histo(char * filename);
void ht_decompress(char * filename);
void histo1(char * filename);
char *  lecture();
int comparI(const void* p0, const void* p1);
int comparC(const void* p0, const void* p1);
void isort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
#endif
