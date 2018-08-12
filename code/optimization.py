#斐波那契数列
#一般递归与dynamic programming/memorize


#2**n
def fib(n):
   # print(n)
    if n<=1:return 1
    else: return fib(n-1)+fib(n-2)
#n
def fastfib(n,memo):
    if not n in memo:
        memo[n] = fastfib(n-1,memo)+fastfib(n-2,memo)
    return memo[n]
def fib1(n):
    memo = {0:1,1:1}
    return fastfib(n,memo)
