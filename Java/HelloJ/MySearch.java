import java.util.Comparator;

public class MySearch {
    //循环实现二分查找
    public static <T> int binarySearch(T[] x, T key, Comparator<T> comp){
        int low = 0;
        int high = x.length-1;
        while(low<=high){
            int mid = (low+high)>>1;
            int cmp = comp.compare(x[mid],key);
            if(cmp<0)
                low = mid+1;
            else if(cmp>0)
                high = mid -1;
            else
                return mid;
        }
        return -1;
    }

    //递归实现二分查找
    public static <T extends Comparable> int bSearch(T[] x,int low,int high,T key){
        if(low<=high){
            int mid = low+(high-low)>>1;
            if(key.compareTo(x[mid])==0)
                return mid;
            else if(key.compareTo(x[mid])<0)
                return bSearch(x,low,mid-1,key);
            else
                return bSearch(x,mid+1,high,key);
        }
        return -1;
    }

}
