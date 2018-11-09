#include "mySort.h"
#include "util.cpp"

void bubbleSort(int *l, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (l[j] > l[j + 1])
                mySwap(l[j + 1], l[j]);
        }
    }
}
void sampleSelectSort(int *l, int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (l[j] < l[k])
                k = j;
        }
        mySwap(l[i], l[k]);
    }
}
void sampleInsertSort(int *l, int n)
{

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (l[i] < l[j])
                mySwap(l[i], l[j]);
        }
    }
}

void shellSort(int *l, int n)
{
    int incre = 1;
    while (incre < n / 3)
    {
        incre = incre * 3 + 1;
    }
    while (incre)
    {
        for (int i = incre; i < n; i += incre)
        {
            for (int j = i - incre; j >= 0; j--)
            {
                if (l[i] < l[j])
                    mySwap(l[i], l[j]);
            }
        }
        incre /= 3;
    }
}
void mergeSort(int *, int) {}
void merge(int *, int, int, int) {}
void quickSort(int *, int) {}
void heapSort(int *, int) {}

#include <iostream>
using namespace std;
void printL(int *, int);
int main()
{
    int L[] = {4, 2, 4, 6, 2, 6, 7, 20, 9, 12};
    int len = sizeof(L) / sizeof(L[0]);
    shellSort(L, len);
    printL(L, len);
    return 0;
}
void printL(int *L, int len)
{
    for (int i = 0; i < len; i++)
        cout << L[i] << ",";
    cout << endl;
}