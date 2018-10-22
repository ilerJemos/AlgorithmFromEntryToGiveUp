
//Whose who cannot remember the past are condemed to repeat it
//talk is cheap show me the code
#include "DynamicProgram.h"

using namespace std;
//Fib
//递归
int fib1(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fib1(n - 1) + fib1(n - 2);
}

//动态规划
//自顶而下
//备忘录
static int fibonacii(int n, int mem[])
{
    if (mem[n] != -1)
        return mem[n];
    if (n <= 2)
        mem[n] = 1;
    else
        mem[n] = mem[n - 1] + mem[n - 2];

    return mem[n];
}
int fib2(int n)
{
    if (n <= 0)
        return n;
    int mem[n];

    for (int i = 0; i < n; i++)
        mem[i] = -1;
    return fibonacii(n, mem);
}

//自低而上
int fib3(int n)
{
    if (n <= 0)
        return 0;
    int mem[n];
    mem[0] = 0;
    mem[1] = 1;
    for (int i = 2; i < n; i++)
    {
        mem[i] = mem[i - 1] + mem[i - 2];
    }

    return mem[n];
}
//优化
int fib4(int n)
{
    if (n <= 1)
        return n;
    int mem0 = 0;
    int mem1 = 1;
    int memi = 0;
    for (int i = 2; i < n; i++)
    {
        memi = mem0 + mem1;
        mem0 = mem1;
        mem1 = memi;
    }
    return memi;
}

//钢条切割
/**
 * p:价格表
 * n:钢条长度
*/
//递归
int cut1(int *p, int n)
{
    if (n <= 0)
        return n;
    int q = -1;
    for (int i = 1; i <= n; i++)
        q = max(q, p[i - 1] + cut1(p, n - i));
    return q;
}
// 1,5,8,9,10,17,17,20,24,30
int cut2(int *p, int n)
{
    int *s = new int[n + 1];
    for (int i = 0; i <= n; i++)
        s[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            s[i] = max(s[i], s[i - j] + p[j - 1]);
    }

    return s[n];
}

//线性模型
//过河问题
/*
n:要过河人数
T(i):第i 人过河耗时
每次允许不大于2人通过
贪心算法不适用
*/
//1,2,5,10c
int crossRiver(int n, int *T)
{
    if (n == 1)
        return T[0];
    if (n == 2)
        return max(T[0], T[1]);
    int *tot = new int[n];
    tot[0] = T[0];
    tot[1] = max(T[0], T[1]);
    for (int i = 2; i < n; i++)
    {
        tot[i] = min(tot[i - 1] + T[0] + T[i], tot[i - 2] + T[0] + T[i] + 2 * T[1]);
    }
    return tot[n - 1];
}
//区间模型
//给定一个长度为n（n <= 1000）的字符串A，求插入最少多少个字符使得它变成一个回文串
inline int dfs(string s, int d[][5], int i, int j)
{
    if (d[i][j]!=0)
        return d[i][j];
    if (i == j)
        return d[i][j] = 0;
    if (s[i] == s[j] && i + 1 == j)
        return d[i][j] = 0;
    if (s[i] == s[j])
        return d[i][j] = dfs(s, d, i + 1, j - 1);
    d[i][j] = min(dfs(s, d, i + 1, j), dfs(s, d, i, j - 1)) + 1;
    return d[i][j];
}
int palindromeCreate(string s)
{
    int n = s.length() - 1;
    int d[n][5]={0};
    n=dfs(s, d, 0, n);
    return n;
}
//背包模型
//最长单调序列
//最大M字段和
//线性模型

//LIS longest increasing sussequence
//n**2
int LIS(int *L, int n)
{
    int *d = new int[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (L[j] <= L[i] && d[j] + 1 > d[i])
                d[i] = d[j] + 1;
        }
    }
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        len = max(len, d[i]);
    }
    return len;
}
//nlogn
