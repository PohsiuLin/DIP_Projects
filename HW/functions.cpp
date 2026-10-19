#include "items.h"

void QuickSort(int *A, int left, int right)
{
    int i, j, s, Temp;
    if (left < right)
    {
        s = A[(left + right) >> 1];
        i = left - 1;
        j = right + 1;
        while (1)
        {
            while (A[++i] < s)
                ; // 向右找
            while (A[--j] > s)
                ; // 向左找
            if (i >= j)
                break;
            Temp = A[i];
            A[i] = A[j];
            A[j] = Temp;
        }
        QuickSort(A, left, i - 1);  // 對左邊進行遞迴
        QuickSort(A, j + 1, right); // 對右邊進行遞迴
    }
}

int my_random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

double my_generate_gausson(double x)
{
    return (1.0 / (sqrt(6.28318530718) * 3)) * exp(-x * x / 18.0); // p(x)=1/sqrt(2*pi)*sigma*exp(-pow(x-mean)/2*pow(sigma))
}