#include <bits/stdc++.h>

int recursive_fibonacci(int n)
{
    if ((n == 0) || (n == 1))
    {
        return n;
    }
    else
    {
        return recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
    }
}

int iterative_fibonacci(int n)
{
    int table[1000] = { 0 };  table[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        table[i] = table[i - 2] + table[i - 1];
    }
    return table[n];
}

int main()
{

    int index;  scanf("%d", &index);
    printf("%d'th value of the Fibonacci sequence = %d\n", index, iterative_fibonacci(index));
    return 0;
}
