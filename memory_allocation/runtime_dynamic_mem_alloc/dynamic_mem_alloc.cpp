#include <stdio.h>
#include <stdlib.h>

int main()
{

    // int pointer to store the address of the runtime allocated memory
    int *ptr;

    int n, i;

    printf("Enter limit: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(ptr));

    if (ptr == NULL)
    {
        printf("Insufficient Memory!!!\n");
        return 0;
    }

    // Read n elements
    printf("Input %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (ptr + i));
    }

    // Print array elements
    printf("Input elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Release memory occupied by dynamically allocated array
    free(ptr);

    return 0;
}