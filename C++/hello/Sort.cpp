/**
 * status：待验证
 **/
void swap(int *L, int a, int b)
{
    L[a], L[b] = L[b], L[a];
}

//冒泡排序
void boobleSort(int *L, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (L[j] > L[j + 1])
                swap(L, j + 1, j);
        }
    }
}
//简单选择排序
void sampleSelectSort(int *L, int len)
{
    int minx = 0;
    for (int j = 0; j < len - 1; j++)
    {
        minx = j;
        for (int i = j + 1; i < len; i++)
        {
            if (L[i] < L[minx])
                minx = i;
        }
        swap(L, minx, j);
    }
}
//简单插入排序
void sampleInsertSort(int *L, int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i;
        while (L[j] < L(j - 1) && j > 0)
        {
            swap(L, j - 1, j);
            j--;
        }
    }
}

//希尔排序
void shellSort(int *L, int len)
{
    int incre = 1;
    while (intcre < len / 3)
    {
        incre = 3 * incre + 1;
    }
    while (incre >= 1)
    {

        //简单插入排序
        for (int i = incre; i < len; i++)
        {
            for (int j = i; L[j] < L[j - incre] && j > 0; j -= incre)
            {
                swap(L, j, j - incre);
            }
        }
        incre /= 3;
    }
}

//归并排序
//分治 Divide and Conque
void mSort(int *L, int left, int rigt)
{
    if (left >= right)
        return;
    int m = (left + right) / 2;
    mSort(L, left, m);
    mSort(L, m + 1, right);
    merge(L, left, m, right);
}
void merge(int *L, int left, int m, int right)
{
    int *tr;
    tr = (int *)malloc((right - left + 1) * sizeof(int));
    int i = 0, j = 0;
    k = 0;
    for (; i < m && j < right; k++)
    {
        if (L[i] <= L[j])
        {
            tr[k] = L[i];
            i++;
        }
        else
        {
            tr[k] = L[j];
            j++;
        }
    }
    while (i <= m)
    {
        tr[k] = L[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        tr[k] = L[j];
        k++;
        j++;
    }
    for (i = left; i <= right; i++)
    {
        L[i] = tr[i - left];
    }
}
void mergeSort(int *L, int len)
{
    mSort(L, 0, len - 1)
}

//快速排序
int partition(int *L, int left, int right)
{
    int key = L[left]; //暂取左边值为key
    while(left<right){
        while(left<right&&L[right]>=key){
            right--;
        }
        swap(L,left,right);
        while(left<right&&L[left]<=key){
            left++;
        }
        swap(L,left,right);
    }
    return left;
}
void qSort(int *L, int left, int right)
{
    if (left < right)
    {
        int pivot;
        pivot = partition(L,left,right);
        qSort(int *L, int left, int pivot - 1);
        qSort(int *L, int pivot + 1, int right);
    }
}
void quickSort(int *L, int len)
{
    qSort(L, 0, len - 1);
}

//堆排序
//生成大顶堆
void heapAdj(int*L,int m,int len){
//m为堆顶元素
int left = 2*m+1;
int right = left+1;
int large=m;
if(left<len&&L[left]>L[large])
large=left;
if(right<len&&L[right]>L[large])
large=right;
if(large!=m){
    swap(L,m,large);
    heapAdj(L,large,len);
}
}
void heapSort(int *L, int len)
{
    int i;
    //生成大顶堆
    for(i=len/2;i>=0;i--){
        heapAdj(L,i,len-1);
    }
    //每次将堆顶元素取出并重新构造
    for(i=len--;i>0;i--){
        swap(L,0,i);
        heapAdj(L,i,--len);
    }

}