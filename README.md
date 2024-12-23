# Dynamic-Memory-Allocation-simulation-in-C
This project implements custom memory allocation (MyMalloc) and deallocation (MyFree) functions in C. It simulates how memory is managed, similar to the way modern operating systems handle dynamic memory allocation, using a statically allocated memory pool. The goal of this project is to understand how memory management works at a low level, including block splitting, merging, and efficient use of available memory.

# Features
Custom Memory Allocation (MyMalloc): Allocates memory from a statically defined memory pool.
Block Splitting: When a block of memory larger than the requested size is found, it is split into two blocks: one allocated and one free.
Memory Deallocation (MyFree): Frees memory by marking the corresponding block as free and calls a merge function to consolidate adjacent free blocks.
Memory Merging: Merges adjacent free blocks into larger blocks to prevent fragmentation and improve memory utilization.
Simple Linked List Management: The memory pool is managed using a linked list of blocks, allowing efficient traversal and memory allocation.

# How It Works
Initialization (initialize):

The program initializes the first block of the memory pool as free, and assigns it the full size of the pool (excluding the size of metadata).
Memory Allocation (MyMalloc):

MyMalloc searches for a free block that can accommodate the requested memory size.
If a suitable block is found, it is either:
Allocated if it exactly matches the required size.
Split if it is larger than needed, creating a new free block for the remaining space.
Memory Deallocation (MyFree):

When a pointer is passed to MyFree, the corresponding block is marked as free.
After freeing the block, merge() is called to merge adjacent free blocks, reducing fragmentation.
Memory Merging (merge):

After deallocation, the program checks for adjacent free blocks and merges them into a larger block. This ensures the efficient use of available memory..

# Code Structure
dynamicMem: A statically allocated array that serves as the memory pool.
metaData: A structure that holds metadata for each memory block, including:
blockSize: The size of the block.
isFree: A flag indicating whether the block is free or allocated.
next: A pointer to the next block in the linked list.
MyMalloc(size_t size): Allocates memory from the pool.
MyFree(void* ptr): Frees the allocated memory.
split(metaData* currentBlock, size_t size): Splits a block if it is larger than the requested size.
merge(): Merges adjacent free blocks to prevent fragmentation.

# Example Usage
int main() {
    
    initialize();
    
    void* ptr1 = MyMalloc(100 * sizeof(int)); // Allocating memory for 100 integers
    if (ptr1 != NULL) {
        printf("Memory allocated at %p\n", ptr1);
    }

    MyFree(ptr1); // Freeing the allocated memory
    printf("Memory freed at %p\n", ptr1);
    
    return 0;
}

# Requirements
A C compiler (e.g., GCC) to build and run the code.

# Learning Outcomes
Gain a deep understanding of low-level memory management in C.
Learn how to implement custom malloc and free functions using linked lists.
Understand the challenges of memory fragmentation and how block splitting and merging can help mitigate it.
