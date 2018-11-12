/**
 * 
 * 功能：求某一元素集合的全排列
 * 
 * tips: 递归
**/


#include <iostream>
#include"util.cpp"
using namespace std;
//#define Type int
//typedef int Type;
template <class Type>
void Perm(Type a[], int k, int n)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        for (int i = k; i < n; i++)
        {
            swap(a[k],a[i]);
            Perm(a, k + 1, n);
            swap(a[k],a[i]);      
        }
}
// int main()
// {
//     char a[] = {'a', 'b','c'};
//     Perm(a, 0, 3);
//     return 0;
// }