#include <bits/stdc++.h>

int binomial_recursive(int n, int m)
{
    if ((m == 0) or (n == m))
        return 1;
    return binomial_recursive(n - 1, m) + binomial_recursive(n - 1, m - 1);
}

int binomial_iterative(int n, int m)
{
    int nominator   = 1,
        denominator = 1,
        k           = std::max(m, n - m) + 1,
        l           = n - k + 1;
    for (int i = 1; i <= l; ++i)
        denominator *= i;
    for (int i = k; i <= n; ++i)
        nominator *= i;
    return nominator / denominator;
}

int main()
{
    int n, m;  printf("n: ");  scanf("%d", &n);  printf("\nm: ");  scanf("%d", &m);  printf("\n");
    printf("B(n, m) = B(%d, %d) = %d\n", n, m, binomial_iterative(n, m));
    return 0;
}
