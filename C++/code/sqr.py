# -*- coding: utf-8 -*-
#二分法 NR 法 就一定精确度的平方根

def sqr_Bi(x,epsilon):
    """return y y**2 is whithin the epsilon of x"""
    assert epsilon>0,'epsilon must be positive'
    low= 0;
    high = max(x,1)#when 0<x<1,high = 1
    guess = (low + high)/2.0# must be a float
    ctr = 1#count times
    while abs(guess**2-x)>epsilon and ctr<=100:
        if guess**2 <x: low = guess
        else:high = guess
        guess = (low + high)/2.0
        ctr+=1
    assert ctr <= 100,'iteration count exceeded'
    print('Bi method: iteration:',ctr,' Guess:',guess)
    return guess

def sqr_NR(x,epsilon):
    guess = 0.01#assum first guess = 0.01
    diff = guess**2 -x
    ctr = 1
    while(abs(diff)>epsilon and ctr<=100):
        guess = guess - diff/(2.0*guess)
        diff = guess**2 - x
        ctr+= 1
    print('NR method: iteration:',ctr,'Guess:',guess)
    return guess
