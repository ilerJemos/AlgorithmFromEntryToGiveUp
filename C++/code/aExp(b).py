#n
def exp1(a,b):
    ans = 1
    while(b):
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

#矩阵快速幂
#logn
def fib_matrix_multiply(a,b):
    temp = [[0,0],[0,0]]
    for i in range (len(a)):
        for j in range(len(b)):
            for k in range(len(temp)):
                temp[i][j]+=a[i][k]*b[k][j]
    return temp
def fib_matrix_fib(n):
    n=n-1
    base = [[1,1],[1,0]]
    res =[[1,1],[1,0]]
    surplus = [[1,0],[0,0]]
    while n!=0:
        if n&1:
            res = fib_matrix_multiply(base,res)
        base = fib_matrix_multiply(base,base)
        print("n:",n,"res: ",res,"base:",base)
        n>>=1
    res = fib_matrix_multiply(surplus,res)
    return res[0][0]
