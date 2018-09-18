import java.util.Comparator;
import java.util.Stack;

public class MySort {
    public<T extends  Comparable<T>> void sort(T[] list){
        boolean swapped = true;
        for (int i = 1,len = list.length;i<len&&swapped;i++){
            swapped = false;
            for(int j = 0;j<len-1;j++){
                if(list[j].compareTo(list[j+1])>0){
                    T temp = list[j];
                    list[j]=list[j+1];
                    list[j+1]=temp;
                    swapped=true;
                }
            }
        }
    }
    public <T> void sort(T[] list,Comparator<T> comp){
        boolean swapped = true;
        for (int i = 1,len = list.length;i<len&&swapped;i++){
            swapped = false;
            for(int j = 0;j<len-1;j++){
                if(comp.compare(list[j],list[j+1])>0){
                    T temp = list[j];
                    list[j]=list[j+1];
                    list[j+1]=temp;
                    swapped=true;
                }
            }
        }
    }

    //直接插入排序
    public static void insertiontSort(int[] arr){
        for(int i = 1;i<arr.length;i++){
            int temp = arr[i];
            for(int j = i;j>0;j--){
                if(arr[j-1]>temp)
                    arr[j]=arr[j-1];
                else
                    arr[j]=temp;
            }
        }
    }

    //希尔排序
    public static void shellSort(int[] arr){
        int gap =1;
        int temp;
        while (gap<arr.length/3)
            gap= gap*3+1;
        while (gap>=1){
            for(int i = gap;i<arr.length;i++){
                for(int j = i;j>=gap&&arr[j]<arr[j-gap];j-=gap){
                    temp = arr[j];
                    arr[j]=arr[j-gap];
                    arr[j-gap]=temp;
                }
            }
            gap = gap/3;
        }

    }

    //选择排序
    public static void selectionSort(int[] arr){
        int min;
        for(int i = 0;i<arr.length-1;i++){
           min = i;
            for(int j =i;j<arr.length;j++){
                if(arr[j]<arr[min])
                    min = j;
            }
            int temp = arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }

    //堆排序
    private static void heapAjd(int[] arr,int m,int len){
        int left = 2*m +1;
        int right =2*m +2;
        int large = m;
        if(left<len&&arr[left]>arr[large])
            large = left;
        if(right<len&&arr[right]>arr[large])
            large=right;
        if(large!=m){
            swap(arr,m,large);
            heapAjd(arr,large,len);
        }
    }
    public static void heapSort(int[] arr){
        int i,temp;
        int len = arr.length-1;
        for(i = arr.length/2;i>=0;i--)
            heapAjd(arr,i,len);
        for(i = arr.length-1;i>=0;i--){
            swap(arr,0,i);
            heapAjd(arr,0,len--);
        }
    }

    private static void swap(int[] arr,int a,int b){
        int temp = arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

    //冒泡排序
    public static void bubbbleSort(int[] arr){
        for(int i = 0;i<arr.length-1;i++){
            for(int j = 0;j<arr.length-i-1;j++){
                if(arr[j]>arr[j+1])
                    swap(arr,j,j+1);
            }
        }
    }

    //快速排序
    public static void quickSort(int arr[]){
        qSort(arr,0,arr.length-1);
    }
    private static void qSort(int arr[],int left,int right){
        int pivot;
        if(left<right){
            pivot= partition(arr,left,right);
            qSort(arr,left,pivot-1);
            qSort(arr,pivot+1,right);
        }
    }
    private static int partition(int arr[],int left,int right){
        int key = arr[left];
        while(left<right){
            while(left<right&&arr[right]>=key)
                right--;
            swap(arr,left,right);
            while(left<right&&arr[left]<=key)
                left++;
            swap(arr,left,right);
        }
        return left;
    }
    //使用栈代替递归
    public static void quickSortByStack(int[] arr){
        if(arr.length <= 0) return;
        Stack<Integer> stack = new Stack<Integer>();

        stack.push(0);
        stack.push(arr.length-1);
        int low,high,pivot;
        while(!stack.isEmpty()){
            high = stack.pop();
            low = stack.pop();
            pivot = partition(arr,low,high);
            if(pivot>low){
                stack.push(low);
                stack.push(pivot-1);
            }
            if(pivot<high){
                stack.push(pivot+1);
                stack.push(high);
            }
        }
    }

    //归并排序
    public static void mergeSort(int arr[]){
        mSort(arr,0,arr.length-1);
    }
    private static void mSort(int arr[],int left,int right){
        if(left==right) return;
        int m = (left+right)/2;
        mSort(arr,left,m);
        mSort(arr,m+1,right);
        merge(arr,left,m,right);
    }
    private static void merge(int arr[],int left,int m,int right){
        int[] tr=new int[right-left+1];
        int i,j,k;
        for(k=0,i = left,j = m+1;i<=m&&j<=right;k++){
            if(arr[i]<=arr[j]){
                tr[k]=arr[i];
                i++;
            }
            else{
                tr[k]=arr[j];
                j++;
            }
        }
        while(i!=m+1){
            tr[k]=arr[i];
            i++;
            k++;
        }
        while(j!=right+1){
            tr[k]=arr[j];
            j++;
            k++;
        }
        for(i=0;i<=right-left;i++){
            arr[left+i]=tr[i];
        }
    }
    //基数排序
    //lsd
    public static void radixSort(int arr[]){
        int max = -1;
        for(int i = 0;i<arr.length;i++){
            if(max<arr[i])
                max = arr[i];
        }
        int maxDigit=1;
        while(max/10>0){
            maxDigit++;
            max/=10;
        }
        int[][] buckets = new int[10][arr.length];
        int base = 10;

        for(int i = 0;i<maxDigit;i++){
            int[] bktLen = new int[10];
            //分配
            for(int j = 0;j<arr.length;j++){
                int whickBucket = (arr[j]%base)/(base/10);
                buckets[whickBucket][bktLen[whickBucket]]=arr[j];
                bktLen[whickBucket]++;
            }
            //收集
            int k = 0;
            for(int b = 0;b<buckets.length;b++){
                for(int p=0;p<bktLen[b];p++){
                    arr[k++]=buckets[b][p];
                }
            }
            base*=10;
        }
    }
}
