# -*- coding: utf-8 -*-
"""
Created on Sun Aug 19 13:51:13 2018

@author: 13548
"""

#Dynamic Programming practice

# 给定一段长度为n英寸的钢条和一个价格表pi(i=1,2,3,...n),求切割钢条方案，使得销售收益Rn最大
#注：如果长度为n英寸的钢条的价格pn足够大，最优解可能为完全不需要切割

#递归
def cut(p,n):
    if n==0:return 0
    q = -1
    for i in range(1,n+1):
        q =max(q,p[i-1]+cut(p,n-i))
    return q
#自顶而下 备忘录版本
def fastcut(p,n,r):
    try: return r[n]
    except KeyError:
        q = -1
        if n==0:
            q=0
        else:
            for i in range(1,n+1):
                q = max(q,p[i-1]+cut(p,n-i))
        r[n]=q
        return q
def cut1(p,n):
    r = {}
    return fastcut(p,n,r)

#自底而上
def cut2(p,n):
    r=[0]
    for i in range (1,n+1):
        q = -1
        for j in range(1,i+1):
            q = max(q,p[j-1]+r[i-j])
        r.append(q)
    return r[n]

p = [1,5,8,9]
print(cut2(p,4))