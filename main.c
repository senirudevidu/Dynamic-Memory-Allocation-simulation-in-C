#include "mymalloc.h"
#include <stdio.h>
#include "mymalloc.c"

int main(){
    initialize();
    void* ptr1 = MyMalloc(100*sizeof(int));
    if(ptr1 != NULL){
        printf("Memory allocated at %p\n", ptr1);
    }
    void* ptr2 = MyMalloc(200*sizeof(char));
    if(ptr2 != NULL){
        printf("Memory allocated at %p\n", ptr2);
    }
    void* ptr3 = MyMalloc(300*sizeof(float));
    if(ptr3 != NULL){
        printf("Memory allocated at %p\n", ptr3);
    }

    MyFree(ptr1);
    MyFree(ptr2);
    MyFree(ptr3);

    return 0;
}