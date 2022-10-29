#include <bits/stdc++.h>
using namespace std;
class Sort
{
public:
    static constexpr int QUICK_SORT     = 0,
                         MERGE_SORT     = 1,
                         SHELL_SORT     = 2,
                         BUBBLE_SORT    = 3,
                         SELECTION_SORT = 4,
                         INSERTION_SORT = 5;
    class QuickSort
    {
    public:
        static void rec_quick_sort(int A[], int L, int R)
        {
            if (L < R)
            {
                int i = L + 1, j = R, anchor = A[L];
                while (i < j)
                {
                    for (; A[i] <= anchor && i <= R; ++i);
                    for (; A[j] >= anchor && j >  L; --j);
                    if (i >= j)
                        break;
                    swap(A[i], A[j]);
                }
                swap(A[L], A[j]);
                rec_quick_sort(A, L, j - 1);
                rec_quick_sort(A, j + 1, R);
            }
        }
        static void quick_sort(int A[], int n)
        {
            rec_quick_sort(A, 0, n - 1);
        }
    };
    class MergeSort
    {
    public:
        static void rec_merge_sort(int A[], int B[], int L, int R)
        {
            if (L < R)
            {
                int M = (L + R) / 2;
                rec_merge_sort(B, A, L, M);
                rec_merge_sort(B, A, M + 1, R);
                int i = L, j = M + 1, k = L;
                while (i <= M && j <= R)
                {
                    if (B[i] < B[j])
                    {
                        A[k++] = B[i++];
                    }
                    else
                    {
                        A[k++] = B[j++];
                    }
                }
                while (i <= M) A[k++] = B[i++];
                while (j <= R) A[k++] = B[j++];
            }
        }
        static void merge_sort(int A[], int n)
        {
            int * B = new int [n];
            memcpy(B, A, n * sizeof(int));
            rec_merge_sort(A, B, 0, n - 1);
            delete [] B;
        }
    };
    class InsertionSort
    {
    public:
        static void insertion_sort(int A[], int n)
        {
            int i, j, k, l;
            for (i = 1; i < n; ++i)
            {
                for (j = i - 1; j >= 0 && A[i] < A[j]; --j);
                k = A[i];
                for (l = i; l > j; --l)
                    A[l] = A[l - 1];
                A[j + 1] = k;
            }
        }
    };
    class ShellSort
    {
    public:
        static void shell_sort(int A[], int n)
        {
            int i, j, k = 1, span = 2;
            while (span > 1)
            {
                span = ceil((float) n / (1 << k++));
                for (i = 0; i < n - span; ++i)
                {
                    if (A[i] > A[i + span])
                    {
                        swap(A[i], A[i + span]);
                    }
                }
            }
        }
    };
    class SelectionSort
    {
    public:
        static void selection_sort(int A[], int n)
        {
            int i, j, m = n - 1;
            for (i = 0; i < m; ++i)
                for (j = i; j < n; ++j)
                    if (A[j] < A[i])
                        swap(A[i], A[j]);
        }
    };
    class BubbleSort
    {
    public:
        static void bubble_sort(int A[], int n)
        {
            int diff = 1, i;
            while (diff)
            {
                diff = 0;
                for (i = 1; i < n; ++i)
                {
                    if (A[i] < A[i - 1])
                    {
                        swap(A[i], A[i - 1]);
                        diff = 1;
                    }
                }
            }
        }
    };
    static void sort(int A[], int n, int sortAlg = QUICK_SORT)
    {
        switch (sortAlg)
        {
        case QUICK_SORT:
            QuickSort::quick_sort(A, n);
        case MERGE_SORT:
            MergeSort::merge_sort(A, n);
        case SHELL_SORT:
            ShellSort::shell_sort(A, n);
        case BUBBLE_SORT:
            BubbleSort::bubble_sort(A, n);
        case INSERTION_SORT:
            InsertionSort::insertion_sort(A, n);
        case SELECTION_SORT:
            SelectionSort::selection_sort(A, n);
        default:
            ;
        }
    }
};
int main()
{
    int A[] = { 10, 11, 15, 9, -1, 0, 4 }, n = sizeof(A) / sizeof(int);
    Sort::sort(A, n, Sort::SELECTION_SORT);
    for (int i = 0; i < n; ++i)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}
