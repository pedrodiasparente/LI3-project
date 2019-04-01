#ifndef USERDATA_H
#define USERDATA_H

typedef struct userData *DATA;

DATA data(void* data1, void * data2);

void * getData1(DATA d);

void * getData2(DATA d);

#endif
