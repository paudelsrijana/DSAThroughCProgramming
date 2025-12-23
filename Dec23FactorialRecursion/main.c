#include <stdio.h>
// Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0) // Base case
        return 1;
    else // Recursive case
        return n * factorial(n - 1);
}
int main()
{
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of %d = %d\n", num, factorial(num));
    }
    return 0;
}
