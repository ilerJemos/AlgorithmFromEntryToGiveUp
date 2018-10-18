
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
  private:
  public:
    //连续子数组和
    //Continus Subarray Sum
    //方法1 累加和数组
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                    return true;
                if (k != 0 && sum % k == 0)
                    return true;
            }
        }
        return false;
    }
    //方法2 set 如果 a,b分别除以c 得到的余数相同，则a-b一定能够整除c
    bool checkSubarraySum2(vector<int> &nums, int k)
    {
        set<int> s;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int las;
            if (k == 0)
                las = nums[i];
            else
                las = nums[i] % k;
            if (s.count(las))
                return true;
            s.insert(pre);
            //pre代表之前的累加和，因为题目要求至少为两个数
            pre = las;
        }
        return false;
    }

    //方法3 使用haspMap
    bool checkSubarraySum3(vector<int> &nums, int k)
    {
        map<int, int> m{{0, 1}};
        for (int i = 0; i < nums.size(); i++)
        {
            int las = (k == 0) ? nums[i] : (nums[i] % k);
            if (m.count(las))
            {
                if (i - m[las] > 1)
                    return true;
            }
            else
                m[las] = i;
        }
        return false;
    }

    //两个排序数组的中位数
    //log((m+n))
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l1 = nums1.size();
        int l2 = nums2.size();

        int i = 0, j = 0, k = (l1 + l2) / 2;
        double mid=-0;

        for (int m = 0; m < k; m++)
        {
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        if ((l1 + l2) % 2 != 0)
        {
            return max(nums1[i], nums2[j]);
        }
        else
        {
            if (nums1[i] < nums2[j])
            {
                mid = nums2[j];
                j++;
            }
            else
            {
                mid = nums2[i];
                i++;
            }
            mid += max(nums1[i], nums2[j]);
            return mid/2.0;
        }

        return 0.0;
    }
    //方法2
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        return 0.0;
    }
};