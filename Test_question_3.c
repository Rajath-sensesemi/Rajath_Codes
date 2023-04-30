// By Rajath B T
/*Create a c program to solve the given problem:
Write a program to find points (x,y) in an array such that between no
two points there exists another
value 'z' in the array which falls between 'x' and 'y'. ie: the point z
should not be between x and y.
Print the value of the points (x,y) which have no values between them
and the distance between them.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    printf("The points with no values between them are:\n");
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int valid = 1;
            for (int k = i+1; k < j; k++) {
                if (arr[k] > arr[i] && arr[k] < arr[j]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                printf("(%d,%d) with distance %d\n", arr[i], arr[j], j-i);
                count++;
            }
        }
    }
    if (count == 0) {
        printf("No such points found in the array.\n");
    }

    free(arr);
    return 0;
}
