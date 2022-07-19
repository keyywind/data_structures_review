#include <bits/stdc++.h>

void swap_char(char charList[], int s, int t)
{
    int temp = charList[s];
    charList[s] = charList[t];
    charList[t] = temp;
}

void permutation_recursive(char charList[], int i, int n)
{
    if (i == (n - 1))
    {
        for (int k = 0; k < n; ++k)
        {
            printf("%c", charList[k]);
        }
        printf("\n");
    }
    else
    {
        for (int k = i; k < n; ++k)
        {
            swap_char(charList, i, k);
            permutation_recursive(charList, i + 1, n);
            swap_char(charList, i, k);
        }
    }
}

int main()
{
    char charList[100] = { 'a', 'b', 'c', 'd' };
    int listSize = 4;
    permutation_recursive(charList, 0, listSize);

    return 0;
}
