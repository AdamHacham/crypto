#include "pile.h"
#include <stdlib.h>
#include <assert.h>
/*!\brief indice indiquant le haut de la pile.*/
static int haut = -1;
/*!\brief tableau static utilise ́ pour le stockage de la pile.*/
static int pile[PILE_MAX];
/*!\brief Empiler la valeur \a v dans la pile.param v la valeur a` empiler */
void push(int v) {
  pile[++haut] = v;
}
/*!\brief de ́piler et renvoyer la valeur de l’e ́le ́ment en haut de la pile. return la valeur en haut de la pile.*/
int pop(void) {
  return pile[haut--];
}
/*!\brief Indique si la pile est vide.
return vrai si la pile est vide, faux sinon. */

int vide(void) {
  return haut < 0;
}
