#include "mymalloc.h"
#include <stdio.h>
#include "mymalloc.c"

int main(){
    initialize();

    // You can write some test cases to test this simulation and understand well
   
    /*
    // This is an example test case for demostration
    void* ptr1 = MyMalloc(100*sizeof(int));
    if(ptr1 != NULL){
        printf("Memory allocated at %p\n", ptr1);
    }

    MyFree(ptr1);
    */

    return 0;
}
