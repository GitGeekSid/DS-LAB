#include <stdio.h>

int linearSearch(int array[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;  
       }
    }
    return -1; 
}

int main() {
    int n, key;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int array[n];
    
    
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    
    int result = linearSearch(array, n, key);
    
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    
    return 0;
}
