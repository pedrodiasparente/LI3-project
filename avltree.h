#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct avl *AVL;

/*API
//Returns a new NULL AVL
//AVL newAVL();
//Prints AVL*/
void printAVL(AVL a);
/*Inserts a new element in the tree*/
void insertAVL(AVL * a, char * str);
/*Searches for an element in the tree*/
int searchAVL(AVL a, char * str);
/*writes the avl to a FILE/*/
int writeFile(AVL a, FILE *fp);
/*Gets rid of the tree*/
/*void destroyAVL(AVL * a);*/

#endif
