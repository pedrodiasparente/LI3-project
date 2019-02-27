typedef struct avl {
    int bal;
    char * cont;
    struct avl * dir;
    struct avl * esq;
} *AVL;

//API
//Returns a new NULL AVL
//AVL newAVL();
//Prints AVL
void printAVL(AVL a);
//Inserts a new element in the tree
void insertAVL(AVL * a, char * str);
//Searches for an element in the tree
int searchAVL(AVL a, char * str);
//Gets rid of the tree
//void destroyAVL(AVL * a);
