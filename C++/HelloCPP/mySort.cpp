#include "mySort.h"
#include "util.cpp"

//下一步
//将全部转化为模板方法

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
        for (int j = i - 1; (j >= 0) && (l[i] < l[j]); j--)
        {
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
            for (int j = i - incre; (j >= 0) && (l[i] < l[j]); j -= incre)
            {
                mySwap(l[i], l[j]);
            }
        }
        incre /= 3;
    }
}

void merge(int *l, int left, int mid, int right)
{
    int st[right - left];
    int i = left, j = mid, k = 0;
    for (i, j, k; (i < mid) && (j < right); k++)
    {
        if (l[i] <= l[j])
        {
            st[k] = l[i];
            i++;
        }
        else
        {
            st[k] = l[j];
            j++;
        }
    }
    while (i < mid)
    {
        st[k++] = l[i++];
    }
    while (j < right)
    {
        st[k++] = l[j++];
    }
    for (k = left; k < right - left; k++)
        l[k] = st[k];
}
void Msort(int *l, int left, int right)
{
    if (right - left <= 1)
        return;
    int mid = (left + right) / 2;
    Msort(l, left, mid);
    Msort(l, mid, right);
    merge(l, left, mid, right);
}
void mergeSort(int *l, int n)
{
    Msort(l, 0, n);
}

int partition(int *l, int left, int right)
{
    int key = l[left];
    while (right - left > 1)
    {
        while ((right - left > 1) && (l[right - 1]) >= key)
            right--;
        mySwap(l[left], l[right - 1]);
        while ((right - left > 1) && (l[left] < key))
            left++;
        mySwap(l[right - 1], l[left]);
    }
    return left;
}
void Qsort(int *l, int left, int right)
{
    if (right - left > 1)
    {
        int pivot = partition(l, left, right);
        Qsort(l, left, pivot);
        Qsort(l, pivot + 1, right);
    }
}
void quickSort(int *l, int n)
{
    Qsort(l, 0, n);
}

//将 m 到 n 构造为大顶堆
void heapAdjust(int *l, int m, int n)
{
    int left = 2 * m + 1;
    int right = 2 * m + 2;
    int large = m;
    if (left < n && l[left] > l[large])
        large = left;
    if (right < n && l[right] > l[large])
        large = right;
    if (large != m)
    {
        mySwap(l[m], l[large]);
        heapAdjust(l, large, n);
    }
}
void heapAdj(int *l, int m, int n)
{
    int large = m;
    for (int i = 2 * m; i < n; i *= 2)
    {
        if (i < n && l[i] < l[i + 1])
            i++;
        if (l[i] <= l[large])
            break;
        mySwap(l[large], l[i]);
        large = i;
    }
}
void heapSort(int *l, int n)
{
    //构造大顶堆
    int i;
    for (i = n / 2; i >= 0; i--)
    {
        heapAdj(l, i, n);
    }
    //将最上面的取出，重新构造小顶堆
    for (i = n - 1; i > 0; i--)
    {
        mySwap(l[0], l[i]);
        heapAdj(l, 0, i - 1);
    }
}

//test
// #include <iostream>
// using namespace std;
// void printL(int *, int);
// int main()
// {
//     int L[] = {4, 2, 4, 6, 2, 6, 7, 20, 9, 12};
//     int len = sizeof(L) / sizeof(L[0]);
//     heapSort(L, len);
//     printL(L, len);
//     return 0;
// }
// void printL(int *L, int len)
// {
//     for (int i = 0; i < len; i++)
//         cout << L[i] << ",";
//     cout << endl;
// }