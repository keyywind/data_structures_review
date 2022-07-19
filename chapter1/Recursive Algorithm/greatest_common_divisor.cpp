#include <bits/stdc++.h>

int GCD_recursive(int a, int b)
{
    int remainder = a % b;
    if (remainder == 0)
        return b;
    return GCD_recursive(b, remainder);
}

int GCD_iterative(int a, int b)
{
    while ((a != 0) && (b != 0))
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return ((a != 0) ? (a) : (b));
}

int main()
{

    int a, b;  printf("a: ");  scanf("%d", &a);  printf("\nb: ");  scanf("%d", &b);  printf("\n");
    printf("GCD(a, b) = GCD(%d, %d) = %d\n", a, b, GCD_iterative(a, b));
    return 0;
}
