#include"Solution.h"

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

    //4.两个排序数组的中位数
    //log((m+n))

    //Stupid Mehtod
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l1 = nums1.size();
        int l2 = nums2.size();

        int i = 0, j = 0, left = (l1 + l2 + 1) / 2, right = (l1 + l2 + 2) / 2;

        int l, r;
        for (int m = 0; m < left; m++)
        {
            if (nums1[i] < nums2[j])
            {
                l = max(nums1[i], nums2[j]);
                i++;
            }
            else
            {
                l = max(nums1[i], nums2[j]);
                j++;
            }
        }

        for (int m = left; m < right; m++)
        {
            if (nums1[i] < nums2[j])
            {
                r = max(nums1[i], nums2[j]);
                i++;
            }
            else
            {
                r = max(nums1[i], nums2[j]);
                j++;
            }
        }
        r = max(nums1[i], nums2[j]);

        return (l + r) / 2.0;
    }
    //二分法递归
    //log (m+n)
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findK(nums1, 0, nums2, 0, left) + findK(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findK(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (i >= nums1.size())
            return nums2[j + k - 1];
        if (j >= nums2.size())
            return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int midVal1, midVal2;
        midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2)
        {
            return findK(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        else
            return findK(nums1, i, nums2, j + k / 2, k - k / 2);
    }


    //5. 最长回文子串
    //暴力法 n**3
    bool isPalidrome(string s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    string longestPalindrome(string s){
        int maxij=0,fromi =0;
        for(int i =0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalidrome(s,i,j)&&maxij<j-i+1){
                    maxij=j-i+1;
                    fromi=i;
                }
            }
        }
        return s.substr(fromi,maxij);
    }
    //动态规划
    string longestPalindrome2(string s){
        if(s.empty()) return "";
        int left=0,right=0,len=0;
        int dp[s.length()][s.length()]={0};
        for(int i = 0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(i==j)
                dp[i][j]=1;
                if(j-i==1)
                dp[i][j]=(s[i]==s[j]);
                if(j-i>1)
                dp[i][j]=max(dp[i+1][j-1],dp[i+1][j-1]+(s[i]==s[j]));
            }
            
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout<<dp[i][j]+",";
            }
            cout<<endl;
        }
        return "3333333";
    }

    //马拉车算法
    string longestPalindrome3(string s){
        return "2222";
    }
};