#include <stdio.h>
#include <stdlib.h>


void allocate(int value) {
    int *ptr = NULL;
    ptr = malloc(1024*1024 * sizeof(int));
    if (ptr == NULL){
        perror("Error: ");
        exit(1);
    }
    *ptr = value;
    printf("test of allocated memory: %i\n", value);
}



int main(){
    int i;
    i=0;
    while(1){
        allocate(i);
        i++;
    }

    return 0;
}





