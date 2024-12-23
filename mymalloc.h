//
// Created by sendev on 23/12/2024.
//

#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>

#define MEMORY_SIZE 25000
#define TRUE 1
#define FALSE 0

typedef struct metaData {
    size_t blockSize;
    int isFree;                 // 1 : free memory , 0 : allocated memory
    struct metaData* next;
} metaData;

void split(metaData* currentBlock , size_t size);
void initialize(void);
void MyFree(void* ptr);
void* MyMalloc(size_t size);
void merge();

#endif
