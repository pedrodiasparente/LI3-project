#include <stdlib.h>
#include "userData.h"

struct userData{
    void * data1;
    void * data2;
};

DATA data(void * data1, void * data2){
    DATA d;
    d = malloc(sizeof(DATA));

    d -> data1 = data1;
    d -> data2 = data2;

    return d;
}

void * getData1(DATA d){
    return (d -> data1);
}

void * getData2(DATA d){
    return (d -> data2);
}
