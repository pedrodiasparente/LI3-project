#define ESQ -1
#define BAL 0
#define DIR 1

typedef struct avl {
    int bal;
    char * cont;
    AVL * dir;
    AVL * esq;
} AVL;

int insertAVL(AVL * a, char * str){
    if(a == NULL){
        a -> bal = BAL;
        a -> cont = str;
        a -> dir = a -> esq = NULL;
        return 1;
    }
    if(strcmp(a -> cont, cont) > 0){

    }
}

int searchAVL(AVL * a, char * str){

}

int removeAVL(ALV * a, char * str){
    
}
