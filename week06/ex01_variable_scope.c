#include <stdio.h>
#include <stdlib.h>

/* Global scope that is visible to all the functions */
int x = 3;

/* A function declaration tells the compiler about a function name and parameters */ 
void print_number(); // function declaration

int main()
{
        printf("x = %d\n", x); // global x
        int x = 5; // Local scope of 'main'
        {
                int x = 8; // Local scoope of '{ ... }'
                printf("x = %d\n", x);
        }
        printf("x = %d\n", x);
        print_number();
        exit(0);
}

/* a function that prints a number */
void print_number() // function definition
{
        printf("x = %d\n", x);
}
