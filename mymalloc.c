#include <stdio.h>
#include <stddef.h>
#include "mymalloc.h"

char dynamicMem[MEMORY_SIZE];

metaData* firstBlock = (metaData*) dynamicMem;
void initialize(void){
    firstBlock->blockSize = MEMORY_SIZE - sizeof(metaData);
    firstBlock->isFree = TRUE;
    firstBlock->next = NULL;
}

void* MyMalloc(size_t size) {
    metaData* current = firstBlock;

    // Traverse the linked list to find a suitable block
    while (current != NULL) {
        if (size <= current->blockSize && current->isFree) {
            printf("Suitable memory block found.\n");

            if (size == current->blockSize) {
                current->isFree = FALSE;
                printf("Exact size block allocated.\n");
                return (void*)(current + 1);
            } else if (size < current->blockSize) {
                split(current,size);
                printf("Memory split and allocated successfully.\n");
                return (void*)(current + 1);
            }
        }
        current = current->next; // Move to the next block
    }

    printf("No suitable memory block found.\n");
    return NULL; // Allocation failed
}
// Create a new block and initialize current and new.
void split(metaData* currentBlock, size_t size) {
    metaData* newBlock = (metaData*)((char*)(currentBlock) + sizeof(metaData) + size);
    newBlock->blockSize = currentBlock->blockSize - size - sizeof(metaData);
    newBlock->isFree = TRUE;
    newBlock->next = currentBlock->next;

    currentBlock->blockSize = size;
    currentBlock->isFree = FALSE;
    currentBlock->next = newBlock;
}

void MyFree(void* ptr){
    if(ptr == NULL) {
        printf("Null Pointer Cannot Free\n");
        return;
    }

    ((metaData*)ptr - 1)->isFree = TRUE;
    merge();
    printf("Memory freed");

}
// traverse through the linked list and Merges adjacent free memory blocks
void merge(){
    metaData *temp = (metaData*)firstBlock;
    while(temp != NULL && temp->next != NULL){
        // Check if adjacent blocks are free
        if(temp->isFree == TRUE && temp->next->isFree == TRUE){
            temp->blockSize += temp->next->blockSize;
            temp->next = temp->next->next;
        } else {
            temp = temp->next;  // Move to the next block if no merge
        }
    }
}
