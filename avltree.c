#define _GNU_SOURCE 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

#define ESQ -1
#define BAL 0
#define DIR 1

struct avl {
    int bal;
    char * cont;
    struct avl * dir;
    struct avl * esq;
};

/*AVL newAVL(){
    AVL *a = malloc(sizeof(struct avl));
    *a = NULL;
    return a;
}*/

void printAVL(AVL a){
	if(a){
		printAVL(a -> esq);
		printf("%s\n", a -> cont);
		printAVL(a -> dir);
	}
}

AVL rotateE(AVL a){
    AVL b = a -> dir;
    a -> dir = b -> esq;
    b -> esq = a;
    return b;
}

AVL rotateD(AVL a){
    AVL b = a -> esq;
    a -> esq = b -> dir;
    b -> dir = a;
    return b;
}

AVL fixE(AVL a){
    AVL b = a -> esq;
    AVL c = b -> dir;
    if(b -> bal == DIR){
        a -> bal = b -> bal = BAL;
        a = rotateD(a);
    }
    else if(b -> bal == BAL);
    else{
        switch (c -> bal) {
            case DIR: a -> bal = BAL;
                      b -> bal = ESQ;
                      break;
            case ESQ: a -> bal = DIR;
                      b -> bal = BAL;
                      break;
            case BAL: a -> bal = BAL;
                      b -> bal = BAL;
                      break;
        }
        c -> bal = BAL;
        a -> esq = rotateE(b);
        a = rotateD(a);
    }
    return a;
}

AVL fixD(AVL a){
    AVL b = a -> dir;
    AVL c = b -> esq;
    if(b -> bal == DIR){
        a -> bal = b -> bal = BAL;
        a = rotateE(a);
    }
    else if(b -> bal == BAL);
    else{
        switch (c -> bal) {
            case DIR: a -> bal = BAL;
                      b -> bal = DIR;
                      break;
            case ESQ: a -> bal = ESQ;
                      b -> bal = BAL;
                      break;
            case BAL: a -> bal = BAL;
                      b -> bal = BAL;
                      break;
        }
        c -> bal = BAL;
        a -> dir = rotateD(b);
        a = rotateE(a);
    }
    return a;
}

AVL insertAVLaux(AVL a, char * str, int *x){
    if(a == NULL){
        a = malloc(sizeof(struct avl));
        a -> bal = BAL;
        a -> cont = strdup(str);
        a -> dir = a -> esq = NULL;
        *x = 0;
    }
    else{
        if(strcmp(str, a -> cont) > 0){
            a-> dir = insertAVLaux(a -> dir, str, x);
            if(*x == 1){
                if(a -> bal == ESQ){
                    a -> bal = BAL;
                    *x = 0;
                }
                else if(a -> bal == BAL){
                    a -> bal = DIR;
                    *x = 1;
                }
                else{
                    fixD(a);
                    *x = 0;
                }
            }
        }
        else{
            a-> esq = insertAVLaux(a -> esq, str, x);
            if(*x == 1){
                if(a -> bal == DIR){
                    a -> bal = BAL;
                    *x = 0;
                }
                else if(a -> bal == BAL){
                    a -> bal = ESQ;
                    *x = 1;
                }
                else{
                    fixE(a);
                    *x = 0;
                }
            }
        }
    }
    return a;
}

void insertAVL(AVL *a, char * str){
    int x;
    * a = insertAVLaux(*a, str, &x);
}

int searchAVL(AVL a, char * str){
    int comp, r;

    if(a == NULL){
        return 0;
    }

    comp = strcmp(str, a -> cont);

    if(comp == 0) r = 1;
    else if(comp > 0) r = searchAVL(a -> dir, str);
    else r = searchAVL(a -> esq, str);

    return r;
}

int writeFile(AVL a, FILE *fp){
	int vWrite;

	vWrite = 0;
	if(a != NULL){
		vWrite += writeFile(a -> esq, fp);
		if(fwrite(a -> cont, 1, strlen(a -> cont), fp)){
			vWrite++;
			fwrite("\n", 1, 1, fp);
		}
		vWrite += writeFile(a -> dir, fp);
	}
	return vWrite;
}

/*void destroyAVL(AVL *a){
    if(a){
        destroyAVL(&((*a) -> esq));
        destroyAVL(&((*a) -> dir));
        free(a);
    }
}*/
