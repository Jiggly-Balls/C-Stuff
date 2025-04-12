
/*
Notes-

All these functions work with the memory on the heap.

malloc(size)
    (Memory Allocation)
    malloc function takes in one argument which is the total size to be allocated in
    the memory. When called, it creates that much "size" of space in memory & assigns
    a garbage value to the memory. This function also returns a void pointer which
    allows us to cast the pointer to any other type.

calloc(items, size_of_each_item)
    (Clear Allocation)
    Similar to malloc, which creates space in memory, unlike malloc which gives us the
    memory pointer containing garbage value, calloc clears the memory in the heap and
    returns the pointer of that empty space in memory. Since calloc needs to manually
    clear up the memory before returning it, it is slower than malloc.

*/

#include <stdio.h>
#include <stdlib.h>


// Function declarations-
int average_by_malloc();
int average_by_calloc();


int main() {
    return average_by_malloc();
}

int average_by_malloc() {
    int* ptr_array;  // Creating an int pointer for our dynamically allocated memory
    int total;
    float sum = 0;

    printf("Enter the total number of elements you want to enter: ");
    scanf("%d", &total);

    ptr_array = (int* )malloc(total * sizeof(int)); // Casting the returned void pointer to int
    //             ^
    //             |
    //      This is optional as "ptr_array" is already an int pointer

    if (ptr_array == NULL) {
        printf("Error in allocating memory!");
        return 1;
    }
    
    for (int i = 0; i < total; ++i) {
        printf("\nEnter the %d number: ", i);
        scanf("%d", &ptr_array[i]);
    }

    for (int i = 0; i < total; ++i) {
        sum += ptr_array[i];
        printf("\nnum = %d | sum = %d", ptr_array[i], sum);
    }

    printf("\n%f", sum / total);
    free(ptr_array);  // Frees this memory from the heap

    return 0;
}

int average_by_calloc() {
    int* ptr_array;  // Creating an int pointer for our dynamically allocated memory
    int total;
    float sum = 0;

    printf("Enter the total number of elements you want to enter: ");
    scanf("%d", &total);

    ptr_array = (int* )calloc(total, sizeof(int)); // Casting the returned void pointer to int
    if (ptr_array == NULL) {
        printf("Error in allocating memory!");
        return 1;
    }
    
    for (int i = 0; i < total; ++i) {
        printf("\nEnter the %d number: ", i);
        scanf("%d", &ptr_array[i]);
    }

    for (int i = 0; i < total; ++i) {
        sum += ptr_array[i];
        printf("\nnum = %d | sum = %d", ptr_array[i], sum);
    }

    printf("\n%f", sum / total);
    free(ptr_array);  // Frees this memory from the heap

    return 0;
}