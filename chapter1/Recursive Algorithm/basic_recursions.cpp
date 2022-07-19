#include <bits/stdc++.h>
#define TEST_CASE        2
#define TEST_FACTORIAL   1
#define TEST_EXPONENTIAL 2

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int exponential(int base, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return base * exponential(base, n - 1);
    }
}

int main()
{
    #if (TEST_CASE == TEST_FACTORIAL)
    int userInput;  printf("Factorial: ");  scanf("%d", &userInput);  printf("\n");
    printf("Factorial of %d = %d\n", userInput, factorial(userInput));
    #endif
    #if (TEST_CASE == TEST_EXPONENTIAL)
    int base, exponential;  printf("Base: ");  scanf("%d", &base);  printf("\n");  printf("Exponential: ");  scanf("%d", &exponential);  printf("\n");
    printf("%d to the power of %d = %d\n", base, exponential, ::exponential(base, exponential));
    #endif
    return 0;
}
