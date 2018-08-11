#n
def exp1(a,b):
    ans = 1
    while(b>0):
        ans *=a
        b-=1
    return ans

#n
def exp2(a,b):
    if b==1:return a
    else: return a*exp2(a,b-1)

#递归
#logn
def exp3(a,b):
    if b==1:return a
    elif b%2*2==b: return exp3(a*a,b/2)#b 为偶数
    else:return a*exp3(a,b-1)

#快速幂
#logn
def exp4(a,b):
    ans = 1
    base = a
    while b!=0:
        if b&1: ans*=base
        base *=base
        b>>=1
    return ans
