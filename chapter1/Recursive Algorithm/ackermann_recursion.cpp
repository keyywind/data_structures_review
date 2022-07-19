#include <bits/stdc++.h>

int ackermann_recursive(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return ackermann_recursive(m - 1, 1);
    }
    else
    {
        return ackermann_recursive(m - 1, ackermann_recursive(m, n - 1));
    }
}

int main()
{
    int m, n;  printf("m: ");  scanf("%d", &m);  printf("\n");  printf("n: ");  scanf("%d", &n);  printf("\n");
    printf("A(m, n) = A(%d, %d) = %d\n", m, n, ackermann_recursive(m, n));

    printf("A(2, 2) = %d\n", ackermann_recursive(2, 2));
    printf("A(2, 1) = %d\n", ackermann_recursive(2, 1));
    printf("A(1, 2) = %d\n", ackermann_recursive(1, 2));

    return 0;
}
