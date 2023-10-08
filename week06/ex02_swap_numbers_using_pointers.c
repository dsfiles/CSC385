/* Swap two numbers using C pointers*/
#include <stdio.h>

// function to swap the two numbers
void swap(float *x, float *y)
{
    float t;
     t  = *x;
    *x  = *y;
    *y  =  t;
}

float main()
{
    float n1,n2;

    printf("Enter value of n1: ");
    scanf("%f",&n1); // scanf takes in a number and store it at the address of variable
    printf("Enter value of n2: ");
    scanf("%f",&n2);

    // numbers before swapping ('%.1f' specifier prints one decimal point float number)
    printf("Before swapping: n1: %.1f, n2: %.1f\n", n1, n2);

    // call the function
    swap(&n1, &n2);

    // numbers after swapping
    printf(" After swapping: n1: %.1f, n2: %.1f\n",n1, n2);

    return 0;
}