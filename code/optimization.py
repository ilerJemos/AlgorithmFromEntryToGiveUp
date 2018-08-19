#斐波那契数列
#一般递归与dynamic programming/memorize


#2**n
def fib(n):
   # print(n)
    if n<=1:return 1
    else: return fib(n-1)+fib(n-2)
#n
#自顶而下
def fastfib(n,memo):
    if not n in memo:
        memo[n] = fastfib(n-1,memo)+fastfib(n-2,memo)
    return memo[n]
def fib1(n):
    memo = {0:1,1:1}
    return fastfib(n,memo)
#自底而上
def fib2(n):
    if n<= 1:
        return 1
    memo =[1,1]
    for i in range(2,n+1):
        temp=memo[i-1]+memo[i-2]
        memo.append(temp)
    return memo[n]
#压缩空间
def fib22(n):
    if n<= 1:
        return 1
    memo_0=memo_1 = 1
    for i in range(2,n+1):
        memo = memo_0+memo_1
        memo_1 = memo_0
        memo_0 = memo
    return memo
